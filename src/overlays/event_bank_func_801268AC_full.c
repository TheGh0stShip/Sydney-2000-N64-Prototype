extern void func_8007B834(void *);
extern void func_800BBA1C(void *);
extern void func_8009C690(void *);
extern void func_8009D334(void *);
extern void func_800B3870(void *, void *, int);
extern void func_8009D85C(void *);
extern void func_800A9B78(void *, int, int, int, int);

#define B(o) (*(unsigned char *)(obj + (o)))
#define W(o) (*(int *)(obj + (o)))
#define F(o) (*(float *)(obj + (o)))
#define K(a) (*(float *)(a))

void func_801268AC(char *obj)
{
    float a = K(0x800813BC);
    float b = K(0x800813C0);
    float c = K(0x800813C4);
    unsigned char i;
    char *p;
    char *m;

    B(27000) = 0;
    B(2072) = 0;
    B(26980) = 0;
    W(27020) = 0;
    W(27016) = 0;
    B(800) = 0;
    W(792) = 0;
    W(804) = 0;
    W(2056) = 0;
    W(784) = 0;
    W(2060) = 0;
    W(2068) = 0;
    F(796) = a;
    F(788) = b;
    F(780) = a;
    F(776) = c;
    for (i = 0; i < 3; i++) {
        func_8007B834(*(void **)(obj + (i << 2) + 26984));
    }
    p = *(char **)(obj + 648);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    func_800BBA1C(obj + 748);
    if (B(426) != 4) {
        func_8009C690(obj + 2076);
        func_8009D334(obj + 2076);
    }
    m = obj + 1880;
    func_800B3870(m, *(char **)(obj + 26984) + 20, 76);
    F(1856) = K(0x800813C8);
    W(2044) = 0;
    func_8009D85C(obj + 2076);
    W(26996) = W(26992);
    func_800A9B78(obj + 1048, W(26996), 1, 1, 2);
    func_800B3870(m, *(char **)(obj + 26984) + 732, 76);
    *(float *)(m + 68) += K(0x800813CC);
}
