typedef struct {
    short offset;
    void (*fn)(void *self);
} VirtualSlot;

extern void func_800ADC38(void *part);
extern void func_800B2158(void *part, int mode);

void func_800D26AC(unsigned char *self)
{
    VirtualSlot *slot;

    if (self[5384] & 1) {
        return;
    }
    slot = (VirtualSlot *)(*(unsigned char **)(self + 180) + 64);
    slot->fn(self + slot->offset);
    func_800ADC38(self + 2128);
    func_800ADC38(self + 2340);
    func_800ADC38(self + 2552);
    func_800ADC38(self + 644);
    func_800ADC38(self + 212);
    func_800B2158(self + 424, 1);
    func_800ADC38(self + 856);
    func_800ADC38(self + 1068);
    func_800ADC38(self + 1280);
    *(float *)(self + 160) = 696.0f;
    self[5384] |= 1;
    self[5385] |= 1;
}
