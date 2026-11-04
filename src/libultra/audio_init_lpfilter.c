#include <libaudio.h>
#include "synthInternals.h"

#define SCALE 16384

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
