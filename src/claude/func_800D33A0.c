extern void func_800B3870(void *dst, void *src, int len);
extern void func_800D2B14(void *obj, short arg);

void func_800D33A0(char *obj, void *src, short value, short arg) {
    func_800B3870(obj + 0xD4, src, 0x28);
    *(short *)(obj + 0x576) = value;
    func_800D2B14(obj, arg);
}
