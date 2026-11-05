typedef unsigned char u8;
typedef unsigned int u32;

typedef struct RuntimeRecord {
    u32 field0;
    void *resource;
} RuntimeRecord;

extern void func_800B3870(void *destination, const void *source, u32 size);
extern void func_800AC334(void *object);
extern void func_800AC37C(void *object, void *owner);
extern void func_800A9B78(void *destination, void *object, int enabled,
                         int selector, int mode);

void func_800725FC(u8 *state, u8 *input, int selector) {
    RuntimeRecord *record;

    func_800B3870(state + 0x7C0, input + 0x14, 0x4C);
    record = (RuntimeRecord *)(state + 0x7AC);
    if (record->resource != 0) {
        func_800AC334(record);
    }
    func_800AC37C(record, input);
    func_800A9B78(state + 0x9AC, record, 1, selector, 2);
}
