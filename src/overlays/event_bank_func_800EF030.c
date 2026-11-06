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

int func_800EF030(Object *object, float t)
{
    unsigned char *state;
    Row *row;
    int idx;
    int count;
    signed char i;

    i = 0;
    state = object->data + 0x8000;
    idx = *(signed char *)(state + 0x415);
    count = *(signed char *)(state + 0x414);
    row = *(Row **)(state + 0x44C) + idx;
loop:
    if (i < count) {
        if (!(t <= i[row->v])) {
            i++;
            goto loop;
        }
        return 0;
    }
    row = D_800FC270 + *(signed char *)(object->data + 0x8000 + 0x415);
    if (t < ((LimitRow *)row)->limit) {
        return 0;
    }
    return 1;
}
