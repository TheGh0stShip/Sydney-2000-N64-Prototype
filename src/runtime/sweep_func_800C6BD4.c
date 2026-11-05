extern int D_800F40F0;
extern signed char D_80102030[];

typedef struct {
    char pad0[192];
    int flags;
    int group;
    char pad200;
    unsigned char mode;
} BlinkChild;

typedef struct {
    char pad0[220];
    unsigned char *info;
    char pad224[20];
    BlinkChild *children[134];
    unsigned int counter;
} BlinkOwner;

void func_800C6BD4(BlinkOwner *self)
{
    int found = 0;
    int i = 0;
    unsigned char id = **(unsigned char **)(self->info + 28);
    BlinkChild *child;
    unsigned char idx;

    for (; (unsigned char)i < 12; i++) {
        if (D_80102030[(unsigned char)i] == id) {
            found = 1;
        }
    }
    if (!found) {
        return;
    }
    for (i = 0;; i++) {
        idx = i;
        if (idx >= 4) {
            return;
        }
        child = self->children[idx];
        if (child->group == D_800F40F0) {
            if (++self->counter >= 9) {
                child->mode = 5;
                child->flags = (child->flags ^ 4) | 0x20000;
                self->counter = 0;
            }
        }
    }
}
