typedef unsigned char u8;
typedef int s32;
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern u8 *D_800FC270;
extern u8 D_800F3BC0[];
extern void func_800C0110(void *);

void func_800AF164(void)
{
    if (W(D_800FC270, 0xa04) != 0) {
        func_800C0110(D_800F3BC0);
    }
}
