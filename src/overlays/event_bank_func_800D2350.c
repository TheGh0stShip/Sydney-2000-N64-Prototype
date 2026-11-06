/* Event-bank event dispatcher (link VRAM 0x80070960), ROM 0xD2350..0xD2548. */
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 type;
    s32 time;
    s32 pad08;
    s32 pad0C;
    unsigned int arg;
} Event;

extern u8 *D_800FC270;
extern char D_800F2AD8[];
extern char D_800F2758[];

extern void func_80015EAC(s32);
extern void func_800177AC(void);
extern void func_80070B58(u8 *, s32);
extern void func_80071404(u8 *);
extern void func_800718B4(u8 *, s32, s32);
extern void func_800828B4(u8 *, s32);
extern void func_80083700(u8 *, s32);
extern void func_80083A0C(u8 *);
extern void func_800AA658(char *, void *);
extern void func_800BBD78(char *, s32, s32, u8 *, s32);
extern void func_800BC07C(u8 *, s32);

#define F32(o) (*(s32 *)(obj + (o)))
#define FU8(o) (*(u8 *)(obj + (o)))
#define FPTR(o) (*(u8 **)(obj + (o)))

void func_800D2350(u8 *obj, Event *evt)
{
    s32 dt = (evt->time - F32(0x10)) >> 8;
    s32 v;
    u8 *p;

    switch (evt->type) {
    case 3:
        func_80015EAC(12);
        {
            u8 *g = D_800FC270;
            func_800718B4(obj, g[0xD1B], g[0xD1F]);
        }
        func_80071404(obj);
        func_800177AC();
        break;
    case 7:
        switch (evt->arg) {
        case 8:
        case 15:
            func_800BBD78(D_800F2AD8, 12, 1, obj, 0);
            break;
        case 7:
        case 57:
            func_800AA658(D_800F2758, obj + 0x42EC);
            func_800828B4(obj, evt->arg);
            break;
        }
        break;
    case 1:
        func_80083700(obj, evt->arg);
        break;
    case 2:
        v = F32(0x42E4);
        p = (u8 *)&evt->arg;
        if (v >= 2U && v != 3) {
            func_800BC07C(FPTR(0xF1C), p[1]);
            FU8(0x471D) = FPTR(0xF1C)[2];
            if (FU8(0x471D) & 0x10) {
                F32(0x473C) = 0;
            }
            FU8(0x471D) = FPTR(0xF1C)[3];
            if (FU8(0x471D) & 0x10) {
                F32(0x473C) = 1;
                FU8(0x471D) &= ~0x10;
            }
        } else {
            func_800BC07C(FPTR(0xF1C), p[1]);
            {
                s32 b = FPTR(0xF1C)[3];
                FU8(0x471D) = b;
                if (b != 0) {
                    F32(0xF14) = 1;
                }
            }
        }
    case 5:
        func_80070B58(obj, dt);
        func_80083A0C(obj);
        break;
    case 12:
        break;
    }
    F32(0x10) = evt->time;
}
