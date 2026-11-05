/* Close the current group's point list: latch the anchor point, then store
 * in the next free slot the offset that remains after subtracting every
 * existing slot from it. */
typedef struct Point {
    unsigned short v[3];
    unsigned short pad;
} Point;

typedef struct Game {
    char pad0[824];
    Point slots[53][4];
    char padS[4];
    unsigned short group;
    char pad1[2528 - 2526];
    unsigned short count;
    char pad2[2538 - 2530];
    unsigned short anchor[3];
    unsigned short latched[3];
} Game;

extern Game *D_800FC270;

void func_800E1E18(void)
{
    unsigned short rest[3];
    unsigned int i;

    rest[0] = D_800FC270->latched[0] = D_800FC270->anchor[0];
    rest[1] = D_800FC270->latched[1] = D_800FC270->anchor[1];
    rest[2] = D_800FC270->latched[2] = D_800FC270->anchor[2];
    for (i = 0; i < D_800FC270->count; i++) {
        rest[0] -= D_800FC270->slots[D_800FC270->group][i].v[0];
        rest[1] -= D_800FC270->slots[D_800FC270->group][i].v[1];
        rest[2] -= D_800FC270->slots[D_800FC270->group][i].v[2];
    }
    D_800FC270->slots[D_800FC270->group][D_800FC270->count].v[0] = rest[0];
    D_800FC270->slots[D_800FC270->group][D_800FC270->count].v[1] = rest[1];
    D_800FC270->slots[D_800FC270->group][D_800FC270->count].v[2] = rest[2];
}
