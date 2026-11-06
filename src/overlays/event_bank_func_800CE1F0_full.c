/* Event-bank event dispatcher (link VRAM 0x80070940), ROM 0xCE1F0..0xCE420. */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef float f32;

typedef struct {
    s32 type;
    s32 time;
    s32 pad08;
    s32 pad0C;
    unsigned int arg;
} Event;

typedef struct {
    u8 b[4];
} Bytes4;

extern void *D_800707D8[];
extern Bytes4 D_800707D0;
extern u8 *D_800FC270;
extern char D_800F2AD8[];
extern char D_800F2758[];

extern void func_80015EAC(s32);
extern void func_800177AC(void);
extern void func_80070B70(u8 *);
extern void func_80070FE0(u8 *, s32);
extern void func_800828B4(u8 *, s32);
extern void func_80083700(u8 *, s32);
extern void func_8008393C(u8 *, s32, u8 *);
extern void func_80083A0C(u8 *);
extern void func_800AA658(char *, void *);
extern void func_800BBD78(char *, s32, s32, u8 *, s32);
extern void func_800BC07C(u8 *, s32);

#define F32(o) (*(s32 *)(obj + (o)))
#define FPTR(o) (*(u8 **)(obj + (o)))

void func_800CE1F0(u8 *obj, Event *evt)
{
    static void *const unused_tbl[] = {
        &&C1, &&C2, &&C3, &&C5, &&C7, &&done
    };
    s32 dt = (evt->time - F32(0x10)) >> 8;
    unsigned int i;
    u8 *p;

    i = evt->type - 1;
    if (i >= 12)
        goto done;
    goto *D_800707D8[i];
C3:
    func_80015EAC(12);
    {
        u8 *g = D_800FC270;
        u8 a = g[0xD1B];
        u8 b = g[0xD1F];
        Bytes4 t = D_800707D0;
        u8 idx;
        idx = t.b[a] + b;
        F32(0x43BC) = 0;
        func_8008393C(obj, 15, obj + 0x43BC);
        FPTR(0x43B8) = FPTR(0x43BC) + idx * 4;
        obj[0x43C0] = obj[0x43C1] = FPTR(0x43B8)[0];
        obj[0x43C2] = FPTR(0x43B8)[2];
        F32(0xF10) = (s8)FPTR(0x43B8)[1] * *(f32 *)0x80070808;
    }
    func_80070B70(obj);
    func_800177AC();
    goto done;
C7:
    switch (evt->arg) {
    case 8:
    case 15:
        func_800BBD78(D_800F2AD8, 12, 1, obj, 0);
        break;
    case 7:
    case 57:
        func_800AA658(D_800F2758, obj + 0x43BC);
        func_800828B4(obj, evt->arg);
        break;
    }
    goto done;
C1:
    func_80083700(obj, evt->arg);
    goto done;
C2:
    p = (u8 *)&evt->arg;
    if (F32(0x43D0) == 2) {
        func_800BC07C(FPTR(0xF1C), p[1]);
    } else {
        func_800BC07C(FPTR(0xF1C), p[1]);
        if (FPTR(0xF1C)[3] != 0) {
            F32(0xF14) = 1;
        }
    }
    func_80070FE0(obj, dt);
    goto done;
C5:
    func_80083A0C(obj);
    func_80070FE0(obj, dt);
done:
    F32(0x10) = evt->time;
}
