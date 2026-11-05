typedef struct VtblEntry {
    short delta;
    short index;
    void (*func)(void *self, void *arg);
} VtblEntry;

typedef struct Pool {
    char pad[8];
    char **base;
    char **top;
    short unk10;
    unsigned short count;
} Pool;

extern char D_800712C0[];
extern char D_80078C30[];
extern char D_800F2A78[];
extern char *func_800AAA58(int size, void *place);
extern void func_800BA1FC(void *obj);
extern void func_800AED80(void *obj);
extern void func_800ADED4(void *obj);
extern void func_8007D398(void *obj, void *arg);
extern void func_8009A828(void *obj, int a, int b);
extern void func_8007C84C(void *obj);

void func_8009F940(char *owner)
{
    Pool *pool;
    char *src;
    char *entry;
    char *obj;
    char *result;
    short b;
    unsigned char a;
    char **top;

    if (*(char **)(owner + 23716) != 0) {
        return;
    }

    pool = (Pool *)(owner + 23672);
    entry = 0;
    if (pool->top > pool->base) {
        pool->count--;
        entry = *--pool->top;
        *pool->top = 0;
        obj = func_800AAA58(1500, entry);
        func_800BA1FC(obj);
        *(char **)(obj + 180) = D_800712C0;
        func_800AED80(obj + 652);
        obj[428] = 0;
        *(short *)(obj + 638) = 0;
        obj[202] = 0;
        *(int *)(obj + 644) = 0;
        *(int *)(obj + 648) = 0;
        *(int *)(obj + 728) = 0;
        *(char **)(obj + 180) = D_80078C30;
        func_800ADED4(obj + 1124);
        *(int *)obj = 102;
    }

    if (entry != 0) {
        VtblEntry *vt = *(VtblEntry **)(entry + 180);
        vt[2].func(entry + vt[2].delta, owner);
    }

    result = entry;
    if (result != 0) {
        src = *(char **)(owner + 23712);
        entry = result;
        *(char **)(owner + 23716) = entry;
        a = ((unsigned char *)src)[424];
        b = ((unsigned char *)src)[425];
        func_8007D398(entry, *(void **)(owner + 17948));
        *(char **)(entry + 644) = owner + 24056;
        *(char **)(entry + 648) = D_800F2A78;
        entry[426] = 4;
        entry[427] = 1;
        entry[425] = b;
        entry[424] = a;
        entry[636] = b & 7;
        func_8009A828(entry + 404, b, (signed char)a);
        *(int *)(entry + 728) = *(int *)(src + 728);
        *(unsigned int *)(entry + 192) = (*(unsigned int *)(entry + 192) | 0x1000000) & ~0x4000000;
        func_8007C84C(entry);
    }
}
