typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define CUR(o) ((u8 *)W(o, 1080) + (o)[1044] * 36)

typedef struct Slot {
    s32 a;
    s32 b;
    s32 c;
} Slot;

typedef struct Obj {
    u8 pad[928];
    Slot slots[8];
} Obj;

extern u8 D_800787C0[];
extern void func_8007DB20(u8 *o, s32 *a);
extern void func_8007CB60(u8 *o);
extern s32 func_8007CD4C(u8 *o, s32 a, s32 b);
extern void func_80078084(s32 a, s32 b, s32 c);
extern void func_800ADC1C(u8 *a);
extern void func_800AD388(u8 *a, s32 b, s32 c);
extern void func_8007D7E4(u8 *o);

void func_800E7C40(u8 *o, s32 *a)
{
    func_8007DB20(o, a);
    func_8007CB60(o);
    if (o[1088] == 0 && func_8007CD4C(o, ((u8 *)W(o, 648))[3], *a)) {
        o[1088] = 1;
        W(CUR(o), 24) = 1;
    }
    if (o[1192] != 0 && F(o, 88) <= F(CUR(o), 4)) {
        u8 *m = D_800787C0 + o[1046] * 76;
        u8 *d;
        F(o, 20) = F(m, 0);
        d = o + 20;
        F(d, 16) = F(m, 16);
        F(d, 32) = F(m, 32);
        F(d, 4) = F(m, 4);
        F(d, 20) = F(m, 20);
        F(d, 36) = F(m, 36);
        F(d, 8) = F(m, 8);
        F(d, 24) = F(m, 24);
        F(d, 40) = F(m, 40);
        if (W(CUR(o), 12) == 7) {
            u8 c = o[1046];
            if (c == 0 || c == 2) {
                o[1046] = c + 1;
            } else {
                o[1046] = c - 1;
            }
        }
        if (o[1088]) {
            u8 *q;
            o[1088] = 0;
            if (o[1089] == 0) {
                s32 k1 = o[1040] + 1;
                ((Obj *)o)->slots[k1].c = 0;
            } else {
                o[1089] = 0;
            }
            o[1193] = 1;
            if (W(CUR(o), 12) != 5) {
                s32 k = o[1040];
                s32 k1 = k + 1;
                if ((u32)((Obj *)o)->slots[k1].a >= 74) {
                    u32 v;
                    k += 2;
                    for (;;) {
                        v = ((Obj *)o)->slots[(u8)k].a;
                        ((Obj *)o)->slots[(u8)k].c = 0;
                        if (v < 74) {
                            break;
                        }
                        k++;
                    }
                }
                F(o, 1060) = F(o, 1068);
                if (W((u8 *)W(o, 848) + o[1043] * 16, 0) & 0x44C) {
                    F(o, 1060) = -F(o, 1068);
                }
                W(o, 172) = 28;
                o[1193] = 0;
            } else {
                W(o, 172) = 29;
            }
            q = (u8 *)(o[1044] * 496 + W(o, 4)) + 0x8CDC;
            q[256] = 2;
            {
                u8 *vt = (u8 *)W(q, 180);
                ((void (*)(u8 *))W(vt, 76))(q + *(s16 *)(vt + 72));
            }
            func_800ADC1C(q + 272);
            o[1044]++;
            F(o, 1084) = F(o, 88) - F(CUR(o), 4);
        } else {
            func_80078084(W(o, 4), o[1044], W(o, 1064));
            o[1088] = 1;
            W(o, 172) = 30;
            W(CUR(o), 24) = 0;
        }
    } else if (o[1193] == 0) {
        func_800AD388(o + 20, W(o, 1060), 3);
        F(o, 1048) += F(o, 1060);
    }
    func_8007D7E4(o);
}
