/* Event-bank event handler (ROM 0x70810, link VRAM 0x80070D00): dispatches on event type and sub-type. */
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 type;
    s32 time;
    s32 pad08;
    s32 pad0C;
    unsigned int arg;
} Event;

extern void *D_800707D0[];
extern void *D_80070800[];
extern s32 D_800F2744;
extern char D_800F26E0[];
extern char D_800F11A0[];

extern void func_800B4794(s32);
extern void func_80070F20(u8 *, s32);
extern void func_80072874(u8 *);
extern void func_800BC07C(u8 *, s32);
extern void func_80072550(u8 *);
extern void func_800AB2A4(char *, s32, s32, void *, u8 *, s32);
extern void func_800738B8(u8 *, u8 *, u8 *, s32);
extern void func_800A9B78(u8 *, u8 *, s32, s32, s32);

void func_80070810(u8 *self, Event *ev)
{
    static void *const unused_tbl[] = {
        &&T1, &&T2, &&T3, &&T4, &&T5, &&S1, &&S2, &&S3, &&S4, &&S5, &&S6, &&S7, &&done
    };
    unsigned int i;
    u8 *p;

    i = ev->type - 1;
    if (i >= 11)
        goto done;
    goto *D_800707D0[i];
T1:
    func_800B4794(1);
    func_80070F20(self, ev->arg);
    func_800B4794(0);
    goto done;
T2:
    if (*(s32 *)(self + 0x1164) == 0)
        goto done;
    func_80072874(self);
    goto done;
T3:
    p = self + 0xCC;
    func_800BC07C(p, ((u8 *)ev)[0x11]);
    if (p[3] == 0)
        goto done;
    if (!(*(s32 *)(self + 0x13AC) + 0x3C00 < ev->time))
        goto done;
    func_80072550(self);
    if (self[0x1168] != 0)
        func_800AB2A4(D_800F26E0, D_800F2744, 3, D_800F11A0, self, 0);
    else {
        void *owner = *(void **)(self + 4);
        func_800AB2A4(D_800F26E0, D_800F2744, 20, owner, self, 15);
    }
    goto done;
T4:
    func_80072550(self);
    if (self[0x1168] != 0)
        func_800AB2A4(D_800F26E0, D_800F2744, 3, D_800F11A0, self, 0);
    else {
        void *owner = *(void **)(self + 4);
        func_800AB2A4(D_800F26E0, D_800F2744, 20, owner, self, 15);
    }
    goto done;
T5:
    if (ev->arg >= 22)
        goto done;
    goto *D_80070800[ev->arg];
S1:
    func_800A9B78(self + 4004, self + 240, 1, 1, 2);
    goto done;
S2:
    func_800738B8(self, self + 1088, self + 1724, 1);
    goto done;
S3:
    func_800738B8(self, self + 1300, self + 2128, 1);
    goto done;
S4:
    func_800738B8(self, self + 1512, self + 2532, 1);
    goto done;
S5:
    func_800A9B78(self + 4004, self + 3448, 1, 1, 2);
    goto done;
S6:
    func_800A9B78(self + 4004, self + 3632, 1, 1, 2);
    goto done;
S7:
    func_800A9B78(self + 4004, self + 3816, 1, 1, 2);
done:
    *(s32 *)(self + 0x10) = ev->time;
}
