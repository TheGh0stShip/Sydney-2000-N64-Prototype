#ifndef LEAF_NAME
#define LEAF_NAME synthesizeDelayedAudioSamples
#endif

typedef signed short s16;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 samples[179];
    s16 delay;
} DelayedAudioState;

extern u16 delayCoefficients[] __asm__("D_80027E68");

void LEAF_NAME(DelayedAudioState *state, s32 delay, u32 coefficientIndex,
               const s16 *input)
{
    u32 index;
    s32 coefficient;

    if (delay >= 40 && delay <= 120) {
        state->delay = delay;
    }
    delay = state->delay;
    coefficient = delayCoefficients[coefficientIndex];
    for (index = 0; index < 120; index++) {
        state->samples[index] = state->samples[index + 40];
    }
    for (index = 0; index < 40; index++) {
        s32 predicted = state->samples[120 + index - delay] * coefficient;
        state->samples[120 + index] =
            input[index] + ((predicted + 0x4000) >> 15);
    }
}
