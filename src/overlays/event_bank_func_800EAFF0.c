typedef struct {
    float x;
    float y;
    float z;
} Vec;

typedef struct {
    char p0[64];
    Vec pos;
} Sub;

typedef struct {
    char p0[0x88BC];
    Sub cam;
} World;

typedef struct {
    int a;
    int limit;
    char p8[3];
    unsigned char next;
} Step;

typedef struct {
    char p0[4];
    World *world;
    char p8[12];
    Sub base;
    char p60[76];
    int f172;
    char pB0[250];
    unsigned char f426;
    char p1AB[205];
    int f632;
    char p27C[96];
    unsigned char f732;
    char p2DD[99];
    unsigned char f832;
    char p341[95];
    Step steps[9];
    int timer;
    unsigned char idx;
    unsigned char count;
    char p412[47];
    unsigned char f1089;
    char p442[46];
    int f1136;
    Vec v474;
    float f1152;
    Vec v484;
    Vec v490;
    Vec v49C;
} Obj;

struct Snd;

extern struct Snd D_800445F0;
extern float D_8007DC94;

extern void func_800084C0(struct Snd *s, int id, float vol);
extern void func_800B9BD4(Obj *o, int n, Vec *a, float *b, Vec *c, int z);
extern void func_800B9E9C(Obj *o, int a, int b, int c, int z);
extern void func_800B9A68(Obj *o, int v);

static inline void vput(Sub *d, Vec *s)
{
    d->pos.x = s->x;
    d->pos.y = s->y;
    d->pos.z = s->z;
}

static inline void vcopy(Vec *d, Vec *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

static inline void vget(Vec *d, Sub *s)
{
    d->x = s->pos.x;
    d->y = s->pos.y;
    d->z = s->pos.z;
}

void func_8007CB60(Obj *o)
{
    Vec a;
    Vec c;
    float b;

    if (o->base.pos.y < -3.27669978f) {
        vput(&o->world->cam, &o->base.pos);
        vcopy(&o->v49C, &o->base.pos);
        o->f1136 = 0;
        vcopy(&o->v484, &o->v490);
        o->f1152 = -(D_8007DC94 + D_8007DC94);
        vget(&o->v474, &o->base);
        o->f172 = 32;
        if (o->f832 != 0) {
            o->f832 = 0;
        }
        if (o->f426 == 1) {
            func_800084C0(&D_800445F0, o->f732, 0.9f);
        }
    }
    if (o->f1089 == 0) {
        func_800B9BD4(o, 1, &a, &b, &c, 0);
        if (o->timer > o->steps[o->idx].limit) {
            o->timer = 0;
            o->idx++;
            if (o->idx < o->count) {
                func_800B9E9C(o, o->steps[o->idx].a, -1, o->f632, 0);
                func_800B9A68(o, o->steps[o->idx].limit);
                o->f1089 = o->steps[o->idx].next;
            }
        } else {
            o->timer += 256;
        }
    }
}
