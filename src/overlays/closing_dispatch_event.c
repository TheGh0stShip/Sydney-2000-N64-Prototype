typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int type; int value; int pad8; int padC; int flag; } Msg;
extern void func_800B4794(int);
extern void func_80070E38(u8 *);
extern void func_80071BC0(u8 *);
extern void func_800BC07C(u8 *, int);
extern void func_80071834(u8 *);
extern void func_800AB2A4(void *, int, int, int, u8 *, int);
extern void func_800725F8(u8 *, void *, int);
extern void func_800A9B78(void *, void *, int, int, int);
extern char D_800F26E0[];
extern int D_800F2744;
extern u32 D_800F2714;
static __inline__ u32 rnd(u32 n) { D_800F2714 = D_800F2714 * 16807 & 0x7FFFFFFF; return ((D_800F2714 >> 15) * n) >> 16; }
void func_80070C94(u8 *o, Msg *m) {
    u8 *p;
    switch (m->type) {
    case 3:
        func_800B4794(1);
        func_80070E38(o);
        func_800B4794(0);
        break;
    case 5:
        if (*(int *)(o + 228) == 0) break;
        func_80071BC0(o);
        break;
    case 1:
    case 2:
        p = o + 1076;
        func_800BC07C(p, ((u8 *)m)[17]);
        if (p[3] == 0) break;
    case 7: {
        int w;
        func_80071834(o);
        w = *(int *)(o + 4);
        func_800AB2A4(D_800F26E0, D_800F2744, 20, w, o, 15);
        break;
    }
    case 11:
        switch (m->flag) {
        case 0:
            break;
        case 1: case 2: case 3: case 4: case 5:
            func_800725F8(o, *(void **)((rnd(10) << 2) + o + 1124), 1);
            break;
        case 8:
            func_800A9B78(o + 2476, o + 1964, 1, 1, 2);
            break;
        case 12:
            break;
        }
        break;
    }
    *(int *)(o + 16) = m->value;
}
