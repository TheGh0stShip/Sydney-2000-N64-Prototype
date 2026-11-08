typedef unsigned char u8;
typedef unsigned int u32;
extern void *ceremonyDisplayResources[];
extern void func_800A848C(void *object, int index, void *resource);
extern void func_800B4794(int enabled);
typedef struct { u8 pad[0xE0]; u32 tab[10]; } St;
void func_8007549C(u8 *state) {
 signed char *index = (signed char *)(state + 0x2861);
 ++*index;
 if (*index >= 10) *index = 0;
 func_800A848C(state + 0x1F4, 0, ceremonyDisplayResources[*index]);
 func_800B4794(1);
 *(u32 *)(state + 0xEB4) = ((St *)state)->tab[*index];
 func_800B4794(0);
}
