typedef struct Entry {
    int time;
    unsigned int step;
} Entry;

typedef struct Ctx {
    char pad0[0x615];
    unsigned char kind;
    char pad616[0x62BC - 0x616];
    int base;
} Ctx;

typedef struct Obj {
    char pad0[4];
    Ctx *ctx;
    char pad8[0x27C - 8];
    unsigned char row;
    unsigned char col;
    unsigned short state;
    int next;
    char pad284[0x2DE - 0x284];
    unsigned char jitter;
    char pad2DF[0x4D4 - 0x2DF];
    unsigned short reset;
} Obj;

extern unsigned int D_800F2C14;
extern int D_800F2778;
extern Entry D_8007C1D0[];
extern Entry D_8007C380[][4];

static inline unsigned int random_below(unsigned int count)
{
    D_800F2C14 = (D_800F2C14 * 16807) & 0x7FFFFFFF;
    return ((D_800F2C14 >> 15) * count) >> 16;
}

unsigned short func_800F4B50(Obj *obj, int time)
{
    Ctx *ctx;
    Entry *e;
    int t;
    unsigned int step;

    time -= D_800F2778;
    ctx = obj->ctx;
    if (time >= 0) {
        if (ctx->kind != 2) {
            e = &D_8007C380[obj->row][obj->col];
        } else {
            e = &D_8007C1D0[obj->col];
        }
        if ((t = ctx->base, e->time + t) < time) {
            e++;
            obj->next = time;
            obj->col++;
        }
        if (time >= obj->next) {
            if (obj->state != 0) {
                obj->state ^= 3;
            } else {
                obj->state = obj->reset;
            }
            step = e->step;
            if (obj->jitter != 0) {
                step += step * random_below(obj->jitter) / 100;
            }
            obj->next += step;
        }
        return obj->state;
    }
    return 0;
}
