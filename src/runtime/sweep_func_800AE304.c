typedef struct {
    char pad0[196];
    unsigned short flags;
    char pad198[46];
    float value;
    float rate;
    float target;
    char pad256[116];
    float divisor;
} Obj;

void func_800AE304(Obj *obj) {
    float rate;
    float target;

    if (obj->divisor > *(float *)0x80086020) {
        rate = obj->rate / *(float *)0x80086024;
        target = obj->target / obj->divisor;
        if (obj->flags & 2) {
            obj->value = target;
            obj->flags &= ~2;
        } else {
            obj->value += (target - obj->value) * rate;
        }
        if (obj->value > *(float *)0x80086028) {
            obj->value = *(float *)0x80086028;
        }
        if (obj->value < *(float *)0x8008602C) {
            obj->value = *(float *)0x8008602C;
        }
    }
}
