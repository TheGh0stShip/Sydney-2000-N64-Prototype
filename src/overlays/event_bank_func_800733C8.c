typedef struct Mtx34 {
    float m[3][4];
} Mtx34;

typedef struct Transform {
    char pad0[20];
    Mtx34 rot;
} Transform;

typedef struct Source {
    char pad0[84];
    float pos[3];
} Source;

typedef struct SubObj {
    char pad0[4];
    int active;
} SubObj;

typedef struct EventBankObj {
    char pad0[4004];
    char sub4004[260];
    SubObj sub4264;
    char pad4272[12];
    Mtx34 rot;
    char pad4332[16];
    float pos[3];
} EventBankObj;

extern void func_800AC334(SubObj *);
extern void func_800AC37C(SubObj *, Source *);
extern void func_800A9B78(void *, SubObj *, int, int, int);

void func_800733C8(EventBankObj *obj, Source *src, Transform *xf, int arg3)
{
    Mtx34 *m = &xf->rot;
    Mtx34 *d;
    float *sp;
    float *dp;
    SubObj *sub;

    d = &obj->rot;

    d->m[0][0] = m->m[0][0];
    d->m[1][0] = m->m[1][0];
    d->m[2][0] = m->m[2][0];
    d->m[0][1] = m->m[0][1];
    d->m[1][1] = m->m[1][1];
    d->m[2][1] = m->m[2][1];
    d->m[0][2] = m->m[0][2];
    d->m[1][2] = m->m[1][2];
    d->m[2][2] = m->m[2][2];
    sp = src->pos;
    dp = obj->pos;
    dp[0] = sp[0];
    dp[1] = sp[1];
    dp[2] = sp[2];

    sub = &obj->sub4264;
    if (sub->active) {
        func_800AC334(sub);
    }
    func_800AC37C(sub, src);
    func_800A9B78(obj->sub4004, sub, 1, arg3, 2);
}
