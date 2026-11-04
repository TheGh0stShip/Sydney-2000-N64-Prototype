#ifndef LEAF_NAME
#define LEAF_NAME addScaledValues
#endif

void LEAF_NAME(int mode, int first, int second, int third, int fourth,
               float *firstOutput, float *secondOutput, float *thirdOutput,
               float *fourthOutput)
{
    register int scaled __asm__("$2");

    if (mode == 8) {
        scaled = first << 2;
        *firstOutput += scaled;
        scaled = second << 2;
        *secondOutput += scaled;
        scaled = third << 2;
        *thirdOutput += scaled;
        scaled = fourth << 2;
        *fourthOutput += scaled;
    } else if (!(mode & 1)) {
        scaled = first << 1;
        *firstOutput += scaled;
        scaled = second << 1;
        *secondOutput += scaled;
        scaled = third << 1;
        *thirdOutput += scaled;
        scaled = fourth << 1;
        *fourthOutput += scaled;
    } else {
        *firstOutput += first;
        *secondOutput += second;
        *thirdOutput += third;
        *fourthOutput += fourth;
    }
}
