extern int D_800F40F4;

typedef struct {
    char pad0[192];
    int flags;
    int group;
} BlinkChild;

typedef struct {
    char pad0[244];
    BlinkChild *children[134];
    unsigned int counter;
} BlinkOwner;

void func_800C6B70(BlinkOwner *self)
{
    int i = 0;
    int target = D_800F40F4;
    BlinkChild *child;
    unsigned char idx;

    for (;; i++) {
        idx = i;
        if (idx >= 2) {
            return;
        }
        child = self->children[idx];
        if (child->group == target) {
            if (++self->counter >= 9) {
                child->flags ^= 4;
                self->counter = 0;
            }
        }
    }
}
