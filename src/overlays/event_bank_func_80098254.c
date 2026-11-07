typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct {
    char pad0[0x50];
    s8 col;
    s8 row;
    u8 f52;
    u8 pad53;
    u8 f54;
    char pad55[0x6C - 0x55];
    s32 f6C;
    char pad70[0x8C - 0x70];
    f32 *tbl;
} Hdr;

typedef struct {
    char pad0[0xA00];
    s32 mode;
} Game;

extern Game *D_800FC270;
extern void func_80075D88(u8 *, f32);
extern void func_8007582C(u8 *, f32);
extern void func_80075C6C(u8 *, f32);
extern void func_800A9BE8(void *, s32);

void func_80072C64(u8 *obj)
{
    f32 v;

    ((Hdr *)(obj + 0x8000))->f6C -= 256;
    if (((Hdr *)(obj + 0x8000))->f6C > 0) {
        return;
    }
    v = ((Hdr *)(obj + 0x8000))->tbl[((Hdr *)(obj + 0x8000))->row * 3 + ((Hdr *)(obj + 0x8000))->col];
    if (((Hdr *)(obj + 0x8000))->f54 == 5) {
        func_80075D88(obj, v);
    } else if (D_800FC270->mode == 4) {
        func_8007582C(obj, v);
    } else if (D_800FC270->mode == 5) {
        func_80075C6C(obj, v);
    }
    switch (((Hdr *)(obj + 0x8000))->f54) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
        if (*(s32 *)(*(u8 **)(obj + 12136) + 744) != 0) {
            ((Hdr *)(obj + 0x8000))->f6C = 30720;
            func_800A9BE8(obj + 32228, 7);
        } else {
            ((Hdr *)(obj + 0x8000))->f6C = 15360;
        }
        ((Hdr *)(obj + 0x8000))->f52 = 15;
        break;
    case 2:
        ((Hdr *)(obj + 0x8000))->f6C = 15360;
        ((Hdr *)(obj + 0x8000))->f52 = 17;
        break;
    }
}
