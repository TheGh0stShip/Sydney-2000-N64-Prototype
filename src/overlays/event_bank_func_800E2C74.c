typedef unsigned char u8;
typedef struct Slot { char pad[2]; short unk2; char pad4[8]; } Slot;
typedef struct Glob { char pad[2572]; u8 count; char padA0D[2576 - 2573]; Slot slots[256]; } Glob;
typedef struct Obj {
    char pad[1550];
    u8 index;
    char pad60F[1555 - 1551];
    u8 stride;
    char pad614;
    u8 state;
    char pad616[25383 - 1558];
    u8 mode;
} Obj;
extern Glob *D_800FC270;
extern void func_8007714C(Obj *);
extern void func_80074390(Obj *);
void func_80077284(Obj *o)
{
    u8 st = o->state;
    if (st == 0 || st == 5) {
        while (o->index < D_800FC270->count) {
            if (o->mode == 0) {
                func_8007714C(o);
            } else if (o->mode == 1) {
                func_80074390(o);
            }
            o->mode = 0;
            o->index++;
        }
    } else if (st == 4) {
        D_800FC270->slots[o->index * o->stride].unk2 = -1;
    }
}
