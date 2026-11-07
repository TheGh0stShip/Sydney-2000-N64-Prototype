typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern void func_80037F30(void *dst, s32 v, s32 n);
extern void func_8008393C(u8 *p, s32 id, void *out);

#define W(o) (*(s32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define SB(o) (*(s8 *)(p + (o)))
#define H(o) (*(s16 *)(p + (o)))
#define P(o) (*(u8 **)(p + (o)))

void func_800C6E94(u8 *p, u8 sel, s32 base)
{
    u8 buf[4];
    u8 idx;
    u8 *e;
    u8 i;
    u8 n;

    func_80037F30(buf, 0, 4);
    buf[3] = 3;
    idx = buf[sel] + base;
    W(0x42E8) = 0;
    func_8008393C(p, 12, p + 0x42E8);
    P(0x42E4) = P(0x42E8) + idx * 14;
    W(0x44C8) = (s8)P(0x42E4)[2];
    SB(0x44BB) = P(0x42E4)[3];
    P(0x44BC) = P(0x42E4) + 4;
    B(0x44C4) = P(0x42E4)[1];
    B(0x44BA) = SB(0x44BB);
    H(0x44E0) = 0;
    if (W(0x44C8) == 2) {
        W(0xF10) = (s8)P(0x42E4)[9] * 7680;
        W(0x44DC) = 0;
        for (i = 0; i < SB(0x44BB); i++) {
            W(0x44DC) += (s8)(P(0x42E4) + i)[9] * 7680;
        }
    } else {
        W(0x44DC) = W(0xF10) = (s8)P(0x42E4)[0] * 7680;
    }
}
