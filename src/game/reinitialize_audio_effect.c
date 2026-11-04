#ifndef LEAF_NAME
#define LEAF_NAME reinitializeAudioEffect
#endif
#ifndef LOW_PASS_NAME
#define LOW_PASS_NAME initializeLowPass
#endif

typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

typedef struct AudioFilter {
    void *source;
    void *handler;
    void *setParameter;
    s16 input;
    s16 output;
    s32 type;
} AudioFilter;
typedef struct LowPass {
    s16 frequency;
    s16 gain;
    unsigned char pad[4];
    s16 coefficients[16];
    void *state;
    s32 first;
} LowPass;
typedef struct Resampler {
    AudioFilter filter;
    void *state;
    f32 ratio;
    s32 unityPitch;
    f32 delta;
    s32 first;
    void *controlList;
    void *controlTail;
    s32 motion;
} Resampler;
typedef struct Delay {
    u32 input;
    u32 output;
    s16 feedForward;
    s16 feedback;
    s16 gain;
    s16 pad;
    f32 resampleIncrement;
    f32 resampleValue;
    s32 resampleDelta;
    f32 resampleGain;
    LowPass *lowPass;
    Resampler *resampler;
} Delay;
typedef struct Effect {
    AudioFilter filter;
    s16 *base;
    s16 *input;
    u32 length;
    Delay *delay;
    u8 sectionCount;
    u8 pad[3];
    void *parameterHandler;
} Effect;
typedef struct {
    unsigned char pad[0x34];
    struct {
        unsigned char pad[0x24];
        Effect *effect;
    } *auxiliaryBus;
    unsigned char pad38[8];
    s32 outputRate;
} Synthesizer;

extern Synthesizer *audioState;
extern void *effectBuffers[6];
extern void LOW_PASS_NAME(LowPass *lowPass);

void LEAF_NAME(s32 *parameters)
{
    u16 section;
    u16 parameter;
    Delay *delay;
    Effect *effect;

    effect = audioState->auxiliaryBus->effect;
    parameter = 2;
    effect->sectionCount = parameters[0];
    effect->length = parameters[1];
    effect->delay = (Delay *)effectBuffers[0];
    effect->base = effectBuffers[1];
    effect->input = effect->base;
    for (section = 0; section < effect->length; section++)
        effect->base[section] = 0;
    for (section = 0; section < effect->sectionCount; section++) {
        delay = &effect->delay[section];
        delay->input = parameters[parameter++];
        delay->output = parameters[parameter++];
        delay->feedback = parameters[parameter++];
        delay->feedForward = parameters[parameter++];
        delay->gain = parameters[parameter++];
        if (parameters[parameter]) {
            delay->resampleIncrement =
                ((((f32)parameters[parameter++]) / 1000) * 2.0) /
                audioState->outputRate;
            delay->resampleGain =
                (((f32)parameters[parameter++]) / 173123.404906676) *
                (delay->output - delay->input);
            delay->resampleValue = 1.0;
            delay->resampleDelta = 0.0;
            delay->resampler = effectBuffers[2];
            delay->resampler->state = effectBuffers[3];
            delay->resampler->delta = 0.0;
            delay->resampler->first = 1;
        } else {
            delay->resampler = 0;
            parameter++;
            parameter++;
        }
        if (parameters[parameter]) {
            delay->lowPass = effectBuffers[4];
            delay->lowPass->state = effectBuffers[5];
            delay->lowPass->frequency = parameters[parameter++];
            LOW_PASS_NAME(delay->lowPass);
        } else {
            delay->lowPass = 0;
            parameter++;
        }
    }
}
