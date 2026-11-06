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
extern Vec2 D_8007C200[][4];
extern IVec2 D_8007C380[][4];

void func_800F6490(Obj *obj)
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

    src = D_8007C200[obj->slot];
    dst = D_8007C380[obj->slot];
    switch (D_800FC270->mode) {
    case 0:
    default:
        sx = *(float *)0x80078BE8;
        sy = *(float *)0x80078BEC;
        break;
    case 1:
        sx = *(float *)0x80078BF0;
        sy = *(float *)0x80078BF4;
        break;
    case 2:
        sx = *(float *)0x80078BF8;
        sy = *(float *)0x80078BFC;
        break;
    case 3:
        sx = *(float *)0x80078C00;
        sy = *(float *)0x80078C04;
        break;
    }
    one = *(float *)0x80078C08;
    xs = *(float *)0x80078C0C;
    num = *(float *)0x80078C10;
    ys = *(float *)0x80078C14;
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
