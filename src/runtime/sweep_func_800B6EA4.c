typedef struct { int a; int b; int c; int d; } Slot;
typedef struct { Slot slots[6]; } Team;
typedef struct { char pad[0xE0C]; Team teams[1]; } Game;
typedef struct { int id; Slot *slot; int h; int d; int c; } Entry;

extern char D_800F2790[];
extern char D_800F5900[];
extern char D_800F2AD8[];
extern short D_800FD8F4;
extern int D_800FCE8C;
extern Entry D_800FCE94[];
extern Game *D_800FC270;
extern void func_800B3178(char *p, int n);
extern int func_800D98FC(int n);
extern void func_800D53A0(char *p, int n);
extern void func_800BC180(char *p);
extern void func_800BBD78(char *p, int a, int b, int c, int d);

void func_800B6EA4(int who, int team)
{
    unsigned char i;
    Entry *e;

    func_800B3178(D_800F2790, 5);
    D_800FD8F4 = 9;
    D_800FCE8C = func_800D98FC(250);
    for (i = 0; i < 6; i++) {
        e = &D_800FCE94[i];
        e->id = i + 1;
        e->slot = &D_800FC270->teams[team].slots[i];
        e->h = func_800D98FC(89);
        e->d = (D_800FC270->teams[team].slots + i)->d;
        e->c = D_800FC270->teams[team].slots[i].c;
    }
    func_800D53A0(D_800F5900, 6);
    func_800BC180(D_800F2AD8);
    func_800BBD78(D_800F2AD8, 12, 1, who, 2);
    func_800BBD78(D_800F2AD8, 13, 1, who, 2);
    func_800BBD78(D_800F2AD8, 13, 0, 0, 2);
}
