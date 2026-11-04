#include <libaudio.h>
#include "synthInternals.h"

#define SCALE 16384
#define ms *(((s32)((f32)44.1)) & ~0x7)

static s32 SMALLROOM_PARAMS[26] = {
    3, 100 ms,
    0, 54 ms, 9830, -9830, 0, 0, 0, 0,
    19 ms, 38 ms, 3276, -3276, 0x3fff, 0, 0, 0,
    0, 60 ms, 5000, 0, 0, 0, 0, 0x5000
};

static s32 BIGROOM_PARAMS[34] = {
    4, 100 ms,
    0, 66 ms, 9830, -9830, 0, 0, 0, 0,
    22 ms, 54 ms, 3276, -3276, 0x3fff, 0, 0, 0,
    66 ms, 91 ms, 3276, -3276, 0x3fff, 0, 0, 0,
    0, 94 ms, 8000, 0, 0, 0, 0, 0x5000
};

static s32 ECHO_PARAMS[10] = {
    1, 200 ms,
    0, 179 ms, 12000, 0, 0x7fff, 0, 0, 0
};

static s32 CHORUS_PARAMS[10] = {
    1, 20 ms,
    0, 5 ms, 0x4000, 0, 0x7fff, 7600, 700, 0
};

static s32 FLANGE_PARAMS[10] = {
    1, 20 ms,
    0, 5 ms, 0, 0x5fff, 0x7fff, 380, 500, 0
};

static s32 NULL_PARAMS[10] = {
    0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

void _init_lpfilter(ALLowPass* lp) {
    s32 i;
    s32 temp;
    s16 fc;
    f64 ffc;
    f64 fcoef;

    temp = lp->fc * SCALE;
    fc = temp >> 15;
    lp->fgain = SCALE - fc;

    lp->first = 1;
    for (i = 0; i < 8; i++) {
        lp->fcvec.fccoef[i] = 0;
    }

    lp->fcvec.fccoef[i++] = fc;
    fcoef = ffc = (f64)fc / SCALE;

    for (; i < 16; i++) {
        fcoef *= ffc;
        lp->fcvec.fccoef[i] = (s16)(fcoef * SCALE);
    }
}

void alFxNew(ALFx* r, ALSynConfig* c, ALHeap* hp) {
    u16 i;
    u16 j;
    u16 k;
    s32* param = 0;
    ALFilter* f = (ALFilter*)r;
    ALDelay* d;

    alFilterNew(f, 0, alFxParam, AL_FX);
    f->handler = alFxPull;
    r->paramHdl = (ALSetFXParam)alFxParamHdl;

    switch (c->fxType) {
        case AL_FX_SMALLROOM:
            param = SMALLROOM_PARAMS;
            break;
        case AL_FX_BIGROOM:
            param = BIGROOM_PARAMS;
            break;
        case AL_FX_ECHO:
            param = ECHO_PARAMS;
            break;
        case AL_FX_CHORUS:
            param = CHORUS_PARAMS;
            break;
        case AL_FX_FLANGE:
            param = FLANGE_PARAMS;
            break;
        case AL_FX_CUSTOM:
            param = c->params;
            break;
        default:
            param = NULL_PARAMS;
            break;
    }

    j = 0;
    r->section_count = param[j++];
    r->length = param[j++];

    r->delay = alHeapAlloc(hp, r->section_count, sizeof(ALDelay));
    r->base = alHeapAlloc(hp, r->length, sizeof(s16));
    r->input = r->base;

    for (k = 0; k < r->length; k++) {
        r->base[k] = 0;
    }

    for (i = 0; i < r->section_count; i++) {
        d = &r->delay[i];
        d->input = param[j++];
        d->output = param[j++];
        d->fbcoef = param[j++];
        d->ffcoef = param[j++];
        d->gain = param[j++];

        if (param[j]) {
#define RANGE 2.0
            d->rsinc = ((((f32)param[j++]) / 1000) * RANGE) / c->outputRate;
#define CONVERT 173123.404906676
#define LENGTH (d->output - d->input)
            d->rsgain = (((f32)param[j++]) / CONVERT) * LENGTH;
            d->rsval = 1.0;
            d->rsdelta = 0.0;
            d->rs = alHeapAlloc(hp, 1, sizeof(ALResampler));
            d->rs->state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
            d->rs->delta = 0.0;
            d->rs->first = 1;
        } else {
            d->rs = 0;
            j++;
            j++;
        }

        if (param[j]) {
            d->lp = alHeapAlloc(hp, 1, sizeof(ALLowPass));
            d->lp->fstate = alHeapAlloc(hp, 1, sizeof(POLEF_STATE));
            d->lp->fc = param[j++];
            _init_lpfilter(d->lp);
        } else {
            d->lp = 0;
            j++;
        }
    }
}
