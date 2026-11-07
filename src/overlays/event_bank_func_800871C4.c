typedef unsigned char u8;
typedef struct Slot { char pad[4]; float f4; char pad8[4]; } Slot;
typedef struct Glob { char pad[2560]; int w0A00; int w0A04; char padA08[4]; u8 count; char padA0D[3]; Slot slots[1]; } Glob;
typedef struct Arr { short h0; char pad[34]; } Arr;
typedef struct Obj {
    char pad[1550];
    u8 index;
    char pad60F[1555 - 1551];
    u8 stride;
    char pad614[21200 - 1556];
    Slot *cur;
    Slot *nxt;
    char pad61E8[21264 - 21208];
    Arr arr[8];
    char pad6228[21568 - 21264 - 8 * 36];
    int w62E8;
} Obj;
extern Glob *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *, int, int, int);
void func_80075DF4(Obj *o)
{
    Slot *s = &D_800FC270->slots[o->index * o->stride];
    u8 i;
    int c;
    int id;
    for (i = 0; i < o->stride; i++, s++) {
        if (s == o->cur) {
            break;
        }
    }
    c = 0;
    if (o->nxt != 0 && o->nxt->f4 - o->cur->f4 <= 0.35f) {
        c = 1;
    }
    if (D_800FC270->w0A00 != 4 || D_800FC270->w0A04 < 4) {
        if (c == 1) {
            id = 621;
        } else {
            id = 623;
        }
        if (o->arr[i].h0 == 0) {
            id -= 1;
        }
    } else {
        if (D_800FC270->w0A04 == 4) {
            if (c == 1) {
                id = 539;
            } else {
                id = 543;
            }
        } else {
            if (c == 1) {
                id = 538;
            } else {
                id = 542;
            }
        }
        if (o->arr[i].h0 == 0) {
            id -= 2;
        }
    }
    if (id != -1 && D_800FC270->w0A04 != 0 && o->w62E8 == 1) {
        func_800C0110(D_800F3BC0, id, 0, 0);
    }
}
