typedef unsigned char u8;
typedef unsigned int u32;

extern void func_800ADC1C(void *object);
extern void *func_800AEF6C(void *object, int selector);
extern void func_800AE72C(void *object, void *target, void *value);
extern void func_800AE9DC(void *object, float amount, void *target);
extern void func_800A9BE8(void *object, int mode);

void func_80075524(u8 *state) {
    u8 *object;
    u8 *target;
    void *value;

    func_800ADC1C(state + 0x106C);
    value = func_800AEF6C(state + 0x1214, 0);
    object = state + 0x70C;
    target = state + 0xACC;
    func_800AE72C(object, target, value);
    func_800AE9DC(object, 196.60199f, target);
    *(u32 *)(object + 0x0C) = 1;
    *(u32 *)(object + 0x38) = 1;
    state[0x2860] = 6;
    *(u32 *)(state + 0x2864) = 0x12C00;
    func_800A9BE8(state + 0x1234, 2);
}
