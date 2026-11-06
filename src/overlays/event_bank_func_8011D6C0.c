typedef float f32;

#define D_80080AD8 (*(f32 *)0x80080AD8)

void func_80079DD0(char *object, f32 value)
{
    f32 offset = D_80080AD8;

    *(f32 *)(object + 0x1AC) = value;
    *(f32 *)(object + 0x58) = value - offset;
    *(f32 *)(object + 0x174) = *(f32 *)(object + 0x1AC) - offset;
}
