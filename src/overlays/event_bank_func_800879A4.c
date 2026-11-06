typedef struct Glob { char pad[0xA00]; int modeA00; } Glob;
typedef struct Obj {
    char pad[0x612]; unsigned char b612; unsigned char b613; char pad614;
    unsigned char b615; char pad616[0x5460 - 0x616];
    int w5460; int w5464; float f5468;
} Obj;
extern Glob *D_800FC270;

void func_800879A4(Obj *o)
{
    int v;
    float f;
    if (o->b615 < 2) {
        if (o->b615 == 1 || D_800FC270->modeA00 != 4) {
            v = 0x12C00;
            o->b612 = 1;
        } else {
            v = 0x18600;
            o->b612 = 0;
        }
        o->w5460 = v;
        f = *(float *)0x80071428;
        o->f5468 = f;
    } else {
        f = *(float *)0x8007142C;
        o->b612 = 14;
        o->w5460 = 0x10E00;
        o->f5468 = f;
    }
    o->w5464 = o->w5460;
    o->w5464 = o->w5464 + o->b613 * 23040 + 38400;
}
