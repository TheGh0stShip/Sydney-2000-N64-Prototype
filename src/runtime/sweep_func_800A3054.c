struct SlotOwner {
    char pad[12];
    int slots[4];
};

int func_800A3054(struct SlotOwner *owner, int value)
{
    int i;

    if (value == 0) {
        for (i = 3; i >= 0; i--) {
            owner->slots[i] = 0;
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (owner->slots[i] == 0) {
                owner->slots[i] = value;
                return i;
            }
        }
    }
    return -1;
}
