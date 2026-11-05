typedef struct {
    short offset;
    void (*fn)(void *self);
} VirtualSlot;

#define VCALL(self, off) \
    do { \
        VirtualSlot *slot_ = (VirtualSlot *)(*(unsigned char **)((self) + 180) + (off)); \
        slot_->fn((self) + slot_->offset); \
    } while (0)

void func_800CCC68(unsigned char *self, int *message)
{
    switch (message[0]) {
    case 5:
        *(int *)(self + 212) -= 256;
        if (*(int *)(self + 212) <= 0) {
            *(int *)(self + 212) = 3840;
            *(int *)(self + 192) ^= 4;
        }
        VCALL(self, 32);
        break;
    case 3:
        break;
    case 7:
        VCALL(self, 24);
        break;
    }
    *(int *)(self + 16) = message[1];
}
