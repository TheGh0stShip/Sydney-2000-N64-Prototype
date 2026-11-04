#include "synthInternals.h"

void _freePVoice(ALSynth* drvr, PVoice* pvoice) {
    alUnlink((ALLink*)pvoice);
    alLink((ALLink*)pvoice, &drvr->pLameList);
}

s32 _timeToSamplesNoRound(ALSynth* synth, s32 micros) {
    f32 tmp = ((f32)micros) * synth->outputRate / 1000000.0 + 0.5;

    return (s32)tmp;
}
