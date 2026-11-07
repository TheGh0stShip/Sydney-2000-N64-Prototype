typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { float x, y, z; } Vector3;
typedef struct { float values[16]; Vector3 position; } MotionTransform;
extern void func_8001C784(void);
extern void func_8001D5D8(void *, int, int, int, int, int);
extern void func_80073CF0(u8 *, int);
extern void func_800A9BE8(void *, int);
extern void func_800C013C(void *);
extern void func_8001D550(void *, int);
extern void func_800A3394(void *, int, int, int);
extern void func_800A31BC(void *);
extern void func_800A3194(void *, int);
extern void func_80073B30(u8 *);
extern void func_80072B48(u8 *);
extern void func_800B3870(void *, void *, int);
extern void func_800A3298(void *, int);
extern void func_800A3218(void *);
extern void func_800736D4(u8 *);
extern void func_80073E4C(u8 *);
extern int func_800B9BD4(void *, int, void *, void *, void *, int);
extern void func_800B9E9C(void *, int, int, float, int);
extern void func_800B9964(void *, void *, void *, void *);
extern void func_800B97D4(void *, int, void *);
extern void func_800AC5CC(void *, void *, void *, int);
extern void func_80073DB0(u8 *);
extern int func_800B8DC8(void *, void *, void *, void *, void *);
extern void *func_800AEF6C(void *, int);
extern void func_800AE72C(void *, void *, void *);
extern void func_800738A8(u8 *);
extern void func_800AD9E8(void *);
extern void func_800739E8(u8 *);
extern void func_8000F444(void);
extern void func_800ADC38(void *);
extern int func_8000EB20(char *);
extern void func_80017CF4(int, int, u16);
extern void func_800AB2A4(void *, int, int, int, u8 *, int);
extern char D_800F1AE0[];
extern char D_800F3BC0[];
extern char D_800F26E0[];
extern int D_800F2744;
#define STATE (*(u8 *)(s + 10336))
#define TIMER (*(int *)(s + 10340))
#define F192(p) (*(int *)((u8 *)(p) + 192))
static __inline__ void mident(MotionTransform *m, float one) {
    m->values[9] = 0.0f; m->values[8] = 0.0f; m->values[6] = 0.0f; m->values[4] = 0.0f; m->values[2] = 0.0f; m->values[1] = 0.0f;
    m->position.z = 0.0f; m->position.y = 0.0f; m->position.x = 0.0f;
    m->values[10] = one; m->values[5] = one; m->values[0] = one;
}
static __inline__ void setpos(MotionTransform *t, Vector3 *v) { t->position.x = v->x; t->position.y = v->y; t->position.z = v->z; }
static __inline__ void finish(u8 *s, u8 *o, MotionTransform *m) {
    func_800B97D4(o, 23, m);
    func_800AC5CC(m, s + 2784, s + 4436, 1);
}
#define FINISH() finish(s, o, &m)
static __inline__ void getpos(Vector3 *d, MotionTransform *m) { d->x = m->position.x; d->y = m->position.y; d->z = m->position.z; }
static __inline__ void setfl(u8 *q, u8 a) { q[185] = a; q[184] = 1; q[186] = 0; q[187] = 0; }
void func_800746C0(u8 *s) {
    float a[4];
    float b[4];
    MotionTransform m;
    float c[2];
    u8 *o;
    u8 *q;
    u8 *p;
    u8 *e;
    u8 *x;
    u8 *y;
    u8 flag;
    int r;
    func_8001C784();
    switch (STATE) {
    case 0:
        if ((TIMER -= 256) >= 0) return;
        r = *(int *)(s + 10344);
        TIMER = 0x2EE00;
        STATE = 1;
        func_8001D5D8(D_800F1AE0, r, 0, 120, 1, 0);
        func_80073CF0(s, 0);
        break;
    case 1:
        if ((TIMER -= 256) >= 0) return;
        TIMER = 0x41A00;
        STATE = 2;
        mident((MotionTransform *)(s + 3188), 1.0f);
        setfl(s + 3168, 1);
        func_800A9BE8(s + 4660, 0);
        func_800C013C(D_800F3BC0);
        func_8001D550(D_800F1AE0, 1);
        func_800A3394(D_800F1AE0, 9830, -1, -1);
        func_800A31BC(D_800F1AE0);
        break;
    case 2:
        if ((TIMER -= 256) < 0) {
            func_800A3194(D_800F1AE0, 300);
            func_800A3394(D_800F1AE0, 32767, -1, -1);
            func_80073B30(s);
        } else {
            func_80072B48(s);
        }
        break;
    case 3:
        *(float *)(s + 1424) += 0.5461166501045227f;
        p = s + 500;
        func_800B3870(*(u8 **)(p + 268) + 96, s + 1356, 76);
        func_800B3870(s + 3188, *(u8 **)(p + 268) + 20, 76);
        if ((TIMER -= 256) >= 0) return;
        TIMER = 0x12C00;
        STATE = 4;
        func_80073CF0(s, 1);
        break;
    case 4:
        if ((TIMER -= 256) >= 0) return;
        func_800C013C(D_800F3BC0);
        func_800A3298(D_800F1AE0, 6);
        func_8001D550(D_800F1AE0, 1);
        func_800A3218(D_800F1AE0);
        func_800A3394(D_800F1AE0, 32767, 32767, 32767);
        func_800A3394(D_800F1AE0, 9830, -1, -1);
        func_800A31BC(D_800F1AE0);
        setfl(s + 3168, 0);
        func_800736D4(s);
        func_80073E4C(s);
        break;
    case 5:
        o = s + 2764;
        if (func_800B9BD4(o, 1, a, c, b, 0)) func_800B9E9C(o, 0, -1, 1.0f, 0);
        func_800B9964(o, a, c, b);
        FINISH();
        if ((TIMER -= 256) >= 0) return;
        func_80073DB0(s);
        break;
    case 6:
        o = s + 2764;
        TIMER -= 256;
        if (func_800B9BD4(o, 1, a, c, b, 0)) func_800B9E9C(o, 0, -1, 1.0f, 0);
        e = s + 1804;
        if (func_800B8DC8(o, e, a, c, b)) func_800AE72C(e, o, func_800AEF6C(s + 4628, 0));
        FINISH();
        if (TIMER >= 0) return;
        func_800738A8(s);
        break;
    case 7:
        flag = 0;
        o = s + 2764;
        if (func_800B9BD4(o, 1, a, c, b, 0)) {
            func_800B9E9C(o, 2, -1, 1.0f, 0);
            flag = 1;
        }
        func_800B9964(o, a, c, b);
        if (flag) {
            getpos((Vector3 *)(s + 4288), (MotionTransform *)(s + 2784));
            *(float *)(s + 4292) -= 36.043697357177734f;
            func_800AD9E8(s + 4204);
        }
        FINISH();
        if ((TIMER -= 256) >= 0) return;
        func_800739E8(s);
        break;
    case 8:
        o = s + 2764;
        TIMER -= 256;
        if (func_800B9BD4(o, 1, a, c, b, 0)) func_800B9E9C(o, 2, -1, 1.0f, 0);
        func_800B9964(o, a, c, b);
        FINISH();
        if (TIMER >= 0) return;
        func_8000F444();
        x = s + 3780;
        y = s + 3992;
        F192(x) |= 0x20;
        F192(y) |= 0x20;
        func_800ADC38(x);
        func_800ADC38(y);
        r = func_8000EB20("FIRE_PROC");
        func_80017CF4(*(int *)(s + 264), 0, r);
        STATE = 9;
        TIMER = 15360;
        break;
    case 9:
        o = s + 2764;
        TIMER -= 256;
        if (func_800B9BD4(o, 1, a, c, b, 0)) func_800B9E9C(o, 2, -1, 1.0f, 0);
        func_800B9964(o, a, c, b);
        FINISH();
        if (TIMER >= 0) return;
        STATE = 10;
        TIMER = 0x12C00;
        func_800A3194(D_800F1AE0, 300);
        func_800A3394(D_800F1AE0, 32767, -1, -1);
        func_800A9BE8(s + 4660, 5);
        break;
    case 10:
        o = s + 2764;
        TIMER -= 256;
        FINISH();
        if (TIMER >= 0) return;
    default:
        func_800AB2A4(D_800F26E0, D_800F2744, 7, (int)s, 0, 0);
        break;
    }
}
