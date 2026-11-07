typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef struct Slot { char pad[8]; s8 b8; char pad9[3]; } Slot;
typedef struct Glob { char pad[2572]; u8 count; char padA0D[3]; Slot slots[1]; } Glob;
typedef struct E { char pad[2]; u16 h2; u8 b4; char pad5[28 - 5]; } E;
typedef struct Obj {
    char pad[30120];
    s8 idx;
    u8 unk75A9;
    char pad75AA;
    u8 st;
    char pad75AC[30204 - 30124];
    E *ents;
} Obj;
extern Glob *D_800FC270;
extern char D_800F26E0[];
extern int D_800F2744;
extern void func_800AB2A4(void *, int, int, Obj *, int, int);
void func_800760D4(Obj *o)
{
    unsigned int cnt;
    unsigned int i;
    int c;
    if (o->st == 4) {
        func_800AB2A4(D_800F26E0, D_800F2744, 24, o, 0, 0);
    } else {
        o->unk75A9 = 20;
    }
    o->ents[o->idx].h2--;
    cnt = 0;
    if (o->st == 3 || o->st == 4) {
        c = 0;
    } else {
        for (i = 0; i < D_800FC270->count; i++) {
            if (o->ents[i].b4 < 3) {
                cnt++;
            }
        }
        c = cnt == 1 && D_800FC270->slots[o->idx].b8 == 0;
    }
    if (c) {
        o->ents[o->idx].b4 = 3;
    }
}
