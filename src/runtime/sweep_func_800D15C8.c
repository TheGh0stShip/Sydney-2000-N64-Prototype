typedef struct {
    short delta;
    short index;
    void (*fn)();
} VEntry;

#define AT(self, off) ((char *)(self) + (off))
#define VTBL(self) (*(VEntry **)AT(self, 180))

extern char *D_800F63F0;
extern int D_80102880;
extern char D_800F4AE0[];
extern char D_800F4AF8[];
extern void func_800ADC54(void *, int);
extern void func_800ADC38(void *);
extern void func_800CE468(void *, int, int, int, int, int);
extern void func_800B31EC(int);
extern void func_800B360C(void *, void *);
extern void func_800B35F0(void *);

void func_800D15C8(void *self, unsigned char mode, int before, int after)
{
    char *ctx;
    void *panel;

    VTBL(self)[8].fn(AT(self, VTBL(self)[8].delta));
    ctx = D_800F63F0;
    VTBL(self)[2].fn(AT(self, VTBL(self)[2].delta), ctx);
    func_800ADC54(self, 1 << *(int *)(ctx + 216));
    *(unsigned char *)AT(self, 176) = 1;
    func_800ADC38(AT(self, 264));
    panel = AT(self, 900);
    func_800CE468(panel, 0, mode, 146, 3, 2);
    func_800ADC38(panel);
    D_80102880 = before;
    func_800B31EC(3);
    func_800B360C(AT(self, 1112), D_800F4AE0);
    D_80102880 = after;
    func_800B360C(AT(self, 1332), D_800F4AF8);
    func_800B35F0(AT(self, 1552));
    func_800B35F0(AT(self, 1772));
}
