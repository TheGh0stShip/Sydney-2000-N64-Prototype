typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;

extern void func_800B9E9C(u8 *obj, s32 a, s32 b, s32 c, s32 d);

void func_80112560(u8 *obj)
{
    u8 i;
    s16 *q;

    q = (s16 *)(obj + 430);

    if (obj[743] == 0) {
        i = 0;
        do {
            *q = 68;
            i++;
            q++;
        } while (i < 5);
        *q = -1;
        obj[429] = 0;
        func_800B9E9C(obj, *(s16 *)(obj + 430), -1, *(s32 *)(obj + 632), 0);
    } else {
        i = 0;
        do {
            *q = 62;
            i++;
            q++;
        } while (i < 5);
        *q = -1;
        obj[429] = 0;
        func_800B9E9C(obj, *(s16 *)(obj + 430), -1, *(s32 *)(obj + 632), 0);
    }
    *(f32 *)(obj + 632) = *(f32 *)(obj + 804);
}
