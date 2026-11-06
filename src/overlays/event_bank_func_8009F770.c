typedef struct {
    short offset;
    short pad;
    void (*fn)(void *self);
} VEntry;

typedef struct {
    unsigned char pad[180];
    VEntry *vtbl;
} VObj;

typedef struct {
    unsigned char pad[12];
    void **next;
    unsigned short capacity;
    unsigned short count;
} Pool;

typedef struct {
    int w[15];
} Slot;
#define VCALL(obj, n) ((obj)->vtbl[n].fn((char *)(obj) + (obj)->vtbl[n].offset))
#define VCALL2(obj, n, a) (((void (*)(void *, int))(obj)->vtbl[n].fn)((char *)(obj) + (obj)->vtbl[n].offset, a))

extern volatile int D_800F2724;
extern volatile int D_800F2728;
extern char D_800F2AD8[];
extern char D_800F26E0[];
extern char *D_800FC270;
extern void func_800BC274(void *arg);
extern void func_800AACB0(void *list, void *item, int mode);
extern void func_800D2328(void *arg);
extern void func_800D2760(void *arg);
extern void func_8001786C(int handle);
extern void func_80017B0C(int arg);

static inline void PoolFree(char *list, Pool *pool, char *player)
{
    VCALL((VObj *)player, 3);
    func_800AACB0(list, player, 0);
    if (pool->count < pool->capacity) {
        VCALL2((VObj *)player, 1, 2);
        *pool->next = player;
        pool->next++;
        pool->count++;
    }
}

void func_8009F770(char *self)
{
    unsigned char i;
    char *list;

    D_800F2724 = 0;
    D_800F2728 = 0;
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_800D2328(self + 18068);
    func_800D2760(self + 18068);
    i = 0;
    list = D_800F26E0;
    while (1) {
        if (i >= 2) break;
        {
        char **slot = (char **)(self + i * 4 + 23712);
        char *player = *slot;
        VObj *obj;
        Pool *pool;

        if (player != 0) {
            int id;

            func_800AACB0(list, player, 0);
            obj = (VObj *)(player + 1124);
            VCALL(obj, 3);
            VCALL(obj, 9);
            if ((unsigned char)player[426] != 4) {
                func_8001786C(*(int *)(*slot + 728));
                func_80017B0C(2);
            }
            id = player[424];
            if (id != 8) {
                { char *b = D_800FC270; int off = id * 60; ((Slot *)(b + off))->w[18] = 0; }
            }
            PoolFree(list, (Pool *)(self + 23672), *slot);
            *slot = 0;
        }
        }
        i++;
    }
}
