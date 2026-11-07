typedef struct { int heap; int a; int b; int wp; unsigned short cap; unsigned short used; } Pool;
typedef struct { char pad[232]; } Lane;
typedef struct {
    char pad0[0xD8];
    char snd[0x104 - 0xD8];
    char hud[0x284 - 0x104];
    int live;
    char pad288[0x5B48 - 0x288];
    char board[0x6038 - 0x5B48];
    Lane lanes[13];
    char pad[0x6CE4 - (0x6038 + 13 * 232)];
    char c0[0x6DC0 - 0x6CE4];
    char c1[0x6E9C - 0x6DC0];
    char c2[0x6F7C - 0x6E9C];
    char chan[4];
} Game;

extern char D_800F1AE0[];
extern char D_800F3BC0[];
extern Pool D_800F2690;
extern Pool D_800FCB90;
extern char D_800F5900[];
extern void func_800A32CC(void *p);
extern void func_800A3218(void *p);
extern void func_800A3240(void *p);
extern void func_800AC334(void *p);
extern void func_800C0168(void *p);
extern void func_800B35F0(void *p);
extern void func_800CE594(void);
extern void func_800AA658(int h, int *p);
extern void func_800DB124(int n);
extern void func_800C8500(void *p);
extern void func_800C04DC(void *p);
extern void func_800C0A5C(Lane *l);
extern void func_800D5760(char *p);
extern void func_80006A18(void *p);
extern void func_800137FC(void);
extern void func_80014384(void);
extern void func_800DAFBC(void);
extern void func_800E9794(Game *g);
extern void func_800B31D0(void);

static inline void pool_free(Pool *p)
{
    int h = p->heap;

    if (h != 0) {
        p->heap = 0;
        if (p->a != 0) {
            func_800AA658(h, &p->a);
        }
        if (p->b != 0) {
            func_800AA658(h, &p->b);
        }
        p->cap = 0;
        p->used = 0;
        p->wp = 0;
        p->heap = 0;
    }
}

void func_800E8EB4(Game *g)
{
    unsigned short i;

    func_800A32CC(D_800F1AE0);
    func_800A3218(D_800F1AE0);
    func_800A3240(D_800F1AE0);
    func_800AC334(D_800F3BC0);
    func_800C0168(D_800F3BC0);
    if (g->live == 0) {
        return;
    }
    func_800AC334(g->c0);
    func_800B35F0(g->c0);
    func_800AC334(g->c1);
    func_800B35F0(g->c1);
    func_800AC334(g->c2);
    func_800B35F0(g->c2);
    func_800CE594();
    pool_free(&D_800F2690);
    pool_free(&D_800FCB90);
    func_800DB124(1);
    func_800AC334(g->hud);
    func_800C8500(g->chan);
    func_800C04DC(g->board);
    func_800AC334(g->board);
    i = 0;
    do {
        func_800C0A5C(&g->lanes[i]);
        i++;
    } while (i < 13);
    func_800D5760(D_800F5900);
    func_80006A18(g->snd);
    func_800137FC();
    func_80014384();
    func_800DAFBC();
    func_800E9794(g);
    g->live = 0;
    func_800B31D0();
}
