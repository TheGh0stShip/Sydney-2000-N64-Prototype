/* Matches (SN -O2, --symbol=descriptorRefreshState:0x80101938).
 * The block-scoped loop condition reproduces the original's non-inverted
 * top-tested loop (GCC 2.8 will not duplicate an exit test containing a scope);
 * the unsigned int copy of the counter makes the byte stores use the masked
 * value (i & 0xFF) as in the original. */
typedef struct {
    char pad0[0x10];
    signed char unk10;
    signed char unk11;
    char pad12[6];
} Entry800BC180;

extern unsigned char descriptorRefreshState;

void func_800BC180(Entry800BC180 *entries) {
    unsigned char i;

    for (i = 0; ({ i < 12; }); i++) {
        unsigned int j = i;

        if (j < descriptorRefreshState) {
            entries[j].unk10 = j;
            entries[j].unk11 = j;
        } else {
            entries[j].unk10 = -1;
            entries[j].unk11 = -1;
        }
    }
}
