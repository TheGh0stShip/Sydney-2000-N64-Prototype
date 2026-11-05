typedef struct { short offset; short pad; void (*fn)(); } VEntry;
typedef struct { char pad[72]; VEntry notify; } VTable;
typedef struct Obj { char pad[180]; VTable *vt; char pad2[192 - 184]; struct Obj *child; char pad3[208 - 196]; int a; int b; } Obj;

void func_800A9B78(Obj *obj, int value, int propagate, int extra, int mode)
{
    Obj *child;

    if ((unsigned int)(mode - 1) < 2) {
        obj->b = value;
    }
    if (mode == 0 || mode == 2) {
        obj->a = value;
    }
    if (propagate) {
        child = obj->child;
        if (child != 0 && value != 0) {
            child->vt->notify.fn((char *)child + child->vt->notify.offset, value, extra, mode);
        }
    }
}
