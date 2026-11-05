typedef struct Player {
    char pad0[426];
    unsigned char state;
    char pad1AB[736 - 427];
    int active;
} Player;

extern void func_800831A8(Player *p);
extern void func_8008382C(Player *p);

void func_80079328(char *self)
{
    unsigned char mode = self[1556];
    Player *p;
    int ok;

    if (mode != 2 && mode != 5) {
        p = (Player *)(self + 1584);
        if (p->active) {
            func_800831A8(p);
        }
        p = (Player *)(self + 28608);
        ok = 0;
        if (p->active) {
            ok = p->state != 4;
        }
        if (ok) {
            func_800831A8(p);
        }
    } else {
        p = (Player *)(self + 1584);
        if (p->active) {
            func_8008382C(p);
        }
        p = (Player *)(self + 28608);
        ok = 0;
        if (p->active) {
            ok = p->state != 4;
        }
        if (ok) {
            func_8008382C(p);
        }
    }
}
