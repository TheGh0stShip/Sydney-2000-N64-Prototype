/* Exact SN GCC2.8 match (-O2 -G0 -mcpu=vr4300 -mips3 -mhard-float -meb); verified via n64dk match. */
typedef unsigned int u32; typedef signed int s32;
typedef struct { s32 time; unsigned char unused, value, reserved[2]; } InputSample;
typedef struct { unsigned short unused, index; InputSample *samples; } InputPlayback;

u32 func_800BBAA4(InputPlayback *playback, s32 time) {
    u32 index = playback->index;
    InputSample *sample = &playback->samples[index];

    if (sample->time != -0x1E00 && time >= sample->time) {
        sample++;
        if (sample->time != -0x1E00 && time >= sample->time) {
            playback->index = index + 1;
        } else {
            sample--;
        }
        return sample->value;
    }
    return 0;
}
