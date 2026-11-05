extern char D_80070A70[];
extern void func_800ADE84(void *p, int n);
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

void func_800C3D60(char *obj, int b)
{
    char *base;
    char *e;

    *(int *)(obj + 180) = (int)D_80070A70;
    func_800ADE84(obj + 19088, 2);
    func_800ADE84(obj + 18872, 2);
    base = obj + 18020;
    if (base != 0) {
        e = obj + 18868;
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
    base = obj + 17156;
    if (base != 0) {
        e = obj + 18004;
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
