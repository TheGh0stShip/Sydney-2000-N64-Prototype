#include <libaudio.h>
#include "synthInternals.h"

s32 alResampleParam(void* filter, s32 paramID, void* param) {
    ALFilter* f = (ALFilter*)filter;
    ALResampler* r = (ALResampler*)filter;
    union {
        f32 f;
        s32 i;
    } data;

    switch (paramID) {
        case AL_FILTER_SET_SOURCE:
            f->source = (ALFilter*)param;
            break;

        case AL_FILTER_RESET:
            r->delta = 0.0;
            r->first = 1;
            r->motion = AL_STOPPED;
            r->upitch = 0;
            if (f->source) {
                (*f->source->setParam)(f->source, AL_FILTER_RESET, 0);
            }
            break;

        case AL_FILTER_START:
            r->motion = AL_PLAYING;
            if (f->source) {
                (*f->source->setParam)(f->source, AL_FILTER_START, 0);
            }
            break;

        case AL_FILTER_SET_PITCH:
            data.i = (s32)param;
            r->ratio = data.f;
            break;

        case AL_FILTER_SET_UNITY_PITCH:
            r->upitch = 1;
            break;

        default:
            if (f->source) {
                (*f->source->setParam)(f->source, paramID, param);
            }
            break;
    }
    return 0;
}
