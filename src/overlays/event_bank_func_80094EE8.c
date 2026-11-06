typedef struct Rec { char pad[0x10]; int limit; int last; char pad18[4]; } Rec;
typedef struct Obj {
    char pad[0x73F4]; int value; char pad73f8[0x75A8 - 0x73F8];
    signed char idx; char pad75a9[0x75FC - 0x75A9]; Rec *recs;
} Obj;
typedef struct Glob {
    char pad[0x9FC]; int mode9fc; int modeA00; int modeA04;
    char padA08[0xD10 - 0xA08]; float thresh;
} Glob;
extern Glob *D_800FC270;
extern unsigned int D_800F2C14;

static inline unsigned int rnd(unsigned int n)
{
    D_800F2C14 = (D_800F2C14 * 16807) & 0x7FFFFFFF;
    return ((D_800F2C14 >> 15) * n) >> 16;
}

int func_80094EE8(Obj *o)
{
    int r = 0;
    int d;
    int c;

    if (o->recs[o->idx].last == o->value) {
        return 1;
    }
    if (D_800FC270->modeA00 == 4 && D_800FC270->modeA04 == 1 &&
        D_800FC270->thresh <= (float)o->value / *(float *)0x800713F0) {
        return 0;
    }
    if (D_800FC270->mode9fc == 1) {
        return 0;
    }
    if (o->value > o->recs[o->idx].limit) goto end;
    d = (o->recs[o->idx].limit - o->value) / 3;
        if (d == 0) {
            if (rnd(100) < 5) r = 1;
        } else if (d == 1) {
            if (rnd(100) < 10) r = 1;
        } else if (d == 2) {
            if (rnd(100) < 35) r = 1;
        } else if (d == 3) {
            if (rnd(100) < 50) r = 1;
        } else {
            if (rnd(100) < 75) r = 1;
        }
    if (r) {
        o->recs[o->idx].last = o->value;
    }
end:
    return r;
}
