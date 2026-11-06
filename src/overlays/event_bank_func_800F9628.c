typedef struct {
    float v[3];
} Row;

typedef struct {
    char pad[0xA14];
    float limit;
} LimitRow;

typedef struct {
    char pad[4];
    unsigned char *data;
} Object;

extern Row *D_800FC270;

int func_800F9628(Object *object, float t)
{
    unsigned char *state;
    Row *row;
    int idx;
    int count;
    signed char i;

    i = 0;
    state = object->data + 0x8000;
    idx = *(signed char *)(state + 0x51);
    count = *(signed char *)(state + 0x50);
    row = *(Row **)(state + 0x8C) + idx;
loop:
    if (i < count) {
        if (!(t <= i[row->v])) {
            i++;
            goto loop;
        }
        return 0;
    }
    row = D_800FC270 + *(signed char *)(object->data + 0x8000 + 0x51);
    if (t < ((LimitRow *)row)->limit) {
        return 0;
    }
    return 1;
}
