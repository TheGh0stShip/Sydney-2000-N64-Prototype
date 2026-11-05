typedef struct VtEntry {
    short offset;
    short pad;
    void (*func)(void *, ...);
} VtEntry;

#define VCALL(o, slot) ((VtEntry *)*(void **)((char *)(o) + 180))[slot].func((char *)(o) + ((VtEntry *)*(void **)((char *)(o) + 180))[slot].offset)

typedef struct Pool {
    void *owner;
    void *first;
    void *second;
    int top;
    unsigned short capacity;
    unsigned short count;
} Pool;

extern void func_80077088(char *);
extern void func_8009BDC4(void);
extern void func_800BC274(void *);
extern void func_800BC0B4(void);
extern void func_800AACB0(void *, void *, int);
extern void func_800AC25C(char *, int, int, int);
extern void func_800AC334(void *);
extern void func_800AEFA0(void *);
extern void func_800D7F5C(void *);
extern void func_80098D08(void *);
extern void func_800ADC1C(void *);
extern void func_800CCE4C(void *);
extern void func_800EAE54(void *);
extern void func_800AA658(void *, void *);
extern void func_800A8850(void *);
extern void func_800D6EA0(void *);
extern void func_800D29E0(void *);
extern void func_800D771C(void *);
extern void func_80017B24(int);
extern void func_800D52A8(void *);
extern void func_800BAC24(void);
extern void func_8007E230(void *);
extern void func_8009C100(void);
extern char D_800F2AD8[];
extern char D_800F26E0[];
extern char D_800F7270[];
extern char D_800F2758[];
extern char D_80077720[];
extern char D_800F4D00[];
extern Pool D_800F26B0;

void func_80084EC0(char *obj)
{
    char *sub;
    char *sub2;
    unsigned int i;
    Pool *pool;

    func_80077088(obj);
    func_8009BDC4();
    func_800BC274(D_800F2AD8);
    func_800BC0B4();
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_800AC25C(obj, 107, 7, 0);

    sub = obj + 1632;
    func_800AC334(sub);
    func_800AEFA0(D_800F7270);
    func_800D7F5C(sub);
    for (i = 0; i < 8; i++) {
        *(int *)(sub + 184) = 0;
        sub += 4;
    }

    func_80098D08(obj + 16704);
    sub = obj + 16436;
    func_800ADC1C(sub);
    VCALL(sub, 3);
    sub[176] = 0;
    func_800CCE4C(sub);
    func_800EAE54(obj + 21668);
    if (*(void **)(obj + 1560) != 0) {
        func_800AA658(D_800F2758, obj + 1560);
    }
    func_800A8850(obj + 1116);
    func_800AEFA0(D_80077720);

    sub = obj + 14284;
    func_800D6EA0(sub);
    VCALL(sub, 3);
    sub[176] = 0;
    sub2 = obj + 12884;
    func_800D29E0(sub2);
    VCALL(sub2, 3);
    sub2[176] = 0;
    func_800D771C(obj + 2016);
    func_80017B24(*(int *)(obj + 192));
    func_800D52A8(D_800F4D00);

    pool = &D_800F26B0;
    sub2 = pool->owner;
    if (sub2 != 0) {
        pool->owner = 0;
        if (pool->first != 0) {
            func_800AA658(sub2, &pool->first);
        }
        if (pool->second != 0) {
            func_800AA658(sub2, &pool->second);
        }
        pool->capacity = 0;
        pool->count = 0;
        pool->top = 0;
        pool->owner = 0;
    }

    func_800BAC24();
    sub = obj + 14520;
    func_800AC334(sub);
    func_8007E230(sub);
    func_800AC334(obj + 1116);
    func_8009C100();
    func_800AACB0(D_800F26E0, obj, 0);
    obj[1551] = 0;
    *(int *)(obj + 172) = 2;
}
