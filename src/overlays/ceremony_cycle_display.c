typedef unsigned char u8;
typedef unsigned int u32;

extern void *ceremonyDisplayResources[];
extern void func_800A848C(void *object, int index, void *resource);
extern void func_800B4794(int enabled);

void func_8007549C(u8 *state) {
    signed char *index = (signed char *)(state + 0x2861);
    register u32 offset __asm__("$2");

    ++*index;
    if (*index >= 10) {
        *index = 0;
    }
    func_800A848C(state + 0x1F4, 0, ceremonyDisplayResources[*index]);
    func_800B4794(1);
    offset = (u32)*index * 4;
    __asm__("addu %0,%1,%0" : "+r"(offset) : "r"(state));
    *(u32 *)(state + 0xEB4) = *(u32 *)(offset + 0xE0);
    func_800B4794(0);
}
