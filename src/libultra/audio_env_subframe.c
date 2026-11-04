#include <libaudio.h>
#include "synthInternals.h"

#define EQPOWER_LENGTH 128

static s16 eqpower[EQPOWER_LENGTH] = {
    32767, 32764, 32757, 32744, 32727, 32704, 32677, 32644,
    32607, 32564, 32517, 32464, 32407, 32344, 32277, 32205,
    32127, 32045, 31958, 31866, 31770, 31668, 31561, 31450,
    31334, 31213, 31087, 30957, 30822, 30682, 30537, 30388,
    30234, 30075, 29912, 29744, 29572, 29395, 29214, 29028,
    28838, 28643, 28444, 28241, 28033, 27821, 27605, 27385,
    27160, 26931, 26698, 26461, 26220, 25975, 25726, 25473,
    25216, 24956, 24691, 24423, 24151, 23875, 23596, 23313,
    23026, 22736, 22442, 22145, 21845, 21541, 21234, 20924,
    20610, 20294, 19974, 19651, 19325, 18997, 18665, 18331,
    17993, 17653, 17310, 16965, 16617, 16266, 15913, 15558,
    15200, 14840, 14477, 14113, 13746, 13377, 13006, 12633,
    12258, 11881, 11503, 11122, 10740, 10357, 9971, 9584,
    9196, 8806, 8415, 8023, 7630, 7235, 6839, 6442,
    6044, 5646, 5246, 4845, 4444, 4042, 3640, 3237,
    2833, 2429, 2025, 1620, 1216, 810, 405, 0
};

extern s16 _getRate(f64 vol, f64 tgt, s32 count, u16* ratel);

Acmd* _pullSubFrame(void* filter, s16* inp, s16* outp, s32 outCount,
                    s32 sampleOffset, Acmd* p) {
    Acmd* ptr = p;
    ALEnvMixer* e = (ALEnvMixer*)filter;
    ALFilter* source = e->filter.source;

    if (e->motion != AL_PLAYING || !outCount) {
        return ptr;
    }

    ptr = (*source->handler)(source, inp, outCount, sampleOffset, p);

    aSetBuffer(ptr++, A_MAIN, *inp, AL_MAIN_L_OUT + *outp, outCount << 1);
    aSetBuffer(ptr++, A_AUX, AL_MAIN_R_OUT + *outp, AL_AUX_L_OUT + *outp,
               AL_AUX_R_OUT + *outp);

    if (e->first) {
        e->first = 0;

        e->ltgt = (e->volume * eqpower[e->pan]) >> 15;
        e->lratm = _getRate((f64)e->cvolL, (f64)e->ltgt,
                            e->segEnd, &e->lratl);
        e->rtgt = (e->volume *
                   eqpower[EQPOWER_LENGTH - e->pan - 1]) >> 15;
        e->rratm = _getRate((f64)e->cvolR, (f64)e->rtgt, e->segEnd,
                            &e->rratl);

        aSetVolume(ptr++, A_LEFT | A_VOL, e->cvolL, 0, 0);
        aSetVolume(ptr++, A_RIGHT | A_VOL, e->cvolR, 0, 0);
        aSetVolume(ptr++, A_LEFT | A_RATE, e->ltgt, e->lratm, e->lratl);
        aSetVolume(ptr++, A_RIGHT | A_RATE, e->rtgt, e->rratm, e->rratl);
        aSetVolume(ptr++, A_AUX, e->dryamt, 0, e->wetamt);
        aEnvMixer(ptr++, A_INIT | A_AUX, osVirtualToPhysical(e->state));
    } else {
        aEnvMixer(ptr++, A_CONTINUE | A_AUX, osVirtualToPhysical(e->state));
    }

    *inp += outCount << 1;
    e->delta += outCount;

    return ptr;
}
