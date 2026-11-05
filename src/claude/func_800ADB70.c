/* Runtime-stage C reconstruction: release an object's resource bundle back to the resident pool. */
typedef struct {
    short pad0;
    unsigned short counts[3]; /* 0x02 */
    void *items[3];           /* 0x08 */
} Bundle;

typedef struct {
    char pad0[0xD0];
    Bundle *bundle;           /* 0xD0 */
} Owner;

extern char D_800F2758[];
extern void func_800AA658(void *pool, void *slot);

void func_800ADB70(Owner *owner) {
    unsigned char i;
    if (owner->bundle != 0) {
        for (i = 0;; i++) {
            unsigned int k = i;
            if (!(k < 3)) break;
            if (owner->bundle->counts[k] != 0) {
                func_800AA658(D_800F2758, &owner->bundle->items[k]);
                owner->bundle->counts[k] = 0;
            }
        }
        func_800AA658(D_800F2758, &owner->bundle);
    }
}
