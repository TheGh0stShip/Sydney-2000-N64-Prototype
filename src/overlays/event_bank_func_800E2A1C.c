typedef struct {
    char pad0[0x5C];
    float value;
} EventActor;

typedef struct {
    char pad0[0x613];
    unsigned char count;
    char pad614[0x4EF0 - 0x614];
    EventActor *actors[1];
} EventGroup;

/* Returns the index of the actor whose value is closest to the group mean. */
unsigned char func_800E2A1C(EventGroup *g)
{
    unsigned char i;
    unsigned char best;
    unsigned int count;
    unsigned int count2;
    EventActor *actor;
    float sum;
    float n;
    float one;
    float diff;
    float min;

    i = 0;
    sum = 0.0f;
    count = g->count;
    one = *(float *)0x800714A8;
    n = sum;
    while (1) {
        if (i >= count) {
            break;
        }
        actor = g->actors[i];
        if (actor != 0) {
            n += one;
            sum += actor->value;
        }
        i++;
    }
    sum /= n;
    best = 0;
    i = best;
    min = *(float *)0x800714AC;
    count2 = g->count;
    while (1) {
        if (i >= count2) {
            break;
        }
        actor = g->actors[i];
        if (actor != 0) {
            diff = sum - actor->value;
            if (diff < 0.0f) {
                diff = -diff;
            }
            if (diff < min) {
                min = diff;
                best = i;
            }
        }
        i++;
    }
    return best;
}
