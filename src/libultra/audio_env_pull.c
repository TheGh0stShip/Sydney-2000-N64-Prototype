#include <libaudio.h>
#include "synthInternals.h"

#define EQPOWER_LENGTH 128

extern s16 eqpower[];
extern Acmd* _pullSubFrame(void* filter, s16* inp, s16* outp, s32 outCount,
                           s32 sampleOffset, Acmd* p);
extern f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel);

Acmd* alEnvmixerPull(void* filter, s16* outp, s32 outCount, s32 sampleOffset,
                     Acmd* p) {
    Acmd* ptr = p;
    ALEnvMixer* e = (ALEnvMixer*)filter;
    s16 inp;
    s32 lastOffset;
    s32 thisOffset = sampleOffset;
    s32 samples;
    s16 loutp = 0;
    s32 fVol;
    ALParam* thisParam;

    inp = AL_RESAMPLER_OUT;

    while (e->ctrlList != 0) {
        lastOffset = thisOffset;
        thisOffset = e->ctrlList->delta;
        samples = thisOffset - lastOffset;
        if (samples > outCount) {
            break;
        }

        switch (e->ctrlList->type) {
            case AL_FILTER_START_VOICE_ALT: {
                ALStartParamAlt* param = (ALStartParamAlt*)e->ctrlList;
                ALFilter* f = (ALFilter*)e;
                s32 tmp;

                if (param->unity) {
                    (*e->filter.setParam)(&e->filter,
                                          AL_FILTER_SET_UNITY_PITCH, 0);
                }

                (*e->filter.setParam)(&e->filter, AL_FILTER_SET_WAVETABLE,
                                      param->wave);
                (*e->filter.setParam)(&e->filter, AL_FILTER_START, 0);

                e->first = 1;
                e->delta = 0;
                e->segEnd = param->samples;

                tmp = ((s32)param->volume * (s32)param->volume) >> 15;
                e->volume = (s16)tmp;
                e->pan = param->pan;
                e->dryamt = eqpower[param->fxMix];
                e->wetamt = eqpower[EQPOWER_LENGTH - param->fxMix - 1];

                if (param->samples) {
                    e->cvolL = 1;
                    e->cvolR = 1;
                } else {
                    e->cvolL = (e->volume * eqpower[e->pan]) >> 15;
                    e->cvolR = (e->volume *
                                eqpower[EQPOWER_LENGTH - e->pan - 1]) >> 15;
                }

                if (f->source) {
                    union {
                        f32 f;
                        s32 i;
                    } data;
                    data.f = param->pitch;
                    (*f->source->setParam)(f->source, AL_FILTER_SET_PITCH,
                                          (void*)data.i);
                }
            } break;

            case AL_FILTER_SET_FXAMT:
            case AL_FILTER_SET_PAN:
            case AL_FILTER_SET_VOLUME:
                ptr = _pullSubFrame(e, &inp, &loutp, samples, sampleOffset, ptr);

                if (e->delta >= e->segEnd) {
                    e->ltgt = (e->volume * eqpower[e->pan]) >> 15;
                    e->rtgt = (e->volume *
                               eqpower[EQPOWER_LENGTH - e->pan - 1]) >> 15;
                    e->delta = e->segEnd;
                    e->cvolL = e->ltgt;
                    e->cvolR = e->rtgt;
                } else {
                    e->cvolL = _getVol(e->cvolL, e->delta,
                                       e->lratm, e->lratl);
                    e->cvolR = _getVol(e->cvolR, e->delta,
                                       e->rratm, e->rratl);
                }

                if (e->cvolL == 0) {
                    e->cvolL = 1;
                }
                if (e->cvolR == 0) {
                    e->cvolR = 1;
                }

                if (e->ctrlList->type == AL_FILTER_SET_PAN) {
                    e->pan = (s16)e->ctrlList->data.i;
                }

                if (e->ctrlList->type == AL_FILTER_SET_VOLUME) {
                    e->delta = 0;
                    fVol = e->ctrlList->data.i;
                    fVol = (fVol * fVol) >> 15;
                    e->volume = (s16)fVol;
                    e->segEnd = e->ctrlList->moredata.i;
                }

                if (e->ctrlList->type == AL_FILTER_SET_FXAMT) {
                    e->dryamt = eqpower[e->ctrlList->data.i];
                    e->wetamt =
                        eqpower[EQPOWER_LENGTH - e->ctrlList->data.i - 1];
                }

                e->first = 1;
                break;

            case AL_FILTER_START_VOICE: {
                ALStartParam* start = (ALStartParam*)e->ctrlList;

                if (start->unity) {
                    (*e->filter.setParam)(&e->filter,
                                          AL_FILTER_SET_UNITY_PITCH, 0);
                }

                (*e->filter.setParam)(&e->filter, AL_FILTER_SET_WAVETABLE,
                                      start->wave);
                (*e->filter.setParam)(&e->filter, AL_FILTER_START, 0);
            } break;

            case AL_FILTER_STOP_VOICE:
                ptr = _pullSubFrame(e, &inp, &loutp, samples,
                                    sampleOffset, ptr);
                (*e->filter.setParam)(&e->filter, AL_FILTER_RESET, 0);
                break;

            case AL_FILTER_FREE_VOICE: {
                ALSynth* drvr = &alGlobals->drvr;
                ALFreeParam* param = (ALFreeParam*)e->ctrlList;
                param->pvoice->offset = 0;
                _freePVoice(drvr, (PVoice*)param->pvoice);
            } break;

            default:
                ptr = _pullSubFrame(e, &inp, &loutp, samples,
                                    sampleOffset, ptr);
                (*e->filter.setParam)(&e->filter, e->ctrlList->type,
                                      (void*)e->ctrlList->data.i);
                break;
        }
        loutp += samples << 1;
        outCount -= samples;

        thisParam = e->ctrlList;
        e->ctrlList = e->ctrlList->next;
        if (e->ctrlList == 0) {
            e->ctrlTail = 0;
        }

        __freeParam(thisParam);
    }

    ptr = _pullSubFrame(e, &inp, &loutp, outCount, sampleOffset, ptr);

    if (e->delta > e->segEnd) {
        e->delta = e->segEnd;
    }

    return ptr;
}
