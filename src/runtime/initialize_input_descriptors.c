/* Exact runtime-stage SN GCC2.8/o32 reconstruction; see config/runtime. */
typedef struct { short displayIndex; unsigned short value; unsigned int stateIndex; } InputDescriptor;
extern InputDescriptor runtimeInputDescriptors[];
void func_800BC420(void) {
    unsigned int index = 0;
    short invalid = -1;
    InputDescriptor *descriptor = runtimeInputDescriptors;
    do {
        descriptor->displayIndex = invalid;
        descriptor->value = 0;
        __asm__ volatile ("" : "=r"(index) : "0"(index) : "memory");
        index++;
        descriptor++;
    } while(index < 29);
}
