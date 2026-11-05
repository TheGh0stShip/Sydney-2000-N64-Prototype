struct SlotOwner {
    char pad[12];
    int slots[4];
};

void func_800A3028(struct SlotOwner *owner, int value)
{
    int i;

    if (value != 0) {
        for (i = 0; i < 4; i++) {
            if (owner->slots[i] == value) {
                owner->slots[i] = 0;
            }
        }
    }
}
