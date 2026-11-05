typedef struct VtEntry {
    short offset;
    short pad;
    void (*func)(void *, ...);
} VtEntry;

#define VTABLE(o) ((VtEntry *)*(void **)((char *)(o) + 180))

typedef struct Pool {
    char pad[8];
    char **bottom;
    char **top;
    unsigned short capacity;
    unsigned short count;
} Pool;

typedef struct Pair {
    int a;
    int b;
} Pair;

typedef struct Bank {
    char pad0[1084];
    char *list[116];
    char pad1[1];
    unsigned char listCount;
    char pad2[14];
    Pair pairs[1];
} Bank;

extern char *func_800AAA58(int, char *);
extern void func_800BA1FC(char *);
extern void func_800AED80(void *);
extern void func_800ADED4(void *);
extern void func_8009A828(void *, int, int);
extern void func_8007B444(char *);
extern char D_800713D0[];
extern char D_80078DA8[];
extern char D_80089750[];
extern unsigned char D_80077730;
extern Pair D_800F2A70[];

static __inline__ char *spawn_from_pool(char *base)
{
    Pool *pool;
    char *obj;
    char *made;
    char *sub;

    pool = (Pool *)(base + 16652);
    obj = 0;
    if (pool->top > pool->bottom) {
        pool->count--;
        pool->top--;
        obj = *pool->top;
        *pool->top = 0;

        made = func_800AAA58(1516, obj);
        func_800BA1FC(made);
        *(void **)(made + 180) = D_800713D0;
        func_800AED80(made + 652);
        made[428] = 0;
        *(short *)(made + 638) = 0;
        made[202] = 0;
        *(int *)(made + 644) = 0;
        *(int *)(made + 648) = 0;
        *(int *)(made + 728) = 0;
        *(void **)(made + 180) = D_80078DA8;
        func_800ADED4(made + 824);
        sub = made + 1036;
        func_800ADED4(sub);
        *(void **)(sub + 180) = D_80089750;
        *(int *)(made + 1036) = 85;
        *(int *)(made + 1272) = 0;
        func_800ADED4(made + 1276);
        *(int *)made = 98;
        *(float *)(made + 1496) = -648.192138671875f;
    }

    if (obj != 0) {
        VTABLE(obj)[2].func(obj + VTABLE(obj)[2].offset, base);
    }
    return obj;
}

static __inline__ void attach_slot(char *obj, Pair *own, Pair *shared, int next, int kind, int flags, int slot)
{
    D_80077730 |= 1 << slot;
    *(Pair **)(obj + 644) = own;
    *(Pair **)(obj + 648) = shared;
    obj[636] = flags & 7;
    obj[733] = next;
    obj[424] = kind;
    obj[425] = flags;
    obj[426] = 4;
    obj[427] = slot;
}

void func_800860F8(char *base)
{
    char *obj;
    char *prev;
    int next;
    unsigned char slot;
    int kind;
    int flags;

    if (((char **)(base + 16672))[1] != 0) {
        return;
    }

    obj = spawn_from_pool(base);
    if (obj != 0) {
        prev = ((char **)(base + 16672))[0];
        ((char **)(base + 16672))[1] = obj;
        next = prev[733] + 1;
        kind = prev[424];
        flags = prev[425];
        slot = next;
        attach_slot(obj, &((Bank *)base)->pairs[slot], &D_800F2A70[slot], next, kind, flags, slot);
        ((Bank *)base)->list[((Bank *)base)->listCount] = obj;
        ((Bank *)base)->listCount++;
        func_8009A828(obj + 404, flags, (signed char)kind);
        *(int *)(obj + 728) = *(int *)(prev + 728);
        *(int *)(obj + 192) = (*(int *)(obj + 192) | 0x1000000) & ~0x4000000;
        func_8007B444(obj);
        *(int *)(obj + 748) = 0;
    }
}
