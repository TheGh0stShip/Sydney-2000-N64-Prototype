typedef struct Msg {
    int type;
    int value;
    int pad[2];
    int arg;
} Msg;

typedef struct Obj {
    char pad[16];
    int value;
    char pad2[620];
    int target;
} Obj;

extern void func_800E9B88(Obj *, int);
extern void func_800E97F0(Obj *);
extern void func_800AB2A4(void *, int, int, int, int, int);
extern char D_800F26E0[];
extern int D_800F2744;

void func_800E9C18(Obj *obj, Msg *msg)
{
    switch (msg->type) {
    case 3:
        func_800E9B88(obj, 0);
        break;
    case 5:
        func_800E97F0(obj);
        break;
    case 7:
        func_800AB2A4(D_800F26E0, D_800F2744, 7, obj->target, 0, msg->arg);
        break;
    }
    obj->value = msg->value;
}
