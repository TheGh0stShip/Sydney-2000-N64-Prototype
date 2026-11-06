typedef struct {
    char pad0[0x24];
    float value;
    char pad28[0xC];
    char *owner;
    int pad38;
} Slot; /* stride 0x3C */

typedef struct {
    signed char id;
    char pad1[9];
    unsigned char flags;
} Entity;

extern char *runtimeDescriptorBase;

int func_8009BFE8(int mode, Entity *ent, int kind, float val)
{
    Slot *s;
    int hit = 0;

    if (*(int *)(runtimeDescriptorBase + 0xA00) != 5 && ent->id != 8
        && (kind == 0 || kind == 4 || kind == 3)) {
        s = (Slot *)(runtimeDescriptorBase + 0x14) + ent->id;
        switch (mode) {
        case 0:
        case 1:
        case 7:
        case 10:
        case 11:
            if (s->value == 0.0f) {
                hit = 1;
            } else if (val < s->value) {
                hit = 1;
            }
            break;
        default:
            if (s->value < val) {
                hit = 1;
            }
            break;
        }
        if (hit == 1) {
            s->value = val;
            *(float *)(s->owner + 0x1A4) = val;
            ent->flags |= 1;
        }
    }
    return hit;
}
