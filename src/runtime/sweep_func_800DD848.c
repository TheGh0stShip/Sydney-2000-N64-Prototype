typedef struct Link {
    short *ref;
    int id;
} Link;

typedef struct Row {
    char pad[4];
    unsigned int flags;
    char pad2[24];
} Row;

typedef struct Player {
    char pad[688];
    int slot;
} Player;

typedef struct Menu {
    char pad0[14];
    short choice;
    char pad1[16];
    Player *player;
    unsigned int flags;
    char pad2[280];
    Row rows[1];
    char pad3[228];
    unsigned int flags2;
} Menu;

typedef struct Slots {
    short ids[2];
    int valid[1];
} Slots;

typedef struct Caller {
    char pad[596];
    unsigned short index;
} Caller;

extern Menu *D_800FCC74;
extern char *D_800FC270;
extern Slots *D_800FF484;
extern Link D_800FCD8C[];
extern char D_8008B02C[];
extern char D_8008B05C[];
extern char D_8008B080[];
extern char D_800F5900[];
extern void func_800AAA60(const char *, int, const char *);
extern void func_800D53A0(void *, int);

#define NUM_SLOTS 1

void func_800DD848(Caller *caller)
{
    Menu *menu = D_800FCC74;
    int found;
    int i;
    Row *row;
    unsigned int flags;

    if (menu->player != 0) {
        char *state = D_800FC270;
        int slot;

        state += caller->index;
        slot = menu->player->slot;
        state[500] = slot;
    } else {
        func_800AAA60(D_8008B02C, 1830, D_8008B05C);
    }
    i = 0;
    found = -1;
    for (; i < NUM_SLOTS; i++) {
        D_800FCD8C[i].ref = &D_800FF484->ids[i];
        D_800FCD8C[i].id = i + 29;
        row = (Row *)((char *)menu + i * sizeof(Row)) + 10;
        flags = row->flags & ~0x80000;
        row->flags = flags;
        if (D_800FF484->valid[i] != 0) {
            if (found == -1) {
                found = i;
            }
        } else {
            row->flags = flags | 0x80000;
        }
    }
    if (found == -1) {
        func_800AAA60(D_8008B02C, 1858, D_8008B080);
    }
    menu->choice = found + 10;
    menu->flags |= 0x800000;
    menu->flags2 |= 0x800000;
    func_800D53A0(D_800F5900, 3);
}
