typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define F(o, t) (*(t *)(obj + (o)))
#define H(o, t) (*(t *)(obj + 0x8000 + (o)))

typedef struct {
    char pad0[0x68];
    s32 vol;
} Snd;

typedef struct {
    char pad0[2];
    u8 cnt;
    u8 state;
    char pad4[0x18 - 4];
    s32 val;
    char pad1C[4];
} Lap;

extern u8 D_800F2AD0[];
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern Snd D_800F1AE0;
extern s32 D_800F1270[];
extern u8 D_80077B88[];
extern u8 D_80077B40[];
extern void func_800BC07C(void *, s32);
extern void func_800AB2A4(void *, s32, s32, void *, s32, s32);
extern void func_800D29E0(void *);
extern s32 func_8001D4B8(void *, s32, s32, s32);
extern void func_8001D640(void *, s32, s32);
extern void func_8008204C(void *);
extern void func_80081030(void *, s32);
extern void func_800820DC(void *);
extern void func_800B31EC(s32);
extern void func_800D33A0(void *, void *, s32, s32);
extern void func_800B360C(void *, void *);
extern void func_800B3254(void *, s32);
extern void func_800B3214(void *, s32);
extern void func_800AC25C(void *, s32, s32, s32);
extern void func_80076390(void *, s32);
extern s32 func_80076F30(void *);
extern void func_800AC334(void *);
extern void func_800B35F0(void *);
extern void func_800ADC1C(void *);
extern void func_8007754C(void *);

static inline s32 mulv(s32 a, s32 b)
{
    return a * b;
}

static inline void setsnd(s32 v)
{
    D_800F1270[1] = 0;
    D_800F1270[0] = v;
}

static inline void snd(s32 id)
{
    Snd *s = &D_800F1AE0;
    s32 r = func_8001D4B8(s, id, 0, 0);

    func_8001D640(s, r, mulv(s->vol, 32767) >> 15);
}

void func_80072358(u8 *obj, u8 *arg)
{
    u8 *pad;
    u8 m;
    u8 *p;

    pad = D_800F2AD0;
    func_800BC07C(pad, arg[17]);
    if (H(0x14C, s32) != 0) {
        F(0x7F68, s32) = 0;
        func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 9);
        return;
    }
    m = H(0x11E, u8);
    if (m == 2) {
        if (pad[3] == 0) {
            return;
        }
        H(0x11D, u8) = 20;
        H(0x12C, s32) = 256;
        func_800D29E0(obj + 696);
        if (H(0x130, s32) > 0) {
            H(0x130, s32) = 256;
        }
        return;
    }
    if (H(0x11D, u8) == 1) {
        if (pad[3] == 0) {
            return;
        }
        H(0x12C, s32) = 256;
        if (H(0x130, s32) > 0) {
            H(0x130, s32) = 256;
        }
        return;
    }
    if (H(0x11D, u8) != 2) {
        return;
    }
    if (pad[3] & 4) {
        if (m == 3) {
            snd(229);
            F(0x35CC, u32) += 5;
            if (F(0x35CC, u32) > 300) {
                F(0x35CC, u32) = 300;
            }
            p = obj + 7244;
            func_8008204C(p);
            func_80081030(p, F(0x35CC, s32));
            func_800820DC(p);
            func_800B31EC(3);
            setsnd(F(0x35CC, s32));
            if (H(0x11E, u8) == m) {
                func_800D33A0(obj + 11928, D_80077B88, 0, -1);
            } else {
                func_800D33A0(obj + 11928, D_80077B88, 0, 35);
            }
            func_800B31EC(3);
            func_800B360C(obj + 11708, D_80077B40);
        } else if (F(0x35CC, s32) != 300) {
            if (F(0x35C8, s32) != 0) {
                snd(226);
            }
            F(0x78DC, f32) = 172.0f;
            F(0x35C8, s32) = 0;
            func_800B3254(obj + 13328, 0x80000);
            func_800B3214(obj + 13548, 0x80000);
        }
    }
    if (pad[3] & 8) {
            m = H(0x11E, u8);
        if (m == 3) {
            snd(229);
            F(0x35CC, u32) -= 5;
            if (F(0x35CC, u32) < 150) {
                F(0x35CC, u32) = 150;
            }
            p = obj + 7244;
            func_8008204C(p);
            func_80081030(p, F(0x35CC, s32));
            func_800820DC(p);
            func_800B31EC(3);
            setsnd(F(0x35CC, s32));
            if (H(0x11E, u8) == m) {
                func_800D33A0(obj + 11928, D_80077B88, 0, -1);
            } else {
                func_800D33A0(obj + 11928, D_80077B88, 0, 35);
            }
            func_800B360C(obj + 11708, D_80077B40);
        } else if (F(0x35CC, s32) != 300) {
            if (F(0x35C8, s32) != 1) {
                snd(226);
            }
            F(0x78DC, f32) = 182.0f;
            F(0x35C8, s32) = 1;
            func_800B3214(obj + 13328, 0x80000);
            func_800B3254(obj + 13548, 0x80000);
        }
    }
    if ((pad[3] & 0x10) && F(0x35CC, u32) <= 300) {
        snd(130);
        if (F(0x35C8, s32) == 0) {
            func_800AC25C(obj, 100, 17, 1);
            func_80076390(obj, 0);
        } else {
                    H(0x13C, Lap *)[H(0x11C, s8)].cnt--;
            H(0x13C, Lap *)[H(0x11C, s8)].val = F(0x35CC, s32);
            if (func_80076F30(obj)) {
                H(0x13C, Lap *)[H(0x11C, s8)].state = 3;
            }
            if (H(0x11E, u8) == 4) {
                func_800AB2A4(D_800F26E0, D_800F2744, 24, obj, 0, 0);
            } else {
                H(0x11D, u8) = 24;
            }
        }
        p = obj + 13328;
        func_800AC334(p);
        func_800B35F0(p);
        func_800ADC1C(p);
        p = obj + 13548;
        func_800AC334(p);
        func_800B35F0(p);
        func_800ADC1C(p);
        p = obj + 30776;
        func_800AC334(p);
        func_800ADC1C(p);
        p = obj + 11928;
        func_800AC334(p);
        func_800D29E0(p);
        func_800ADC1C(p);
        func_800D29E0(obj + 696);
        func_800D29E0(obj + 2096);
        func_800D29E0(obj + 3496);
        func_800D29E0(obj + 4896);
    }
    func_8007754C(obj);
}
