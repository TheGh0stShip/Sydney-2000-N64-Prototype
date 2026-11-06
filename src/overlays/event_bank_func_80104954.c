typedef struct Vec2 {
    float x;
    float y;
} Vec2;

typedef struct IVec2 {
    int x;
    int y;
} IVec2;

typedef struct Game {
    char pad0[0xD53];
    unsigned char mode;
} Game;

typedef struct Obj {
    char pad0[0x27C];
    unsigned char slot;
} Obj;

extern Game *D_800FC270;
extern Vec2 D_8007BA28[][4];
extern IVec2 D_8007BBB0[][4];

void func_80104954(Obj *obj)
{
    Vec2 *src;
    IVec2 *dst;
    float sx;
    float sy;
    unsigned char n;
    float one;
    float xs;
    float num;
    float ys;

    src = D_8007BA28[obj->slot];
    dst = D_8007BBB0[obj->slot];
    switch (D_800FC270->mode) {
    case 0:
    default:
        sx = *(float *)0x80078B60;
        sy = *(float *)0x80078B64;
        break;
    case 1:
        sx = *(float *)0x80078B68;
        sy = *(float *)0x80078B6C;
        break;
    case 2:
        sx = *(float *)0x80078B70;
        sy = *(float *)0x80078B74;
        break;
    case 3:
        sx = *(float *)0x80078B78;
        sy = *(float *)0x80078B7C;
        break;
    }
    one = *(float *)0x80078B80;
    xs = *(float *)0x80078B84;
    num = *(float *)0x80078B88;
    ys = *(float *)0x80078B8C;
    n = 4;
loop:
    if (n != 0) {
        float x;
        float y;

        x = src->x;
        if (sx != one) {
            x *= sx;
        }
        y = src->y;
        if (sy != one) {
            y *= sy;
        }
        dst->x = x * xs;
        dst->y = num / y * ys;
        src++;
        dst++;
        n--;
        goto loop;
    }
}
