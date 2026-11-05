/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
typedef struct { short displayIndex; unsigned short value; unsigned int stateIndex; } InputDescriptor;
extern InputDescriptor runtimeInputDescriptors[];
InputDescriptor *func_800BC408(unsigned short device) { return &runtimeInputDescriptors[device]; }
