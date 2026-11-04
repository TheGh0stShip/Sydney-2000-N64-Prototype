/* Custom compact-audio effects runtime preserved by the upstream libmus source. */
#include "n_synth_types.h"

extern N_ALSynth *D_803AD9E0;
extern struct {
    ALDelay *delay;
    s16 *base;
    ALResampler *rs;
    void *rs_state;
    ALLowPass *lp;
    void *lp_state;
} D_803AD9F0;
extern s32 alFxParamHdl();
extern void init_lpfilter(ALLowPass *lp);

void func_800FEB80(s32 *param);
s32 func_800FEE78(void);
s32 func_800FEEBC(void);

void func_800FEA38(ALFx **fx_ar, ALSynConfig *c, ALHeap *hp)
{
    ALFx *r;

    *fx_ar = r = alHeapAlloc(hp, 1, sizeof(ALFx));
    r->paramHdl = alFxParamHdl;
    D_803AD9F0.delay = alHeapAlloc(hp, func_800FEE78(), sizeof(ALDelay));
    D_803AD9F0.base = alHeapAlloc(hp, func_800FEEBC(), sizeof(s16));
    D_803AD9F0.rs = alHeapAlloc(hp, 1, sizeof(ALResampler));
    D_803AD9F0.rs_state = alHeapAlloc(hp, 1, 0x20);
    D_803AD9F0.lp = alHeapAlloc(hp, 1, sizeof(ALLowPass));
    D_803AD9F0.lp_state = alHeapAlloc(hp, 1, 8);
    func_800FEB80(c->params);
}

#define RANGE 2.0
#define CONVERT 173123.404906676
#define LENGTH (d->output - d->input)

void func_800FEB80(s32 *param)
{
    u16 i, j;
    ALFx *r = D_803AD9E0->auxBus->fx_array[0];
    ALDelay *d;

    j = 0;
    r->section_count = param[j++];
    r->length = param[j++];
    r->delay = D_803AD9F0.delay;
    r->base = D_803AD9F0.base;
    r->input = r->base;

    for (i = 0; i < r->length; i++)
        r->base[i] = 0;

    for (i = 0; i < r->section_count; i++) {
        d = &r->delay[i];
        d->input = param[j++];
        d->output = param[j++];
        d->fbcoef = param[j++];
        d->ffcoef = param[j++];
        d->gain = param[j++];

        if (param[j]) {
            d->rsinc = ((((f32)param[j++]) / 1000) * RANGE) / D_803AD9E0->outputRate;
            d->rsgain = (((f32)param[j++]) / CONVERT) * LENGTH;
            d->rsval = 1.0;
            d->rsdelta = 0.0;
            d->rs = D_803AD9F0.rs;
            d->rs->state = D_803AD9F0.rs_state;
            d->rs->delta = 0.0;
            d->rs->first = 1;
        } else {
            d->rs = 0;
            j++;
            j++;
        }

        if (param[j]) {
            d->lp = D_803AD9F0.lp;
            d->lp->fstate = D_803AD9F0.lp_state;
            d->lp->fc = param[j++];
            init_lpfilter(d->lp);
        } else {
            d->lp = 0;
            j++;
        }
    }
}
