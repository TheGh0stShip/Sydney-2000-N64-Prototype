extern char D_800F3BC0[];
extern char D_800F1AE0[];
extern char D_800F2AD8[];
extern char D_800F26E0[];
extern void func_800736D4(void);
extern void func_80017A90(int);
extern void func_800C013C(void *);
extern void func_8001D550(void *, int);
extern void func_800A3240(void *);
extern void func_800A32CC(void *);
extern void func_800AC334(void *);
extern void func_800C0168(void *);
extern void func_800BC274(void *);
extern void func_800AB240(void *);
extern void func_800A8850(void *);
extern void func_800AEFA0(void *);
extern void func_800AC308(void *);
extern void func_80017B24(int);
extern void func_800BAC24(void);
extern void func_8007E7A0(void *);
extern void func_80014384(void);
extern void func_800137FC(void);

void func_800741AC(char *self)
{
    if (*(unsigned char *)(self + 10338) != 0) {
        func_800736D4();
    }
    func_80017A90(0x80000000);
    func_800C013C(D_800F3BC0);
    func_8001D550(D_800F1AE0, 1);
    func_800A3240(D_800F1AE0);
    func_800A32CC(D_800F1AE0);
    func_800AC334(D_800F3BC0);
    func_800C0168(D_800F3BC0);
    func_800BC274(D_800F2AD8);
    func_800AB240(D_800F26E0);
    func_800AC334(self + 4660);
    func_800A8850(self + 4660);
    func_800AEFA0(self + 4644);
    func_800AEFA0(self + 4628);
    func_800AC308(self);
    func_800AC334(self + 868);
    func_80017B24(*(int *)(self + 836));
    func_800BAC24();
    func_8007E7A0(self + 4904);
    func_800AC334(self + 4904);
    func_80014384();
    func_800137FC();
}
