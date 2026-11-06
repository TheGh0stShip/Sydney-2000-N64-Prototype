typedef unsigned char u8;
typedef short s16;
typedef float f32;

typedef struct {
    s16 pad0;
    s16 h;
    f32 v;
    u8 rank;
    u8 pad9[3];
} Elem;

typedef struct {
    char pad0[0xA0C];
    u8 count;
    char padA0D[3];
    Elem e[16];
} Game;

typedef struct {
    char pad0[0x5DA4];
    f32 f[16];
    u8 b5DE4;
} Obj;

extern Game *D_800FC270;

void func_80073438(Obj *o)
{
    Elem *list[16];
    Game *g;
    Elem *a;
    Elem *b;
    u8 i;
    int swapped;
    s16 h;
    f32 *pf;

    if (o->b5DE4 != 1) {
        g = D_800FC270;
        pf = o->f;
        a = g->e;
        for (i = 0; i < D_800FC270->count; i++) {
            if (a->v != -1.0f) {
                if (*pf != -1.0f) {
                    a->v = a->v + o->f[i];
                } else {
                    a->v = -1.0f;
                }
            }
            a++;
            o->f[i] = 0;
            pf++;
        }
    }
    g = D_800FC270;
    a = g->e;
    for (i = 0; i < D_800FC270->count; i++) {
        list[i] = a;
        a++;
    }
    do {
        swapped = 0;
        for (i = 0; i < D_800FC270->count - 1; i++) {
            u8 j = i + 1;
            a = list[j];
            if (a->v == -1.0f) {
                continue;
            }
            if (list[i]->v == -1.0f || a->v < list[i]->v) {
                swapped = 1;
                b = list[i];
                list[i] = a;
                list[j] = b;
            }
        }
    } while (swapped == 1);
    i = 0;
    while (1) {
        if (i >= D_800FC270->count) {
            break;
        }
        a = list[i];
        a->rank = i;
        if (a->v != -1.0f) {
            if (a->v < 400.0f) {
                if (100.0f < a->v) {
                    h = (400.0f - a->v) * 5.0f;
                } else {
                    h = 1500;
                }
            } else {
                h = 0;
            }
            a->h = h;
        } else {
            a->h = -1;
        }
        i++;
    }
}
