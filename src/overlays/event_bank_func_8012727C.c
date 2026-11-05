typedef struct VtEntry {
    short offset;
    short pad;
    void (*func)(void *, ...);
} VtEntry;

extern char D_8008A490[];
extern char D_80086598[];
extern void func_800CCE84(void *object, int mode);
extern void func_800D3460(void *object, int mode);
extern void func_800CE1EC(void *object, int mode);
extern void func_800CC4B4(void *object, int mode);
extern void func_800ADDA4(void *object, int mode);
extern void func_800CE380(void *object, int mode);
extern void func_800CD8A0(void *object, int mode);
extern void func_80004380(void *object);

#define DESTROY_ARRAY(base, count) \
    q = (base); \
    if (q != 0) { \
        p = (base) + (count) * 212; \
        if (q != p) { \
            char *arr = q; \
            do { \
                p -= 212; \
                vt = *(VtEntry **)(p + 180); \
                vt[1].func(p + vt[1].offset, 2); \
            } while (arr != p); \
        } \
    }

#define DESTROY_WITH_VTABLE(o) \
    { \
        char *part = (o); \
        *(void **)(part + 180) = D_80086598; \
        func_800ADDA4(part, 2); \
    }

void func_8012727C(char *self, int flags)
{
    char *p;
    char *q;
    char *head;
    VtEntry *vt;

    func_800CCE84(self + 24688, 2);
    func_800D3460(self + 23288, 2);
    func_800D3460(self + 21888, 2);
    func_800D3460(self + 20488, 2);
    func_800D3460(self + 19088, 2);
    func_800CE1EC(self + 17136, 2);
    func_800CC4B4(self + 15208, 2);
    head = self + 4340;
    *(void **)(head + 180) = D_8008A490;
    DESTROY_ARRAY(self + 4580, 50);
    DESTROY_WITH_VTABLE(head);
    DESTROY_WITH_VTABLE(self + 4120);
    DESTROY_WITH_VTABLE(self + 3900);
    DESTROY_WITH_VTABLE(self + 3680);
    DESTROY_WITH_VTABLE(self + 3460);
    func_800CE380(self + 3248, 2);
    func_800CD8A0(self + 2340, 2);
    func_800ADDA4(self + 2124, 2);
    func_800ADDA4(self + 1912, 2);
    func_800ADDA4(self + 1700, 2);
    func_800ADDA4(self + 1488, 2);
    DESTROY_ARRAY(self + 852, 3);
    func_800ADDA4(self + 640, 2);
    DESTROY_ARRAY(self + 216, 2);
    func_800ADDA4(self + 4, 2);
    if (flags & 1) {
        func_80004380(self);
    }
}
