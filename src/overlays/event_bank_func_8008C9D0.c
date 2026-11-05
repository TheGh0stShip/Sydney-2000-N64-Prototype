extern void func_8009BDC4(void);
extern void func_800BC274(void *obj);
extern void func_800AACB0(void *list, void *object, int mode);
extern void func_80075050(void *obj);
extern void func_800AC25C(void *obj, int a, int b, int c);
extern void func_800AA658(void *list, void *slot);
extern void func_800AC334(void *obj);
extern void func_800A8850(void *obj);
extern void func_800AEFA0(void *obj);
extern void func_800D29E0(void *obj);
extern void func_80097A30(void *obj);
extern void func_800CCE4C(void *obj);
extern void func_800D771C(void *obj);
extern void func_8009F7C8(void *obj);
extern void func_800CEF1C(void *obj);
extern void func_80076AF8(void *obj);
extern void func_80017B24(void *obj);
extern void func_800D7F5C(void *obj);
extern void func_800ADC1C(void *obj);
extern void func_800BAC24(void);
extern void func_8007E7A0(void *obj);
extern void func_800D52A8(void *obj);
extern void func_8009C100(void);
extern unsigned char D_800F2AD8[];
extern unsigned char D_800F26E0[];
extern unsigned char D_800F2758[];
extern unsigned char D_80077700[];
extern unsigned char D_800F7270[];
extern unsigned char D_80077410[];
extern unsigned char D_800F4D00[];

typedef struct {
    void *list;
    void *a;
    void *b;
    int c;
    short d;
    short e;
} Holder;

extern Holder D_800F26B0;

typedef struct {
    short offset;
    short pad;
    void (*func)();
} VEntry;

void func_8008C9D0(unsigned char *object)
{
    unsigned char *hi;
    unsigned char *p;
    unsigned char *a;
    unsigned char *b;
    unsigned char *c;
    VEntry *entry;
    void *list;
    unsigned int i;

    func_8009BDC4();
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_80075050(object);
    func_800AC25C(object, 107, 7, 0);
    hi = object + 0x8000;
    if (*(int *)(hi + 1052) != 0) {
        func_800AA658(D_800F2758, object + 0x841C);
    }
    if (*(int *)(hi + 1100) != 0) {
        func_800AA658(D_800F2758, object + 0x844C);
    }
    p = (unsigned char *)0x8264;
    p += (int)object;
    func_800AC334(p);
    func_800A8850(p);
    func_800AEFA0(D_80077700);
    p = object + 696;
    func_800D29E0(p);
    func_800AC334(p);
    func_80097A30(object + 26580);
    func_800CCE4C(object + 0x8184);
    p = object + 12136;
    func_800D771C(p);
    entry = (VEntry *)(*(unsigned char **)(p + 180) + 24);
    entry->func(p + entry->offset);
    p[176] = 0;
    a = object + 2096;
    entry = (VEntry *)(*(unsigned char **)(a + 180) + 24);
    entry->func(a + entry->offset);
    a[176] = 0;
    b = object + 3496;
    entry = (VEntry *)(*(unsigned char **)(b + 180) + 24);
    entry->func(b + entry->offset);
    b[176] = 0;
    c = object + 4896;
    entry = (VEntry *)(*(unsigned char **)(c + 180) + 24);
    entry->func(c + entry->offset);
    c[176] = 0;
    func_800D29E0(a);
    func_800D29E0(b);
    func_800D29E0(c);
    func_8009F7C8(object + 23196);
    func_800AC334(object + 25832);
    p = object + 31844;
    entry = (VEntry *)(*(unsigned char **)(p + 180) + 24);
    entry->func(p + entry->offset);
    p[176] = 0;
    func_800CEF1C(p);
    func_80076AF8(object);
    func_800AC334(object + 216);
    func_80017B24(*(void **)(object + 184));
    func_800AEFA0(D_800F7270);
    p = object + 11728;
    func_800D7F5C(p);
    for (i = 0; i < 8; i++) {
        *(int *)(p + 184) = 0;
        p += 4;
    }
    func_800AC334(object + 11728);
    p = object + 26356;
    func_800ADC1C(p);
    func_800AC334(p);
    func_800BAC24();
    func_800AEFA0(D_80077410);
    p = object + 6296;
    func_8007E7A0(p);
    func_800AC334(p);
    func_800D52A8(D_800F4D00);
    list = D_800F26B0.list;
    if (list != 0) {
        D_800F26B0.list = 0;
        if (D_800F26B0.a != 0) {
            func_800AA658(list, &D_800F26B0.a);
        }
        if (D_800F26B0.b != 0) {
            func_800AA658(list, &D_800F26B0.b);
        }
        D_800F26B0.d = 0;
        D_800F26B0.e = 0;
        D_800F26B0.c = 0;
        D_800F26B0.list = 0;
    }
    func_8009C100();
    *(int *)(object + 172) = 1;
}
