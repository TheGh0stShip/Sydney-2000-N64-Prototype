extern void func_8001D894(void *); extern void func_8001E0EC(void *);
extern unsigned char runtimeAudioSettings[], runtimeAudioHeap[];
void func_800A2F48(void) { unsigned char *s = runtimeAudioSettings; func_8001D894(s+1); func_8001E0EC(runtimeAudioHeap); }
