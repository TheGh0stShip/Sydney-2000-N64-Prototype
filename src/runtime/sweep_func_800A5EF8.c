struct Entry {
    short value;
    short pad;
};

struct Object {
    char pad0[185];
    unsigned char count;
    char pad186[2];
    float value;
    float limit;
    char pad196[64];
    struct Entry entries[1];
};

int func_800A5EF8(struct Object *object)
{
    float value = object->value;
    int result = 1;
    unsigned char i;
    unsigned char count;

    if (0.0f < value && value < object->limit) {
        result = 0;
    }
    count = object->count;
    for (i = 0; i < count; i++) {
        if (object->entries[i].value == 0) {
            result = 0;
        }
    }
    return result;
}
