typedef struct Entry {
    int unk0;
    unsigned int step;
} Entry;

typedef struct Game {
    char pad0[0xD53];
    unsigned char mode;
} Game;

typedef struct Ctx {
    char pad0[0x8054];
    unsigned char kind;
} Ctx;

typedef struct Obj {
    char pad0[4];
    Ctx *ctx;
    char pad8[0x27E - 8];
    unsigned short state;
    int next;
    char pad284[0x2DD - 0x284];
    unsigned char jitter;
} Obj;

extern unsigned int D_800F2C14;
extern int D_800F2778;
extern Game *D_800FC270;
extern Entry D_8007B8FC[];

static inline unsigned int random_below(unsigned int count)
{
    D_800F2C14 = (D_800F2C14 * 16807) & 0x7FFFFFFF;
    return ((D_800F2C14 >> 15) * count) >> 16;
}

unsigned short func_800F9758(Obj *obj, int time)
{
    Entry *e;
    unsigned int step;

    time -= D_800F2778;
    if (obj->ctx->kind == 2) {
        e = &D_8007B8FC[2];
    } else {
        e = &D_8007B8FC[D_800FC270->mode];
    }
    if (time >= obj->next) {
        if (obj->state & 1) {
            obj->state = 2;
        } else {
            obj->state = 1;
        }
        step = e->step;
        if (obj->jitter != 0) {
            step += step * random_below(obj->jitter) / 100;
        }
        obj->next += step;
    }
    return obj->state;
}
