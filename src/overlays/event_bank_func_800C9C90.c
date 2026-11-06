/* Event-bank event dispatcher (link VRAM 0x800713A0), ROM 0xC9C90..0xC9EC4. */
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    s32 type;
    s32 time;
    s32 pad08;
    s32 pad0C;
    unsigned int arg;
} Event;

typedef struct {
    char pad[0x20];
    s16 off;
    s16 pad22;
    void (*fn)(u8 *);
} VTable;

extern u8 *D_800FC270;
extern void *D_800708A8[];
extern char D_800F2AD8[];
extern char D_800F2758[];

extern void func_80015EAC(s32);
extern void func_800177AC(void);
extern void func_8007221C(u8 *, s32, s32);
extern void func_80071EEC(u8 *);
extern void func_800715D4(u8 *, s32);
extern void func_800828B4(u8 *, s32);
extern void func_80083700(u8 *, s32);
extern void func_80083A0C(u8 *);
extern void func_800AA658(char *, void *);
extern void func_800BBD78(char *, s32, s32, u8 *, s32);
extern void func_800BC07C(u8 *, s32);

#define F32(o) (*(s32 *)(obj + (o)))
#define FPTR(o) (*(u8 **)(obj + (o)))

void func_800C9C90(u8 *obj, Event *evt)
{
    s32 dt = (evt->time - F32(0x10)) >> 8;
    s32 v;
    u8 *p;

    {
        static void *const unused_tbl[] = { &&L1, &&L2, &&L3, &&L5, &&L7 };
        unsigned int i = evt->type - 1;
        if (i >= 12) goto end;
        goto *D_800708A8[i];
    }
L3:
    func_80015EAC(12);
    {
        u8 *g = D_800FC270;
        func_8007221C(obj, g[0xD1B], g[0xD1F]);
    }
    func_80071EEC(obj);
    func_800177AC();
    goto end;
L7:
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
    goto end;
L1:
    func_80083700(obj, evt->arg);
    goto end;
L2:
    v = F32(0x42E4);
    p = (u8 *)&evt->arg;
    if (v >= 2U && v != 3) {
        s32 b;
        func_800BC07C(FPTR(0xF1C), p[1]);
        b = FPTR(0xF1C)[3];
        if (b & 1) F32(0x474C) = 1;
        if (b & 2) F32(0x4750) = 1;
        if (b & 0x10) F32(0x4754) = 1;
        b = FPTR(0xF1C)[2];
        if (b & 1) F32(0x474C) = 0;
        if (b & 2) F32(0x4750) = 0;
        if (b & 0x10) F32(0x4754) = 0;
    } else {
        func_800BC07C(FPTR(0xF1C), p[1]);
        if (FPTR(0xF1C)[3] != 0) {
            F32(0xF14) = 1;
        }
    }
    goto L5b;
L5:
    {
        VTable *vt = *(VTable **)(obj + 0xB4);
        vt->fn(obj + vt->off);
    }
    func_80083A0C(obj);
L5b:
    func_800715D4(obj, dt);
end:
    F32(0x10) = evt->time;
}
