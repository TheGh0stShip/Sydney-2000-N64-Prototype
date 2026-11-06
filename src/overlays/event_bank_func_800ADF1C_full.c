typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern u8 *D_800FC270;
extern u8 D_800F3BC0[];
extern void *D_800713C0[];
extern void func_800C0110(void *, s32, s32, s32);

void func_800ADF1C(void)
{
    static void *const unused_tbl[] = { &&c0, &&c1, &&c2, &&end, &&c4, &&c5, &&c6 };
    u32 st = W(D_800FC270, 0xa00);

    if (st >= 7)
        goto end;
    goto *D_800713C0[st];
c5:
    if (W(D_800FC270, 0xa04) != 0)
        func_800C0110(D_800F3BC0, 28, 768, 0);
    goto end;
c4:
    if (W(D_800FC270, 0xa04) == 5) {
        func_800C0110(D_800F3BC0, 462, 768, 0);
        if (W(D_800FC270, 0xa04) != 0) {
            func_800C0110(D_800F3BC0, 107, 768, 0);
            if (W(D_800FC270, 0xa04) != 0)
                func_800C0110(D_800F3BC0, 466, 768, 0);
        }
    }
    goto end;
c0:
    if (W(D_800FC270, 0xa04) == 1)
        func_800C0110(D_800F3BC0, 175, 768, 0);
    goto end;
c1:
    if (W(D_800FC270, 0xa04) == 1)
        func_800C0110(D_800F3BC0, 177, 768, 0);
    goto end;
c2:
    if (W(D_800FC270, 0xa04) == 1)
        func_800C0110(D_800F3BC0, 179, 768, 0);
    goto end;
c6:
    if (W(D_800FC270, 0xa04) != 0)
        func_800C0110(D_800F3BC0, 30, 0xd500, 0);
end:;
}
