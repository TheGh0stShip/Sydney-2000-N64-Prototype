typedef struct VtblEntry {
    short delta;
    short index;
    void (*func)(void *self);
} VtblEntry;

typedef struct VObject {
    char pad[176];
    unsigned char active;
    char pad2[3];
    VtblEntry *vtbl;
} VObject;

typedef struct HandlePool {
    void *owner;
    void *first;
    void *second;
    int count;
    short head;
    short tail;
} HandlePool;

extern char D_800F2AD8[];
extern char D_800F26E0[];
extern char D_800F2758[];
extern char D_800F7270[];
extern char D_800F4D00[];
extern char D_80076F90[];
extern char D_80076D40[];
extern HandlePool D_800F26B0;
extern void func_8009BDC4(void *obj);
extern void func_800BC274(void *queue);
extern void func_800AACB0(void *list, void *obj, int arg);
extern void func_800762A8(void *obj, int arg);
extern void func_800AC25C(void *obj, int a1, int a2, int a3);
extern void func_800AA658(void *list, void *slot);
extern void func_80097A30(void *obj);
extern void func_800CCE4C(void *obj);
extern void func_800AC334(void *obj);
extern void func_800A8850(void *obj);
extern void func_800AEFA0(void *res);
extern void func_800D29E0(void *obj);
extern void func_800D771C(void *obj);
extern void func_800A2158(void *obj);
extern void func_800CEF1C(void *obj);
extern void func_80017B24(void *handle);
extern void func_800D7F5C(void *obj);
extern void func_800BAC24(void);
extern void func_8007E7A0(void *obj);
extern void func_800D52A8(void *obj);
extern void func_8009C100(void);

void func_800999B0(char *obj)
{
    char *hi;
    VObject *a;
    VObject *b;
    VObject *c;
    VObject *d;

    func_8009BDC4(obj);
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_800762A8(obj, 1);
    func_800AC25C(obj, 107, 7, 0);

    hi = obj + 0x8000;
    if (*(int *)(hi + 88) != 0) {
        func_800AA658(D_800F2758, obj + 0x8058);
    }
    if (*(int *)(hi + 140) != 0) {
        func_800AA658(D_800F2758, obj + 0x808C);
    }

    func_80097A30(obj + 15860);
    func_800CCE4C(obj + 31992);
    func_800AC334(obj + 32228);
    func_800A8850(obj + 32228);
    func_800AEFA0(D_80076F90);
    func_800D29E0(obj + 696);
    func_800AC334(obj + 696);

    a = (VObject *)(obj + 21124);
    func_800D771C(a);
    a->vtbl[3].func((char *)a + a->vtbl[3].delta);
    a->active = 0;

    b = (VObject *)(obj + 2096);
    b->vtbl[3].func((char *)b + b->vtbl[3].delta);
    b->active = 0;
    c = (VObject *)(obj + 3496);
    c->vtbl[3].func((char *)c + c->vtbl[3].delta);
    c->active = 0;
    d = (VObject *)(obj + 4896);
    d->vtbl[3].func((char *)d + d->vtbl[3].delta);
    d->active = 0;
    func_800D29E0(b);
    func_800D29E0(c);
    func_800D29E0(d);

    func_800A2158(obj + 12140);
    a = (VObject *)(obj + 14548);
    a->vtbl[3].func((char *)a + a->vtbl[3].delta);
    a->active = 0;
    func_800CEF1C(a);

    func_800AC334(obj + 216);
    func_80017B24(*(void **)(obj + 184));
    {
        char *p = obj + 11728;
        unsigned int i;
        func_800AEFA0(D_800F7270);
        func_800D7F5C(p);
        for (i = 0; i < 8; i++) {
            *(int *)(p + 184) = 0;
            p += 4;
        }
    }
    func_800AC334(obj + 11728);

    func_800BAC24();
    func_800AEFA0(D_80076D40);
    func_8007E7A0(obj + 6296);
    func_800AC334(obj + 6296);
    func_800D52A8(D_800F4D00);

    {
        void *owner = D_800F26B0.owner;
        if (owner != 0) {
            D_800F26B0.owner = 0;
            if (D_800F26B0.first != 0) {
                func_800AA658(owner, &D_800F26B0.first);
            }
            if (D_800F26B0.second != 0) {
                func_800AA658(owner, &D_800F26B0.second);
            }
            D_800F26B0.head = 0;
            D_800F26B0.tail = 0;
            D_800F26B0.count = 0;
            D_800F26B0.owner = 0;
        }
    }
    func_8009C100();
    *(int *)(obj + 172) = 1;
}
