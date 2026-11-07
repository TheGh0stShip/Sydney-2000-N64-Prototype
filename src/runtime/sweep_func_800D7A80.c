typedef struct { char pad[184]; int judge[8]; } Ctl;
typedef struct { char pad0[20]; char body[492]; int v512; } Judge;
extern unsigned int D_800F2714;
extern Judge *func_800D7BF4(Ctl *, int, int, int, int);
extern void func_800D7D84(Ctl *);
extern void func_800AAA60(const char *, int, const char *);
extern void func_800AD58C(void *, float, float, float);
extern void func_800D8C50(Judge *, int, int);
Judge *func_800D7A80(Ctl *o, int kind, int x, float f, int arg)
{
    Judge *p;
    int r;
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    r = D_800F2714 >> 29;
    switch (kind) {
    case 0:
        p = func_800D7BF4(o, x, 0, r, 0);
        break;
    case 6:
        p = func_800D7BF4(o, x, 0, 2, 6);
        break;
    case 3:
        p = func_800D7BF4(o, x, 0, r, 3);
        break;
    case 4:
        p = func_800D7BF4(o, x, 0, r, 4);
        break;
    case 7:
        p = func_800D7BF4(o, x, 0, r, 7);
        break;
    case 1:
        func_800D7D84(o);
        return 0;
    case 5:
        return 0;
    default:
        func_800AAA60("c:/dev/olympics_2000/code/common/Bgrnd_Ctrl.cpp", 179, "Unknown JUDGETYPE passed to BGRND_CTRL::CreateJudge");
        return 0;
    }
    if (p != 0) {
        p->v512 = arg;
        if (kind != 0) func_800AD58C(p->body, f, 0.0f, 0.0f);
        func_800D8C50(p, 0, o->judge[kind]);
    }
    return p;
}
