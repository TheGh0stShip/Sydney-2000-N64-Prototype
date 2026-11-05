extern unsigned char D_800F3BC0[];
extern unsigned char D_800F1AE0[];
extern void func_80017A90(unsigned int value);
extern void func_800C013C(void *object);
extern void func_800A3240(void *object);
extern void func_800A32CC(void *object);
extern void func_800AC334(void *object);
extern void func_800C0168(void *object);

void func_8009BDC4(void)
{
    func_80017A90(0x80000000);
    func_800C013C(D_800F3BC0);
    func_800A3240(D_800F1AE0);
    func_800A32CC(D_800F1AE0);
    func_800AC334(D_800F3BC0);
    func_800C0168(D_800F3BC0);
}
