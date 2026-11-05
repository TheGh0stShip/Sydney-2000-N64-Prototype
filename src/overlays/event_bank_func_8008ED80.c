typedef struct EventDescriptor {
    unsigned char pad[64];
    short offset;
    unsigned short pad66;
    void (*update)(void *);
} EventDescriptor;

void func_8008ED80(unsigned char *object, float value)
{
    unsigned char *hi;
    unsigned char *call_base;
    EventDescriptor *descriptor;
    float delta;

    delta = value - *(float *)0x800714C8;
    if (delta < 0.0f) {
        delta = 0.0f;
    }
    if ((*(unsigned char **)(object + 23004))[426] != 3) {
        hi = object + 0x8000;
        if (hi[1047] != 2) {
            call_base = object + 0x87B4;
            descriptor = *(EventDescriptor **)(hi + 2152);
            descriptor->update(call_base + descriptor->offset);
        }
    }
    *(float *)(object + 0x8000 + 2132) = delta * *(float *)0x800714CC;
}
