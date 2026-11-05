typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern void func_80037F30(void *dst, int value, int size);
extern void func_8008393C(void *object, int count, void **out);

void func_800CF3C4(u8 *object, u8 selector, int offset)
{
    u8 choices[4];
    u8 index;
    s8 *entry;
    s8 *first;
    u32 state;
    register int scale asm("$3");

    func_80037F30(choices, 0, 4);
    choices[3] = 3;
    index = choices[selector] + offset;
    *(void **)(object + 17132) = 0;
    func_8008393C(object, 18, (void **)(object + 17132));
    entry = *(s8 **)(object + 17132) + index * 12;
    *(s8 **)(object + 17128) = entry;

    scale = entry[0];
    if (scale == 0) {
        state = *(u32 *)(object + 17876);
        scale = (state * 16807) & 0x7fffffff;
        *(u32 *)(object + 17876) = scale;
        scale = ((u32)scale >> 29) + 2;
    }
    *(volatile int *)(object + 3856) = ((scale << 4) - scale) << 9;

    first = *(s8 * volatile *)(object + 17128);
    *(float *)(object + 17364) = first[10];
    entry = *(s8 * volatile *)(object + 17128);
    *(float *)(object + 17360) = entry[9];
    *(float *)(object + 17356) = entry[8];
    *(float *)(object + 17388) = *(float *)(entry + 4);
}
