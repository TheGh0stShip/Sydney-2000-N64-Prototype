extern void func_8009BDC4(void);
extern void func_800BC274(void *obj);
extern void func_800AACB0(void *list, void *object, int mode);
extern void func_800AC25C(void *obj, int a, int b, int c);
extern void func_800AA658(void *list, void *slot);
extern void func_800AC334(void *obj);
extern void func_800A8850(void *obj);
extern void func_800AEFA0(void *obj);
extern void func_800D29E0(void *obj);
extern void func_80097A30(void *obj);
extern void func_800CCE4C(void *obj);
extern void func_800D771C(void *obj);
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
extern unsigned char D_800F7270[];
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

extern void func_80074770(void *obj, int mode);
extern void func_80074EC4(void *obj);
extern unsigned char D_80076AF0[];

static __inline__ void ReleaseHolder(Holder *holder)
{
    void *list = holder->list;

    if (list != 0) {
        holder->list = 0;
        if (holder->a != 0) {
            func_800AA658(list, &holder->a);
        }
        if (holder->b != 0) {
            func_800AA658(list, &holder->b);
        }
        holder->d = 0;
        holder->e = 0;
        holder->c = 0;
        holder->list = 0;
    }
}

void func_8009370C(unsigned char *object)
{
    unsigned char *p;
    unsigned char *a;
    unsigned char *b;
    unsigned char *c;
    VEntry *entry;
    unsigned int i;

    func_8009BDC4();
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_80074770(object, 1);
    func_80074EC4(object);
    p = object + 23684;
    func_800AC334(p);
    func_800ADC1C(p);
    func_800AC25C(object, 107, 7, 0);
    p = object + 29452;
    entry = (VEntry *)(*(unsigned char **)(p + 180) + 24);
    entry->func(p + entry->offset);
    p[176] = 0;
    func_800ADC1C(p);
    func_800CCE4C(p);
    func_80097A30(object + 24188);
    if (*(int *)(object + 30128) != 0) {
        func_800AA658(D_800F2758, object + 30128);
    }
    if (*(int *)(object + 30204) != 0) {
        func_800AA658(D_800F2758, object + 30204);
    }
    if (*(int *)(object + 30200) != 0) {
        func_800AA658(D_800F2758, object + 30200);
    }
    if (*(int *)(object + 30192) != 0) {
        func_800AA658(D_800F2758, object + 30192);
    }
    p = object + 29688;
    func_800AC334(p);
    func_800A8850(p);
    func_800AEFA0(D_80076AF0);
    p = object + 11564;
    func_800D29E0(p);
    func_800AC334(p);
    p = object + 696;
    func_800D771C(p);
    func_800AC334(p);
    a = object + 12964;
    entry = (VEntry *)(*(unsigned char **)(a + 180) + 24);
    entry->func(a + entry->offset);
    a[176] = 0;
    b = object + 14364;
    entry = (VEntry *)(*(unsigned char **)(b + 180) + 24);
    entry->func(b + entry->offset);
    b[176] = 0;
    c = object + 15764;
    entry = (VEntry *)(*(unsigned char **)(c + 180) + 24);
    entry->func(c + entry->offset);
    c[176] = 0;
    func_800D29E0(a);
    func_800D29E0(b);
    func_800D29E0(c);
    ReleaseHolder(&D_800F26B0);
    func_800D52A8(D_800F4D00);
    ReleaseHolder(&D_800F26B0);
    func_800AC334(object + 216);
    func_80017B24(*(void **)(object + 184));
    func_800AEFA0(D_800F7270);
    p = object + 22596;
    func_800D7F5C(p);
    for (i = 0; i < 8; i++) {
        *(int *)(p + 184) = 0;
        p += 4;
    }
    func_800AC334(object + 22596);
    func_800BAC24();
    p = object + 17164;
    func_8007E7A0(p);
    func_800AC334(p);
    func_8009C100();
    *(int *)(object + 172) = 1;
}
