typedef unsigned char u8;
typedef signed char s8;
typedef struct Slot { s8 type; u8 b1; char pad2[6]; s8 b8; char pad9[3]; } Slot;
typedef struct Ent { char pad[32]; u8 kind; char pad21[60 - 33]; } Ent;
typedef struct Glob { Ent ents[42]; char padA08[2572 - 42 * 60]; u8 count; char padA0D[3]; Slot slots[1]; } Glob;
typedef struct Obj { char pad[35997]; u8 st; } Obj;
extern Glob *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *, int, int, int);
void func_80076E24(Obj *o)
{
    if (o->st < 2) {
        Slot *s = D_800FC270->slots;
        unsigned int i;
        u8 k;
        int id;
        short base;
        for (i = 0; i < D_800FC270->count; i++) {
            if (s[i].b8 == 0) {
                break;
            }
        }
        if (i == D_800FC270->count) {
            return;
        }
        if (s[i].type != 8) {
            k = D_800FC270->ents[s[i].type].kind;
        } else {
            k = 3;
        }
        if (k != 3) {
            base = 9;
            id = s[i].type;
        } else {
            base = 295;
            id = s[i].b1;
        }
        base = id + base;
        if ((u8)(o->st - 3) >= 2) {
            func_800C0110(D_800F3BC0, base, 7680, 30720);
        }
    }
}
