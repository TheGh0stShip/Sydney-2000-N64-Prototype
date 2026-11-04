#include <ultra64.h>

static f64 _frexpf(f64 value, s32* eptr) {
    f64 absvalue;

    *eptr = 0;
    if (value == 0.0) {
        return value;
    }
    absvalue = (value > 0.0) ? value : -value;
    for (; absvalue >= 1.0; absvalue *= 0.5) {
        ++*eptr;
    }
    for (; absvalue < 0.5; absvalue += absvalue) {
        --*eptr;
    }
    return value > 0.0 ? absvalue : -absvalue;
}

f64 _ldexpf(f64 in, s32 ex) {
    s32 exp;

    if (ex) {
        exp = 1 << ex;
        in *= (f64)exp;
    }

    return in;
}

s16 _getRate(f64 vol, f64 tgt, s32 count, u16* ratel) {
    s16 s;
    f64 invn = 1.0 / count;
    f64 eps;
    f64 a;
    f64 fs;
    f64 mant;
    s32 i_invn;
    s32 ex;
    s32 indx;

    if (count == 0) {
        if (tgt >= vol) {
            *ratel = 0xffff;
            return 0x7fff;
        } else {
            *ratel = 0;
            return 0;
        }
    }

    if (tgt < 1.0) {
        tgt = 1.0;
    }
    if (vol <= 0) {
        vol = 1;
    }

    {
        f64 logtab[] = {
            -0.912537, -0.752072, -0.607683, -0.476438,
            -0.356144, -0.245112, -0.142019, -0.045804
        };

        i_invn = (s32)_ldexpf(invn, 30);
        mant = _frexpf(tgt / vol, &ex);
        indx = (s32)_ldexpf(mant, 4);
        eps = (logtab[indx - 8] + ex) * 0.69314718055994530942;
        eps /= _ldexpf(1, 30);
        fs = 1.0 + eps;
        a = 1.0;
        while (i_invn) {
            if (i_invn & 1) {
                a = a * fs;
            }
            fs *= fs;
            i_invn >>= 1;
        }
    }

    a *= (a *= (a *= a));
    s = (s16)a;
    *ratel = (s16)(0xffff * (a - (f32)s));
    return (s16)a;
}

f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel) {
    f32 r;
    f32 a;
    s32 i;

    samples >>= 3;
    if (samples == 0) {
        return ivol;
    }
    r = ((f32)(ratem << 16) + (f32)ratel) / 65536;

    a = 1.0;
    for (i = 0; i < 32; i++) {
        if (samples & 1) {
            a *= r;
        }
        samples >>= 1;
        if (samples == 0) {
            break;
        }
        r *= r;
    }
    ivol *= a;
    return ivol;
}
