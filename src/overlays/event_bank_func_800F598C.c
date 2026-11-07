typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    char pad0[0xA00];
    s32 mode;
    s32 sub;
    char padA08[0xD10 - 0xA08];
    s32 limit;
} Game;

typedef struct {
    char pad0[0x1AA];
    u8 side;
    char pad1AB[0x4C8 - 0x1AB];
    s32 score;
    u8 level;
    u8 flag;
} Actor;

extern Game *D_800FC270;
extern u32 D_800F13F0;
extern void func_8007BB94(Actor *, s32);
extern void func_8007B910(Actor *);
extern void func_8007B7F0(Actor *);

static inline u32 rnd(u32 n)
{
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    return ((D_800F13F0 >> 15) * n) >> 16;
}

void func_8007B40C(Actor *a)
{
    Game *g;
    u32 thr;
    s32 hit;

    a->flag = 0;
    g = D_800FC270;
    if (g->mode == 5) {
        if (a->level == 0) {
            func_8007BB94(a, 1);
            return;
        }
        thr = 25;
        if (a->side != 1) thr = 75;
        if (thr < rnd(100)) {
            func_8007B910(a);
            return;
        }
    } else if (g->mode == 4) {
        if (a->level == 0) {
            if (a->side == 1 && g->sub == 5) {
                func_8007BB94(a, 2);
                return;
            }
            func_8007BB94(a, 1);
            return;
        }
        if (a->level >= 4) {
            hit = 0;
            if (a->side == 1 || rnd(100) < 26) {
                hit = 1;
            }
            if (hit) {
                func_8007B910(a);
                return;
            }
        }
    } else if (g->mode != 6) {
        if (a->score <= g->limit) {
            if (a->level == 0) {
                func_8007BB94(a, 2);
                return;
            }
            if (a->level >= 4) {
                func_8007B910(a);
                return;
            }
        } else {
            if (a->side == 1) {
                func_8007B910(a);
                return;
            }
        }
    }
    func_8007B7F0(a);
}
