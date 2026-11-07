typedef unsigned char u8;
extern void func_800725C0(u8 *, int);
extern void func_800A9BE8(void *, int);
extern void func_800A3394(void *, int, int, int);
extern void func_800A31BC(void *);
extern void func_800A3194(void *, int);
extern void func_800A3240(void *);
extern void func_800A3298(void *, int);
extern void func_8001D550(void *, int);
extern void func_80071954(u8 *);
extern void func_80072178(u8 *);
extern void func_800ADC38(void *);
extern void func_800A851C(void *, int, void *, void *);
extern int func_800B9BD4(void *, int, void *, void *, void *, int);
extern void func_800B9E9C(void *, int, int, float, int);
extern void func_800B9964(void *, void *, void *, void *);
extern void func_80071AAC(u8 *);
extern void func_800AC334(void *);
extern void func_800B3870(void *, void *, int);
extern void func_800C013C(void *);
extern void func_800AB2A4(void *, int, int, int, u8 *, int);
extern char D_800F1AE0[];
extern char D_800F3BC0[];
extern char D_800F26E0[];
extern int D_800F2744;
#define STATE (*(u8 *)(s + 9052))
#define TIMER (*(int *)(s + 9056))
typedef struct { u8 pad[1124]; u8 *a[10]; u8 *b[10]; } Scene;
#define MEDAL(n) (((Scene *)s)->a[n])
#define ANIM() \
    for (i = 0; (u8)i < 10; i++) { \
        if (func_800B9BD4(MEDAL((u8)i), 1, a, c, b, 0)) func_800B9E9C(MEDAL((u8)i), 10, -1, 1.0f, 0); \
        func_800B9964(MEDAL((u8)i), a, c, b); \
    } \
    func_80071AAC(s)
void func_80071BC4(u8 *s) {
    float a[4];
    float b[4];
    float c[2];
    int i;
    u8 *p;
    u8 *q;
    switch (STATE) {
    case 0:
        if ((TIMER -= 256) >= 0) return;
        TIMER = 0x2EE00;
        STATE = 1;
        func_800725C0(s, 0);
        break;
    case 1:
        if ((TIMER -= 256) >= 0) return;
        TIMER = 0x38400;
        STATE = 2;
        func_800A9BE8(s + 2476, 0);
        func_800A3394(D_800F1AE0, 9830, -1, -1);
        func_800A31BC(D_800F1AE0);
        break;
    case 2:
        func_80071954(s);
        if ((TIMER -= 256) >= 0) return;
        func_80072178(s);
        func_800ADC38(s + 2156);
        func_800A851C(s + 232, 10, s + 2156, s + 2368);
        func_800A3194(D_800F1AE0, 150);
        func_800A3394(D_800F1AE0, 32767, -1, -1);
        TIMER = 0x9600;
        STATE = 4;
        func_800A9BE8(s + 2476, 1);
        break;
    case 4:
        ANIM();
        if ((TIMER -= 256) >= 0) return;
        STATE = 3;
        func_800725C0(s, 1);
        TIMER = 0x12C00;
        STATE = 3;
        break;
    case 3:
        ANIM();
        if ((TIMER -= 256) >= 0) return;
        STATE = 5;
        TIMER = 0x25800;
        func_800AC334(s + 1964);
        func_800B3870(s + 1984, s + 2368, 76);
        func_800C013C(D_800F3BC0);
        func_8001D550(D_800F1AE0, 1);
        func_800A3240(D_800F1AE0);
        func_800A3298(D_800F1AE0, 6);
        func_800A3394(D_800F1AE0, 32767, 32767, 32767);
        func_800A3394(D_800F1AE0, 9830, -1, -1);
        func_800A31BC(D_800F1AE0);
        func_800A9BE8(s + 2476, 4);
        break;
    case 5:
        ANIM();
        *(float *)(s + 2436) += -0.6662623286247253f;
        p = s + 272;
        func_800B3870(*(u8 **)(p + 268) + 96, s + 2368, 76);
        func_800B3870(s + 1984, *(u8 **)(p + 268) + 20, 76);
        if ((TIMER -= 256) >= 0) return;
        STATE = 6;
        func_800A9BE8(s + 2476, 3);
        *(int *)(s + 8644) = 0;
        func_800A3394(D_800F1AE0, 32767, 13106, 32767);
        i = 0;
        while (1) {
            u8 n = i;
            if (n >= 10) break;
            *(int *)(MEDAL(n) + 192) |= 4;
            *(int *)(((Scene *)s)->b[n] + 192) |= 4;
            i++;
        }
        return;
    case 6:
        ANIM();
        q = s + 8152;
        if (*(int *)(q + 492) != *(int *)(q + 496)) return;
        STATE = 7;
        TIMER = 0x9600;
        func_800A3194(D_800F1AE0, 150);
        func_800A3394(D_800F1AE0, 32767, -1, -1);
        break;
    case 7:
        if ((TIMER -= 256) >= 0) return;
    default:
        func_800AB2A4(D_800F26E0, D_800F2744, 7, (int)s, 0, 0);
        break;
    }
}
