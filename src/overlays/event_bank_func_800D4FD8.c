#define D_800709A8 (*(float *)0x800709A8)

typedef struct {
    int value;
    unsigned char pad[208];
} Slot;

extern void func_80071BBC(void);

void func_800D4FD8(unsigned char *object)
{
    float scaled;

    {
        int i = object[19744];
        Slot *slot = (Slot *)(object + 17984);

        slot[i].value = *(int *)(object + 17780);
    }
    *(int *)(object + 19808) = 0;
    *(short *)(object + 19720) = 0;
    *(short *)(object + 19718) = 0;
    *(short *)(object + 19716) = 0;
    *(int *)(object + 19724) = *(int *)(object + 19700);
    func_80071BBC();
    scaled = *(float *)(object + 19740) * D_800709A8;
    *(int *)(object + 19820) = 0;
    *(int *)(object + 19824) = 0;
    *(int *)(object + 19736) = (int)scaled;
}
