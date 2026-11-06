typedef struct VEntry { short delta; short pad; void (*fn)(void *, int); } VEntry;
typedef struct Elem { unsigned char b[212]; } Elem;
typedef struct VTable { int pad0; int pad4; VEntry e; } VTable;

extern unsigned char D_800F2758[];
extern unsigned char D_800F2AD8[];
extern void func_80015EAC(int);
extern void func_800177AC(void);
extern void func_8007229C(void *, int, int);
extern void func_80071E44(void *);
extern void func_800BBD78(void *, int, int, void *, int);
extern void func_800AA658(void *, void *);
extern void func_800828B4(void *, int);
extern void func_80083700(void *, int);
extern void func_80083A0C(void *);
extern void func_800BC07C(void *, int);
extern void func_800BB764(void *, int);

#define W(p, o) (*(int *)((unsigned char *)(p) + (o)))
#define P(p, o) (*(unsigned char **)((unsigned char *)(p) + (o)))

#define KILL_LIST(off)                                            \
    if (W(o, off) != 0) {                                         \
        for (i = 0; i < 14; i++) {                                \
            unsigned char *e = (unsigned char *)(i * 212 + W(o, off));               \
            VTable *vt = *(VTable **)(e + 180);                   \
            vt->e.fn(e + vt->e.delta, 2);                         \
        }                                                         \
        func_800AA658(D_800F2758, o + off);                       \
    }

void func_800BB470(unsigned char *o, int *m)
{
    int dt = (m[1] - W(o, 16)) >> 8;
    int v;
    unsigned int i;
    unsigned char *b;
    unsigned char *g;

    switch (m[0]) {
    case 3:
        func_80015EAC(12);
        g = *(unsigned char **)0x800FC270;
        func_8007229C(o, g[0xd1b], g[0xd1f]);
        func_80071E44(o);
        func_800177AC();
        break;
    case 7:
        switch ((unsigned int)m[4]) {
        case 8:
        case 15:
            func_800BBD78(D_800F2AD8, 12, 1, o, 0);
            break;
        case 7:
        case 57:
            func_800AA658(D_800F2758, o + 0x42e8);
            func_800828B4(o, m[4]);
            KILL_LIST(0x4350)
            KILL_LIST(0x4348)
            KILL_LIST(0x4340)
            break;
        }
        break;
    case 1:
        func_80083700(o, m[4]);
        break;
    case 2:
        v = W(o, 0x42ec);
        b = (unsigned char *)&m[4];
        if ((unsigned)(v - 9) < 2 || v == 3) {
            func_800BC07C(P(o, 0xf1c), b[1]);
            if (P(o, 0xf1c)[3] & 0x10) W(o, 0x44c0) = 1;
            if (P(o, 0xf1c)[2] & 0x10) W(o, 0x44c0) = 0;
            func_800BB764(o, dt);
        } else {
        func_800BC07C(P(o, 0xf1c), b[1]);
        if (P(o, 0xf1c)[3]) W(o, 0xf14) = 1;
        func_800BB764(o, dt);
        }
        break;
    case 12:
        break;
    case 5:
        func_80083A0C(o);
        func_800BB764(o, dt);
        break;
    }
    W(o, 16) = m[1];
}
