/* Exact runtime-stage SN GCC2.8/o32 reconstruction; see config/runtime. */
/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern void func_8001D894(void *); extern void func_8001E0EC(void *);
extern unsigned char runtimeAudioSettings[], runtimeAudioHeap[];
void func_800A2F48(void) { register unsigned char *settings __asm__("$4")=runtimeAudioSettings; __asm__("" : "=r"(settings) : "0"(settings)); func_8001D894(settings+1); func_8001E0EC(runtimeAudioHeap); }
