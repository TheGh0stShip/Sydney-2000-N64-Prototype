/* Event-bank state handler (link VRAM 0x80071F08), ROM 0x832D8..0x83504.
 * 6-entry jump table at link VRAM 0x80071068 (ROM 0x82438) stays residual data. */
typedef unsigned char u8;
typedef int s32;
typedef float f32;
typedef struct { s32 pad[0x344]; s32 w0d10; } Glob;

extern void *D_80071068[];
extern Glob *D_800FC270;
extern u8 D_800F1AE0[];
extern s32 D_80077750;
extern s32 D_80077570;
extern u8 D_80077628[];
extern u8 D_80077560[];

extern void func_800A6308(u8 *);
extern s32 func_8009B4D4(s32, s32, s32, u8 *, s32, s32);
extern s32 func_8001D4B8(u8 *, s32, s32, s32);
extern void func_8001D640(u8 *, s32, s32);
extern void func_800D33A0(u8 *, u8 *, s32, s32);
extern void func_8007597C(u8 *);
extern void func_80075B6C(u8 *);

static __inline__ void snd_vol(u8 *g, s32 h, s32 scale)
{
    func_8001D640(g, h, (*(s32 *)(g + 0x68) * scale) >> 15);
}

static __inline__ void snd_play(u8 *g, s32 id)
{
    snd_vol(g, func_8001D4B8(g, id, 0, 1), 0x7FFF);
}

#define W(o) (*(s32 *)(p + (o)))
#define BY(o) (*(u8 *)(p + (o)))

void func_800832D8(u8 *p)
{
    f32 f;

    W(0x5424) -= 0x100;
    if (W(0x5424) > 0) {
        return;
    }
    func_800A6308(p + 0x38B8);
    {
        static void *const unused_tbl[] = { &&L01, &&L3, &&L4, &&L5, &&end };
        unsigned int i = BY(0x615);
        if (i >= 6) goto end;
        goto *D_80071068[i];
    }
L01:
    if (func_8009B4D4(7, W(0x52D0), BY(0x615), p + 0x3254, 2, 0) != 0) {
        snd_play(D_800F1AE0, 0xDC);
    } else {
        D_80077750 = ((s32 *)W(0x52D0))[1];
        func_800D33A0(p + 0x3254, D_80077628, 1, -1);
    }
    func_8007597C(p);
    goto end;
L3:
    f = (f32)W(0x542C) / *(f32 *)0x80071080 * *(f32 *)0x80071084;
    D_80077750 = *(s32 *)&f;
    func_800D33A0(p + 0x3254, D_80077628, 1, -1);
    goto end;
L5:
    func_80075B6C(p);
    goto end;
L4:
    if (D_800FC270->w0d10 >= W(0x542C)) {
        snd_play(D_800F1AE0, 0xD9);
        D_80077570 = 0x2A0;
    } else {
        snd_play(D_800F1AE0, 0xC8);
        D_80077570 = 0x2A1;
    }
    D_80077750 = W(0x542C);
    func_800D33A0(p + 0x3254, D_80077560, 0, -1);
end:
    BY(0x60F) = 0x1C;
}
