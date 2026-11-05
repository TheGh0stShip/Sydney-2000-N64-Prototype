typedef struct { short offset; short pad; void (*fn)(); } VEntry;
typedef struct { VEntry pad0; VEntry destroy; } VTable;
typedef struct { char pad[180]; VTable *vt; char pad2[212 - 184]; } Elem;
typedef struct { char pad[180]; void *vt; char pad2[188 - 184]; Elem elems[5]; } Group;
extern char D_80085798[];
extern void func_800AC3A4(void *, int);

void func_800A6B04(Group *group, int flags)
{
    Elem *p;

    group->vt = D_80085798;
    if (group->elems != 0) {
        p = group->elems + 5;
        while (group->elems != p) {
            p--;
            p->vt->destroy.fn((char *)p + p->vt->destroy.offset, 2);
        }
    }
    func_800AC3A4(group, flags);
}
