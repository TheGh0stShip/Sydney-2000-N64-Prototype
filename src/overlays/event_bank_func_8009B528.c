typedef struct {
    char pad0[0xA04];
    int enabled;
    char pad1[0xD10 - 0xA08];
    float threshold;
} SoundCtx;

extern SoundCtx *D_800FC270;
extern void *const D_800714F0[];
extern char D_800F3BC0[];
extern unsigned int D_800F2C14;
extern void func_800C0110(void *, int, int, int);
extern int func_8009B670_ext(char *);

#define PLAY(id) if (D_800FC270->enabled) func_800C0110(D_800F3BC0, (id), 0, 0)

static __inline__ int coin_(int range) {
    D_800F2C14 = (D_800F2C14 * 16807) & 0x7FFFFFFF;
    return (((D_800F2C14 >> 15) * range) >> 16) < 50;
}
#define coin() coin_(100)

void func_8009B528(char *arg) {
    char *p = arg + 0x8000;
    SoundCtx *ctx;
    float f0;
    float f2;
    int b80;
    int b81;
    char *q;

    if (*(unsigned char *)(p + 0x54) == 5) {
        return;
    }
    {
        static void *const unused_tbl[] = { &&L0, &&L1, &&L2, &&L3, &&L4, &&L5 };
        unsigned int sel = *(unsigned char *)(p + 0x53);
        if (sel >= 6) goto L0;
        goto *D_800714F0[sel];
    }
    {
    L1:
        if (coin()) {
            PLAY(231);
        } else {
            PLAY(310);
        }
        goto end;
    L2:
        PLAY(518);
        goto end;
    L3:
        PLAY(517);
        goto end;
    L4:
        PLAY(519);
        goto end;
    L5:
        if (coin()) {
            PLAY(309);
        } else {
            PLAY(524);
        }
        goto end;
    L0:
        ctx = D_800FC270;
        if (ctx->enabled != 1) {
            goto end;
        }
        p = arg + 0x8000;
        b81 = *(signed char *)(p + 0x51);
        b80 = *(signed char *)(p + 0x50);
        f2 = ctx->threshold;
        f0 = (*(float **)(p + 0x8C))[b81 * 3 + b80];
        q = *(char **)(arg + 0x2F68);
        if (*(int *)(q + 0x2E8)) {
            if (f2 < f0) {
                if (f2 < *(float *)(p + 0x90)) {
                    PLAY(526);
                } else {
                    PLAY(525);
                }
            } else if (f2 < *(float *)(p + 0x90)) {
                PLAY(523);
            } else if (b80 < 2) {
                PLAY(520);
            } else if ((unsigned char)func_8009B670_ext(q) >= 12) {
                PLAY(521);
            } else {
                PLAY(522);
            }
        } else {
            if (f2 < *(float *)(p + 0x90)) {
                PLAY(516);
            } else if (b80 < 2) {
                PLAY(514);
            } else if ((unsigned char)func_8009B670_ext(q) >= 12) {
                PLAY(515);
            } else {
                PLAY(522);
            }
        }
        goto end;
    }
end:;
}
