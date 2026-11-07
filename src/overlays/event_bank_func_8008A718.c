typedef unsigned char u8;
typedef struct Obj {
    char pad[0x8410];
    int unk8410;
    char pad8414[2];
    u8 unk8416;
    u8 state;
    u8 next;
    char pad8419[0x8438 - 0x8419];
    int handle;
} Obj;
typedef struct Arg { int unk0; int unk4; } Arg;
extern char D_800F26E0[];
extern char D_800F1AE0[];
extern void func_8009BD50(int);
extern void func_800AB2A4(void *, int, int, void *, int, int);
extern void func_80075050(Obj *);
extern void func_8001D680(void *, int);
void func_8008A718(Obj *o, Arg *a)
{
    o->unk8410 = 0;
    func_8009BD50(o->state);
    if (o->state == 5) {
        o->state = o->next;
    }
    if (o->state == 4 || o->state == 2 || o->state == 3) {
        func_800AB2A4(D_800F26E0, a->unk4, 21, o, 0, 1);
    } else {
        func_800AB2A4(D_800F26E0, a->unk4, 21, o, 0, 0);
    }
    func_80075050(o);
    o->unk8416 = 0;
    if (o->handle != -1) {
        func_8001D680(D_800F1AE0, o->handle);
        o->handle = -1;
    }
}
