typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define W(o) (*(s32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define F(o) (*(f32 *)(p + (o)))

extern s32 D_8007262C[3][3];
extern u8 D_800F1AE0[];

s32 func_8001D4B8(void *, s32, s32, s32);
void func_8001D640(void *, s32, s32);
void func_800722E8(u8 *);
void func_80072370(u8 *);
void func_80083624(u8 *, s32, s32, s32, s32, s32);
void func_800B9FA4(void *, s32, s32, f32, s32, s32);
void func_800B9E9C(void *, s32, s32, f32, s32);
s32 func_800B9BD4(void *, s32, void *, void *, void *, s32);
void func_800B9964(void *, void *, void *, void *);

#define CALL(a, w) func_800B9FA4(p + 4552, (a), -1, (w), 0, 1)
#define SWT(h, c, L)                                                \
    switch (H(h)) {                                                 \
    case 1: CALL(D_8007262C[0][c], F(19756)); break;                \
    case 2: CALL(D_8007262C[1][c], F(19756)); break;                \
    case 3: CALL(D_8007262C[2][c], F(19756)); break;                \
    }
#define AFTER                                                       \
    W(19800) = 1;                                                   \
    if (W(19776) != 0) {                                            \
        W(19776)--;                                                 \
        func_80083624(p, 57, W(19776), 0, 0, 0);                    \
    } else {                                                        \
        W(19816) = 1;                                               \
        W(19812) = 1;                                               \
    }                                                               \
    W(19732) = 3840;                                                \
    W(17132) = 4;
#define XTAIL(c, w)                                                 \
    CALL(D_8007262C[(u8)(b % 3)][c], (w));                          \
    W(19732) = 3840;                                                \
    W(19800) = 1;                                                   \
    W(19792) = 1;                                                   \
    W(17132) = 4;

void func_800D38FC(u8 *p, s32 a1)
{
    s32 v0[4];
    s32 v2[4];
    s32 v1[2];
    u8 *q;
    u8 b;
    s32 a;

    if (W(19808) != 1) {
        goto other;
    }
    {
        W(19728) -= 256;
        if (W(19728) <= 0) {
            s32 h = func_8001D4B8(D_800F1AE0, 188, 0, 1);
            func_8001D640(D_800F1AE0, h, (s32)((long long)*(s32 *)(D_800F1AE0 + 104) * 32767) >> 15);
            func_800722E8(p);
            if (W(19776) != 0) {
                W(19776)--;
                func_80083624(p, 57, W(19776), 0, 0, 0);
            } else {
                W(19816) = 1;
                W(19812) = 1;
            }
        }
        if (W(19820) == 1) {
            W(19736) -= 256;
            if (W(19736) <= 0) {
                W(19736) = F(19740) * 7680.0f;
                W(19824) = 0;
                W(19820) = 0;
                switch (B(19744)) {
                case 0: case 1: case 2: goto cA;
                case 3: case 4: case 5: goto cB;
                case 6: case 7: case 8: goto cC;
                }
            }
        }
        goto done;
    }

cA:
    if (W(19796) == 1) {
        if (H(19718) != 0) {
            SWT(19718, 2, sk1)
            AFTER
            goto done;
        } else if (H(19720) != 0) {
            SWT(19720, 1, sk2)
            AFTER
            goto done;
        } else {
            b = B(19744);
            if (H(19716) == b + 1) {
                XTAIL(0, F(19748))
                goto done;
            }
            if ((s32)(9 - b) == 7 && H(19716) >= 4) { XTAIL(0, F(19748)) }
            SWT(19716, 0, sk3)
            AFTER
            goto done;
        }
        AFTER
    } else {
        b = B(19744);
        XTAIL(0, F(19748))
    }
    goto done;

cB:
    if (W(19796) == 1) {
        if (H(19718) != 0) {
            SWT(19718, 2, sk4)
            AFTER
            goto done;
        } else if (H(19716) != 0) {
            SWT(19716, 0, sk5)
            AFTER
            goto done;
        } else {
            b = B(19744);
            if (H(19720) == b - 2) {
                XTAIL(1, F(19752))
                goto done;
            }
            SWT(19720, 1, sk6)
            AFTER
            goto done;
        }
        AFTER
    } else {
        b = B(19744);
        XTAIL(1, F(19752))
    }
    goto done;

cC:
    if (W(19796) == 1) {
        if (H(19720) != 0) {
            SWT(19720, 1, sk7)
            AFTER
            goto done;
        } else if (H(19716) != 0) {
            SWT(19716, 0, sk8)
            AFTER
            goto done;
        } else {
            b = B(19744);
            if (H(19718) == b - 5) {
                XTAIL(2, F(19756))
                goto done;
            }
            SWT(19718, 2, sk9)
            AFTER
            goto done;
        }
        AFTER
    } else {
        b = B(19744);
        XTAIL(2, F(19756))
    }
    goto done;

other:
    W(19724) -= 256;
    if (W(19724) <= 0) {
        if (W(19800) != 0) {
            goto tail;
        }
        W(3860) = 1;
        func_80072370(p);
    }

done:
    if (W(19800) == 0 && W(3860) == 1) {
        if (W(19836) == 1 && W(19796) == 1) {
            H(19716)++;
            if (H(19716) < 3) {
                W(19736) = F(19740) * 7680.0f;
                W(19728) += (s32)(F(19740) * 7680.0f);
            }
            W(19836) = 0;
            W(19820) = 1;
        }
        if (W(19828) == 1 && W(19796) == 1) {
            H(19720)++;
            if (H(19720) < 3) {
                W(19736) = F(19740) * 7680.0f;
                W(19728) += (s32)(F(19740) * 7680.0f);
            }
            W(19828) = 0;
            W(19820) = 1;
        }
        if (W(19840) == 1 && W(19796) == 1) {
            H(19718)++;
            if (H(19718) < 3) {
                W(19736) = F(19740) * 7680.0f;
                W(19728) += (s32)(F(19740) * 7680.0f);
            }
            W(19840) = 0;
            W(19820) = 1;
        }
    }
tail:
    q = p + 4552;
    if (func_800B9BD4(q, a1, v0, v1, v2, 0)) {
        W(19800) = 0;
        func_800B9FA4(q, 1, -1, 1.0f, 0, 1);
        func_800B9E9C(q, 1, -1, F(19764), 0);
        W(4644) = 0;
    }
    func_800B9964(q, v0, v1, v2);
    if (W(19812) == 1 && W(19800) == 0) {
        W(17132) = 3;
    }
}
