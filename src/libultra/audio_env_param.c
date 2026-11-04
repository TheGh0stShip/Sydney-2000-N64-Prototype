#include <libaudio.h>
#include "synthInternals.h"

s32 alEnvmixerParam(void* filter, s32 paramID, void* param) {
    ALFilter* f = (ALFilter*)filter;
    ALEnvMixer* e = (ALEnvMixer*)filter;

    switch (paramID) {
        case AL_FILTER_ADD_UPDATE:
            if (e->ctrlTail) {
                e->ctrlTail->next = (ALParam*)param;
            } else {
                e->ctrlList = (ALParam*)param;
            }
            e->ctrlTail = (ALParam*)param;
            break;

        case AL_FILTER_RESET:
            e->first = 1;
            e->motion = AL_STOPPED;
            e->volume = 1;
            if (f->source) {
                (*f->source->setParam)(f->source, AL_FILTER_RESET, param);
            }
            break;

        case AL_FILTER_START:
            e->motion = AL_PLAYING;
            if (f->source) {
                (*f->source->setParam)(f->source, AL_FILTER_START, param);
            }
            break;

        case AL_FILTER_SET_SOURCE:
            f->source = (ALFilter*)param;
            break;

        default:
            if (f->source) {
                (*f->source->setParam)(f->source, paramID, param);
            }
    }
    return 0;
}
