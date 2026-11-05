typedef struct { short offset; short pad; void (*fn)(); } VEntry;
typedef struct { char pad[16]; VEntry attach; VEntry detach; } VTable;
typedef struct { char pad[180]; VTable *vt; } Obj;
typedef struct {
    char pad0[16];
    int time;
    char pad1[188 - 20];
    void *hud;
    char pad2[19102 - 192];
    unsigned char busy;
} Scene;
typedef struct { int type; int time; char pad[4]; Obj *obj; int arg; } Msg;

extern char *D_800FC270;
extern int D_800F63E4;
extern char D_800F26E0[];
extern char D_800F11A0[];
extern void func_800DEAA0(Scene *, int, int);
extern void func_800DEC78(Scene *, Msg *);
extern void func_800AB2A4(void *, int, int, void *, int, int);
extern void func_80096398(void *, Obj *);
extern void func_80015EAC(int);
extern void func_800E8714(void *);
extern void func_800E9A48(void *, int);
extern void func_800177AC(void);

void func_800DEF98(Scene *self, Msg *msg)
{
    Obj *obj;

    switch (msg->type) {
    case 3:
        D_800FC270[520] = 0;
        break;
    case 7:
        self->busy = 0;
        func_800DEAA0(self, D_800F63E4, msg->arg);
        break;
    case 5:
        func_800DEC78(self, msg);
        break;
    case 19:
        obj = msg->obj;
        obj->vt->attach.fn((char *)obj + obj->vt->attach.offset, self);
        func_800AB2A4(D_800F26E0, msg->time, 3, obj, 0, 0);
        break;
    case 20:
        obj = msg->obj;
        obj->vt->detach.fn((char *)obj + obj->vt->detach.offset);
        func_80096398(D_800F11A0, obj);
        func_80015EAC(12);
        func_800E8714(self->hud);
        func_800E9A48(self->hud, 1);
        if (msg->arg == 57) {
            func_800AB2A4(D_800F26E0, msg->time, 7, self, 0, 57);
        } else {
            func_800AB2A4(D_800F26E0, msg->time, 7, self, 0, 15);
        }
        func_800177AC();
        break;
    }
    self->time = msg->time;
}
