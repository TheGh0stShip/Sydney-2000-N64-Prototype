/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
typedef struct { short displayIndex; unsigned short value; unsigned int stateIndex; } InputDescriptor;
extern InputDescriptor runtimeInputDescriptors[];
void func_800BC3E0(unsigned short index, short displayIndex, unsigned short value, unsigned short stateIndex) { InputDescriptor *descriptor=&runtimeInputDescriptors[index]; descriptor->displayIndex=displayIndex; descriptor->value=value; descriptor->stateIndex=stateIndex; }
