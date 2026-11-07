typedef struct { char pad[8]; int mode; char padc[3410 - 0xC]; unsigned char flags; } Cfg;
typedef struct { short id; } Cue;
typedef struct {
    char pad0[0x27C];
    int mode;
    char pad280[0x288 - 0x280];
    char intro[840 - 0x288];
    char menu[3412 - 840];
    char opts[22520 - 3412];
    char race[22708 - 22520];
    char res[4];
} Game;

extern Cfg *D_800FC270;
extern short *D_800FF484;
extern short D_800FF54C[];
extern Cue D_800FF488;
extern void func_800E9A2C(Game *g, int f, int n);
extern void func_800B31EC(int n);
extern void func_800E9B18(Game *g, void *scr);
extern void func_800E9974(Game *g, int n);
extern void func_800AC030(void *scr, Game *g);
extern void func_800B3178(Cue *c, int n);
extern void func_800DE4B8(void *scr, int n, Game *g);
extern void func_800DF11C(void *scr, int n, Game *g);
extern void func_800E4E98(void *scr, int n, Game *g);
extern void func_800B7048(void *scr);
extern void func_800B6C58(void *scr, int n, Game *g);
extern void func_800E9A48(Game *g, int n);

void func_800E90AC(Game *g, unsigned short mode)
{
    D_800FC270->mode = mode;
    g->mode = mode;
    func_800E9A2C(g, 1024, 1);
    D_800FF484 = D_800FF54C;
    switch (mode) {
    case 0:
        func_800B31EC(3);
        func_800E9B18(g, g->intro);
        func_800E9974(g, 89);
        func_800AC030(g->intro, g);
        func_800B3178(&D_800FF488, 1);
        func_800E9A48(g, 0);
        break;
    case 1:
        func_800E9B18(g, g->menu);
        func_800DE4B8(g->menu, 1, g);
        func_800E9974(g, 1);
        func_800E9A48(g, 0);
        break;
    case 2:
        func_800E9B18(g, g->menu);
        func_800DE4B8(g->menu, 2, g);
        func_800E9974(g, 3);
        func_800E9A48(g, 0);
        break;
    case 3:
        func_800E9B18(g, g->opts);
        func_800DF11C(g->opts, 3, g);
        func_800E9974(g, 2);
        func_800E9A48(g, 1);
        break;
    case 4:
        func_800E9B18(g, g->race);
        func_800E4E98(g->race, 4, g);
        func_800E9974(g, 4);
        func_800E9A48(g, 0);
        break;
    case 5:
        func_800E9B18(g, g->res);
        func_800B7048(g->res);
        D_800FC270->flags &= 0xFC;
        func_800B6C58(g->res, 5, g);
        func_800E9A48(g, 0);
        break;
    }
}
