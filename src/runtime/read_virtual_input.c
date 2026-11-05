/* Exact runtime-stage SN GCC2.8/o32 reconstruction; see config/runtime. */
extern volatile int selectedDisplayConfiguration;
extern unsigned int func_800BBAA4(unsigned int object, unsigned int time);
unsigned int func_800AAC44(unsigned char *object, unsigned int time) {
    unsigned int result;
    if(selectedDisplayConfiguration < 0) result = 0;
    else result = (unsigned short)func_800BBAA4(*(unsigned int *)(object+0x284),time-selectedDisplayConfiguration);
    return result;
}
