typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Item { char pad[220]; } Item;
typedef struct Def { char pad[24]; } Def;
typedef struct Args { int a; int b; int c; int d; } Args;
typedef struct Obj {
    char pad[1616];
    Item items[10];
    char pad2[3816 - 1616 - 10 * 220];
    u16 keys[15];
    u8 count;
} Obj;
extern Args D_800F4760;
extern Def D_800F4178[];
extern void func_800B31EC(int);
extern void func_800B360C(Item *, Def *);
void func_80083624(Obj *o, u16 key, int a, int b, int c, int d)
{
    int i;
    for (i = 0; (u8)i < o->count; i++) {
        u16 k = o->keys[(u8)i];
        if (k == key) {
            D_800F4760.a = a;
            D_800F4760.b = b;
            D_800F4760.c = c;
            D_800F4760.d = d;
            func_800B31EC(0);
            func_800B360C(&o->items[(u8)i], &D_800F4178[k]);
            return;
        }
    }
}
