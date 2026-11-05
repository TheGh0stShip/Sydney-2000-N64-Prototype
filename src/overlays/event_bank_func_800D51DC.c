extern char D_80070968[];
extern void func_80081DC8(void *p, int b);

typedef struct {
    short pad0;
    short pad2;
    short pad4;
    short pad6;
    short offset;
    short pad10;
    void (*dtor)(void *self, int flags);
} VTable;

void func_800D51DC(char *obj, int b)
{
    char *base;
    char *e;

    *(int *)(obj + 180) = (int)D_80070968;
    base = obj + 17788;
    if (base != 0) {
        e = obj + 19696;
        if (base != e) {
            char *first = base;
            do {
                VTable *vt;
                e -= 212;
                vt = *(VTable **)(e + 180);
                vt->dtor(e + vt->offset, 2);
            } while (first != e);
        }
    }
    base = obj + 17144;
    if (base != 0) {
        e = obj + 17780;
        if (base != e) {
            char *first = base;
            do {
                VTable *vt;
                e -= 212;
                vt = *(VTable **)(e + 180);
                vt->dtor(e + vt->offset, 2);
            } while (first != e);
        }
    }
    func_80081DC8(obj, b);
}
