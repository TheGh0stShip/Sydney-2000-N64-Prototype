typedef struct { short offset; short pad; void (*fn)(); } VEntry;
typedef struct { VEntry entry[4]; } VTable;
typedef struct { char pad[16]; int time; char pad2[180 - 20]; VTable *vt; } Obj;
typedef struct { int type; int time; } Msg;
typedef struct { char pad[12]; Obj **tail; unsigned short cap; unsigned short count; } Pool;
extern char D_800F26E0[];
extern Pool D_800FCB30;
extern void func_800AACB0(void *, Obj *, int);

void func_800B3770(Obj *obj, Msg *msg)
{
    Pool *pool;

    switch (msg->type) {
    case 3:
    case 5:
        break;
    case 7:
        pool = &D_800FCB30;
        obj->vt->entry[3].fn((char *)obj + obj->vt->entry[3].offset);
        func_800AACB0(D_800F26E0, obj, 0);
        if (pool->count < pool->cap) {
            obj->vt->entry[1].fn((char *)obj + obj->vt->entry[1].offset, 2);
            *pool->tail = obj;
            pool->tail++;
            pool->count++;
        }
        break;
    }
    msg->time = obj->time;
}
