typedef unsigned char u8;
typedef struct { float x, y, z; } Vec;
typedef struct { char pad[84]; Vec vel; } Body;
typedef struct { char pad[76]; } Rec;
typedef struct { char pad[232]; char cam[1124 - 232]; void *a[10]; char pad2[1204 - 1164]; Rec rec[10]; char pad3[2444 - 1964]; char pool[4]; } Scene;
extern int func_800B9BD4(void *, int, void *, void *, void *, int);
extern void func_800B9E9C(void *, int, int, float, int);
extern int func_800B8DC8(void *, Rec *, void *, void *, void *);
extern void *func_800AEF6C(void *, int);
extern void func_800AE72C(Rec *, void *, void *);
extern void func_80071AAC(Scene *);
extern void func_800A7A64(void *, Vec *);
static __inline__ void vsub(Vec *o, Vec *a, Vec *b) { o->x = a->x - b->x; o->y = a->y - b->y; o->z = a->z - b->z; }
void func_80071958(Scene *s) {
    float a[4];
    float b[4];
    Vec d;
    int c[2];
    int i;
    i = 0;
    do {
        u8 n = i;
        Rec *r;
        if (func_800B9BD4(s->a[n], 1, a, c, b, 0)) func_800B9E9C(s->a[n], 9, -1, 1.0f, 0);
        r = &s->rec[n];
        if (func_800B8DC8(s->a[n], r, a, c, b)) {
            void *h = func_800AEF6C(s->pool, 0);
            func_800AE72C(r, s->a[n], h);
        }
        i++;
    } while ((u8)i < 10);
    func_80071AAC(s);
    vsub(&d, &((Body *)s->a[0])->vel, &((Body *)s->a[1])->vel);
    func_800A7A64(s->cam, &d);
}
