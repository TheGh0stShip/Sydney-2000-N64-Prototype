/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern void func_800B3AFC(void *, unsigned int, unsigned int);
extern unsigned char runtimeInputEvents[]; extern unsigned short runtimeInputReadIndex, runtimeInputWriteIndex;
void func_800BC378(void) { func_800B3AFC(runtimeInputEvents,0,0xC00); runtimeInputReadIndex=0; runtimeInputWriteIndex=0; }
