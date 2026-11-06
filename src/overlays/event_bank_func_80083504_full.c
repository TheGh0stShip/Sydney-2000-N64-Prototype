/* Event-bank state handler (link VRAM 0x80072134), ROM 0x83504..0x8367C.
 * 6-entry jump table at link VRAM 0x80071088 (ROM 0x82458) stays data. */
typedef unsigned char u8;
typedef int s32;

extern void *D_80071088[];
extern u8 D_800F1AE0[];
extern u8 D_80077678[];

extern void func_80075220(u8 *);
extern s32 func_8001D4B8(u8 *, s32, s32, s32);
extern void func_8001D640(u8 *, s32, s32);
extern void func_8001D5D8(u8 *, s32, s32, s32, s32, s32);
extern void func_8009BEE0(s32);
extern void func_800D33A0(u8 *, u8 *, s32, s32);
extern void func_8007676C(u8 *, s32, s32, s32);
extern void func_800A9BE8(u8 *, s32);
extern void func_800177EC(void);

static __inline__ s32 snd_fade(u8 *g, s32 id, s32 scale)
{
    s32 h = func_8001D4B8(g, id, 0, -1);
    func_8001D640(g, h, 0);
    func_8001D5D8(g, h, (*(s32 *)(g + 0x68) * scale) >> 15, 15, 0, 0);
    return h;
}

#define W(o) (*(s32 *)(p + (o)))
#define BY(o) (*(u8 *)(p + (o)))

void func_80083504(u8 *p)
{

    {
        static void *const unused_tbl[] = { &&L01, &&L2, &&end };
        unsigned int i = BY(0x615);
        if (i >= 6) goto end;
        goto *D_80071088[i];
    }
L01:
    func_80075220(p);
    W(0x545C) = snd_fade(D_800F1AE0, 0x103, 0x3FFF);
    W(0x5448) = snd_fade(D_800F1AE0, 0x10C, 0x3FFF);
    func_8009BEE0(0x2D00);
    goto end;
L2:
    func_800D33A0(p + 0x3254, D_80077678, 1, -1);
    func_8007676C(p, 0x29, 0, 0);
end:
    func_800A9BE8(p + 0x45C, BY(0x612));
    BY(0x60F) = 2;
    W(0x5424) = W(0x5460);
    func_800177EC();
}
