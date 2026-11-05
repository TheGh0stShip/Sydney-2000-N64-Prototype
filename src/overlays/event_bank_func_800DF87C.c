typedef struct VEntry {
    short offset;
    short pad;
    void (*fn)();
} VEntry;

typedef struct VObject {
    char pad[180];
    VEntry *vtbl;
} VObject;

typedef struct Link {
    void *list;
    void *a;
    void *b;
    int c;
    short d;
    short e;
} Link;

extern char D_800F2AD8[];
extern char D_800F26E0[];
extern char D_800F7270[];
extern char D_800F2758[];
extern char D_80077B90[];
extern char D_800F4D00[];
extern Link D_800F26B0;

extern void func_80077514(void);
extern void func_8009BDC4(void);
extern void func_800BC274(void *p);
extern void func_800BC0B4(void);
extern void func_800AACB0(void *p, void *q, int n);
extern void func_800AC25C(void *p, int a, int b, int c);
extern int func_80017D54(void);
extern void func_800AEFA0(void *p);
extern void func_800D7F5C(void *p);
extern void func_800AC334(void *p);
extern void func_80098D08(void *p);
extern void func_800ADC1C(void *p);
extern void func_800CCE4C(void *p);
extern void func_800AA658(void *list, void *slot);
extern void func_800A8850(void *p);
extern void func_800D6EA0(void *p);
extern void func_800D29E0(void *p);
extern void func_80017B24(int value);
extern void func_800D52A8(void *p);
extern void func_800BAC24(void);
extern void func_8007E7A0(void *p);
extern void func_8009C100(void);

#define VCALL(obj, idx) (obj)->vtbl[idx].fn((char *)(obj) + (obj)->vtbl[idx].offset)

void func_800DF87C(unsigned char *state)
{
    unsigned char *p;
    VObject *v;
    unsigned int i;
    void *list;
    Link *link;

    func_80077514();
    func_8009BDC4();
    func_800BC274(D_800F2AD8);
    func_800BC0B4();
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_800AC25C(state, 107, 7, 0);
    if (func_80017D54() != 0) {
        p = state + 1632;
        func_800AEFA0(D_800F7270);
        func_800D7F5C(p);
        for (i = 0; i < 8; i++) {
            ((int *)(p + 184))[i] = 0;
        }
        func_800AC334(state + 1632);
    }
    func_80098D08(state + 20560);
    v = (VObject *)(state + 19952);
    func_800ADC1C(v);
    VCALL(v, 3);
    ((unsigned char *)v)[176] = 0;
    func_800CCE4C(v);
    if (*(int *)(state + 1560) != 0) {
        func_800AA658(D_800F2758, state + 1560);
    }
    func_800A8850(state + 1116);
    func_800AEFA0(D_80077B90);
    func_800D6EA0(state + 14284);
    func_800AC334(state + 14284);
    func_800D29E0(state + 12884);
    func_800AC334(state + 12884);
    func_800AC334(state + 2016);
    func_80017B24(*(int *)(state + 192));
    func_800D52A8(D_800F4D00);
    link = &D_800F26B0;
    list = link->list;
    if (list != 0) {
        link->list = 0;
        if (link->a != 0) {
            func_800AA658(list, &link->a);
        }
        if (link->b != 0) {
            func_800AA658(list, &link->b);
        }
        link->d = 0;
        link->e = 0;
        link->c = 0;
        link->list = 0;
    }
    func_800BAC24();
    func_800AEFA0(state + 25424);
    func_800AC334(state + 14520);
    func_8007E7A0(state + 14520);
    func_800AC334(state + 1116);
    func_8009C100();
    func_800AACB0(D_800F26E0, state, 0);
    state[1551] = 0;
    *(int *)(state + 172) = 2;
}
