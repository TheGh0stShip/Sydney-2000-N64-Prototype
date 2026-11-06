typedef unsigned char u8;
typedef int s32;

#define W(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define B(p, off) (*(u8 *)((u8 *)(p) + (off)))

extern s32 D_800F2620;
extern s32 D_80077C78;
extern u8 D_800F26E0[];
extern s32 D_800F2744;

extern void func_800B4794(s32 on);
extern void func_80073DD0(void *obj);
extern void func_80071540(void *obj, s32 *ev);
extern void func_800A9B78(void *a, s32 b, s32 c, s32 d, s32 e);
extern void func_80071BE4(void *obj);
extern void func_800730F4(void *obj, s32 dt);
extern void func_80071D28(void *obj, s32 *ev);
extern void func_800721D4(void *obj, s32 *ev);
extern void func_8009BD50(s32 id);
extern void func_800AB2A4(void *a, s32 b, s32 c, void *d, s32 e, s32 f);
extern void func_800759C8(void *obj);
extern void func_80072358(void *obj, s32 *ev);
extern void func_80072920(void *obj, s32 *ev, s32 dt);
extern void func_80072C5C(void *obj, s32 *ev);
extern void func_800DB124(s32 a);
extern void func_800137FC(void);
extern void func_80014384(void);

extern void *D_800710C0[];
struct bf { unsigned a : 8; };

void func_800AAB64(u8 *obj, s32 *ev)
{
    static void *const unused_tbl[] = {&&c1,&&c2,&&c3,&&c5,&&c7,&&c11,&&c12,&&c21,&&c23,&&c24,&&c25,&&end};
    u8 *hi;
    s32 dt = (ev[1] - W(obj, 0x10)) >> 8;
    unsigned idx = ev[0] - 1;

    if (idx >= 25) goto end;
    goto *D_800710C0[idx];
c3:
    if (D_800F2620 != 0) {
        D_80077C78 = 1;
    } else {
        D_80077C78 = 0;
    }
    func_800B4794(1);
    func_80073DD0(obj);
    func_800B4794(0);
    goto end;
c21:
    func_80071540(obj, ev);
    goto end;
c11:
    switch ((unsigned)ev[4]) {
    case 1:
        func_800A9B78(obj + 0x7F6C, W(obj, 0x2DB8), 1, 1, 2);
        break;
    case 2:
        func_800A9B78(obj + 0x7F6C, W(obj, 0x2DB8), 1, 1, 2);
        break;
    case 4:
        func_800A9B78(obj + 0x7F6C, W(obj, 0x2DB8), 1, 1, 2);
        break;
    default:
        func_800A9B78(obj + 0x7F6C, W(obj, 0x2DB8), 1, 1, 2);
        break;
    }
    goto end;
c12:
    func_80071BE4(obj);
    func_800730F4(obj, dt);
    goto end;
c25:
    func_80071D28(obj, ev);
    goto end;
c23:
    func_800721D4(obj, ev);
    goto end;
c24:
    {
        u8 *st = obj + 0x8000;
        s32 m;
        W(st, 0x118) = 0;
        func_8009BD50(B(st, 0x11E));
        m = B(st, 0x11E);
        if (m == 5) {
            { s32 t = B(st, 0x11F); B(st, 0x11E) = t; if (t) goto rl; m = t; }
          rl:
            m = B(st, 0x11E);
        }
        if (m == 3) {
            func_800AB2A4(D_800F26E0, ev[1], 21, obj, 0, 0);
        } else {
            func_800AB2A4(D_800F26E0, ev[1], 21, obj, 0, 0);
        }
    }
    func_800759C8(obj);
    B(obj, 0x811D) = 0;
    goto end;
c2:
    func_80072358(obj, ev);
    goto end;
c1:
    func_80072920(obj, ev, dt);
    goto end;
c7:
    func_80072C5C(obj, ev);
    goto end;
c5:
    if (W(obj, 0xAC) == 0) {
        func_800730F4(obj, dt);
    } else if (W(obj, 0xAC) == 1 && W(obj, 8) == 0) {
        func_800DB124(1);
        func_800137FC();
        func_80014384();
        { void *t = (void *)W(obj, 4); func_800AB2A4(D_800F26E0, D_800F2744, 20, t, obj, W(obj, 0x7F68)); }
    }
end:
    W(obj, 0x10) = ev[1];
}
