typedef struct {
    short delta;
    short index;
    void (*fn)();
} VEntry;

#define AT(self, off) ((char *)(self) + (off))
#define FLAGS(self) (*(unsigned char *)AT(self, 5384))
#define PENDING(self) (*(unsigned char *)AT(self, 5385))
#define VTBL(self) (*(VEntry **)AT(self, 180))

extern void func_800B35F0(void *);
extern void func_800AC334(void *);
extern void func_800ADC1C(void *);
extern void func_800CC310(void *);
extern void func_800B2158(void *, int);

void func_800D2328(void *self)
{
    void *obj;

    obj = AT(self, 2796);
    if (FLAGS(self) & 0x1E) {
        func_800B35F0(obj);
        func_800AC334(obj);
        obj = AT(self, 3016);
        func_800B35F0(obj);
        func_800AC334(obj);
        func_800ADC1C(AT(self, 1916));
        func_800ADC1C(AT(self, 1704));
        func_800ADC1C(AT(self, 1492));
        func_800CC310(AT(self, 3456));
    }
    if (FLAGS(self) & 1) {
        func_800ADC1C(AT(self, 1280));
        func_800ADC1C(AT(self, 1068));
        func_800ADC1C(AT(self, 856));
        func_800B2158(AT(self, 424), 0);
        func_800ADC1C(AT(self, 212));
        func_800ADC1C(AT(self, 644));
        func_800ADC1C(AT(self, 2552));
        func_800ADC1C(AT(self, 2340));
        func_800ADC1C(AT(self, 2128));
        VTBL(self)[9].fn(AT(self, VTBL(self)[9].delta));
        func_800B35F0(AT(self, 3236));
    }
    FLAGS(self) = 0;
    PENDING(self) = 0;
}
