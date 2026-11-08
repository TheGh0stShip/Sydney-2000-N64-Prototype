typedef unsigned char u8;
typedef int s32;

extern void func_800832B8(u8 *p, s32 a);
extern void func_800ADC1C(u8 *p);
extern void func_8009D708(u8 *p, s32 a, s32 b);

typedef struct Obj { u8 pad[26984]; u8 *tbl[3]; } Obj;
#define B(o) (*(u8 *)(p + (o)))

void func_80126788(u8 *p)
{
    u8 *q;
    u8 *o;
    u8 i;
    s32 a;
    s32 c;

    q = *(u8 **)(p + 4);
    c = 0;
    if (q[1556] == 5) {
        c = B(426) != 4;
    }
    if (c) {
        func_800832B8(p, B(2072));
    }
    if (++B(2072) == 2) {
        i = 0;
        while (1) {
            if (!(i < 3)) break;
            o = ((Obj *)p)->tbl[i];
            func_800ADC1C(o + 2196);
            func_800ADC1C(o + 1984);
            func_800ADC1C(o + 2408);
            i++;
        }
    }
    if (B(2072) == 9) {
        a = *(s32 *)(p + 740) == 0;
        c = 0;
        if (B(426) != 4) {
            c = q[1556] != 2;
        }
        if (c) {
            if (q[1556] == 5) {
                func_8009D708(p + 2076, a, 0);
            } else {
                func_8009D708(p + 2076, a, 1);
            }
        }
    }
}
