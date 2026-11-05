typedef struct VEntry {
    short offset;
    short pad;
    void (*fn)();
} VEntry;

typedef struct Owner { char pad[20208]; unsigned char *leader; unsigned char *cur; } Owner;

typedef struct Pool {
    char pad0[8];
    void **base;
    void **top;
    short pad10;
    unsigned short count;
} Pool;

extern char D_80071440[];
extern char D_80078B90[];
extern char D_80089750[];
extern unsigned char D_80077BA0;
extern char D_800F2A70[];
extern unsigned char D_80077984[];
extern unsigned char *D_800FC270;

extern unsigned char *func_800AAA58(int size, void *mem);
extern void func_800BA1FC(void *object);
extern void func_800AED80(void *object);
extern void func_800ADED4(void *object);
extern void func_8009A828(void *object, int a, int b);
extern void func_80075510(void *owner, int a, int b);
extern void func_8007A718(void *object);

static inline unsigned char *create(unsigned char *owner)
{
    Pool *pool;
    unsigned char *obj;
    unsigned char *o;
    unsigned char *sub;
    VEntry *vt;

    pool = (Pool *)(owner + 20168);
    obj = 0;
    if (pool->top > pool->base) {
        pool->count--;
        pool->top--;
        obj = *pool->top;
        *pool->top = 0;
        o = func_800AAA58(1264, obj);
        func_800BA1FC(o);
        *(unsigned char **)(o + 180) = D_80071440;
        func_800AED80(o + 652);
        o[428] = 0;
        *(short *)(o + 638) = 0;
        o[202] = 0;
        *(int *)(o + 644) = 0;
        *(int *)(o + 648) = 0;
        *(int *)(o + 728) = 0;
        *(unsigned char **)(o + 180) = D_80078B90;
        func_800ADED4(o + 792);
        sub = o + 1004;
        func_800ADED4(sub);
        *(unsigned char **)(sub + 180) = D_80089750;
        *(int *)(o + 1004) = 85;
        *(int *)(o + 0) = 92;
    }
    if (obj != 0) {
        vt = *(VEntry **)(obj + 180);
        vt[2].fn(obj + vt[2].offset, owner);
    }
    return obj;
}

static inline void setup(unsigned char *obj, unsigned char *slot, unsigned char *tbl, unsigned char n, unsigned char a, unsigned char b, int idx)
{
    *(unsigned char **)(obj + 644) = slot;
    *(unsigned char **)(obj + 648) = tbl;
    obj[636] = b & 7;
    obj[733] = n;
    obj[424] = a;
    obj[425] = b;
    obj[426] = 4;
    obj[427] = idx;
}

void func_800E0CD8(unsigned char *owner)
{
    unsigned char *obj;
    unsigned char *leader;
    int n;
    unsigned char idx;
    int a;
    unsigned char **tbl;
    int b;

    if (*(int *)(owner + 20212) != 0) {
        return;
    }
    obj = create(owner);
    if (obj == 0) {
        return;
    }
    leader = ((Owner *)owner)->leader;
    ((Owner *)owner)->cur = obj;
    n = leader[733] + 1;
    a = leader[424];
    b = leader[425];
    idx = n;
    tbl = &D_800FC270;
    D_80077BA0 |= 1 << idx;
    setup(obj, owner + idx * 8 + 1564, D_800F2A70 + idx * 8, n, a, b, idx);
    *(unsigned char **)(owner + (owner[1549] << 2) + 1084) = obj;
    owner[1549]++;
    { unsigned char *p = &D_80077984[b]; unsigned char *q = *tbl + (signed char)a * 60; obj[735] = *p ^ q[30]; }
    func_8009A828(obj + 404, b, (signed char)a);
    func_80075510(owner, 1, idx);
    *(int *)(obj + 728) = *(int *)(leader + 728);
    *(unsigned int *)(obj + 192) = (*(unsigned int *)(obj + 192) | 0x1000000) & ~0x4000000;
    func_8007A718(obj);
    *(int *)(obj + 736) = 0;
}
