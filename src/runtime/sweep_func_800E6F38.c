typedef struct {
    unsigned char kind;
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
} Pat;

typedef struct {
    unsigned char cells[9][5];
} Grid;

typedef struct {
    char p0[408];
    Grid grid;
} Board;

typedef struct {
    int pad;
    Board *boards[4];
} Game;

typedef struct {
    char p0[24];
    unsigned short who;
    short pad;
    int score;
    int bonus;
} Player;

extern Pat D_80103500;

void func_800E7460(Game *g, unsigned char base, unsigned char w, unsigned char h);
short func_800E7180(Game *g, Player *p, Grid *grid, Pat *pat);

void func_800E6F38(Game *g, Player *p)
{
    unsigned char k = 0;
    Grid *grid = &g->boards[p->who]->grid;

    p->score = 0;
    func_800E7460(g, 0, 9, 5);
    if (!func_800E7180(g, p, grid, &D_80103500)) {
        k = 36;
        p->score += 8;
    }
    func_800E7460(g, k, 5, 5);
    if (!func_800E7180(g, p, grid, &D_80103500)) {
        k += 4;
        p->score += 2;
    }
    func_800E7460(g, k, 5, 3);
    if (!func_800E7180(g, p, grid, &D_80103500)) {
        k += 18;
        p->score += 4;
    }
    func_800E7460(g, k, 3, 3);
    if (!func_800E7180(g, p, grid, &D_80103500)) {
        k += 2;
        p->score += 1;
    }
    func_800E7460(g, k, 3, 2);
    if (!func_800E7180(g, p, grid, &D_80103500)) k += 9;
    func_800E7460(g, k, 2, 2);
    if (!func_800E7180(g, p, grid, &D_80103500)) k += 1;
    p->bonus = (k - k / 9) * 2;
    D_80103500.kind = 4;
    D_80103500.a = k;
    D_80103500.b = k + 1;
    D_80103500.c = k + 9;
    D_80103500.d = k;
    if (!func_800E7180(g, p, grid, &D_80103500)) p->bonus++;
}
