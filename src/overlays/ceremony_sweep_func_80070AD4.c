typedef unsigned char u8;
typedef struct { int type; int value; int pad8; int padC; int flag; } Msg;
extern void func_800B4794(int);
extern void func_80008570(int, int, int, int);
extern void func_80070A1C(u8 *);
extern void func_800715B4(u8 *);
extern void func_800BC07C(u8 *, int);
extern void func_80071078(u8 *);
extern void func_800AB2A4(void *, int, int, int, u8 *, int);
extern char D_800F26E0[];
extern int D_800F2744;
void func_80070AD4(u8 *o, Msg *m) {
    u8 *p;
    switch (m->type) {
    case 3:
        func_800B4794(1);
        if (m->flag == 0) func_80008570(0, 0, 0, 0);
        func_80070A1C(o);
        func_800B4794(0);
        break;
    case 5:
        if (*(int *)(o + 268) == 0) break;
        func_800715B4(o);
        break;
    case 1:
    case 2:
        p = o + 272;
        func_800BC07C(p, ((u8 *)m)[17]);
        if (p[3] == 0) break;
    case 7:
        func_80071078(o);
        { int w = *(int *)(o + 4); func_800AB2A4(D_800F26E0, D_800F2744, 20, w, o, 15); }
        break;
    }
    *(int *)(o + 16) = m->value;
}
