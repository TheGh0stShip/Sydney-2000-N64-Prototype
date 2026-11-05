typedef struct { short offset; short pad; void (*fn)(); } VEntry;
typedef struct { char pad[32]; VEntry tick; } VTable;
typedef struct {
    char pad0[16];
    int time;
    char pad1[180 - 20];
    VTable *vt;
    char pad2[220 - 184];
    int lifeTimer;
    int fadeTimer;
    int blinkTimer;
    int blinkPeriod;
} Obj;
typedef struct { int type; int time; char pad[8]; int arg; } Msg;

extern void func_800D6F80(Obj *, int);
extern void func_800B2158(Obj *, int);
extern void func_800B34C4(Obj *);
extern void func_800D6EA0(Obj *);

void func_800D6FE4(Obj *self, Msg *msg)
{
    switch (msg->type) {
    case 3:
        func_800D6F80(self, msg->arg);
        break;
    case 5:
        if (self->lifeTimer > 0) {
            self->lifeTimer -= 256;
            if (self->lifeTimer <= 0) {
                func_800B2158(self, 1);
            }
        } else {
            if (self->blinkPeriod != 0) {
                self->blinkTimer -= 256;
                if (self->blinkTimer <= 0) {
                    self->blinkTimer += self->blinkPeriod;
                    func_800B34C4(self);
                }
            }
            if (self->fadeTimer > 0) {
                self->fadeTimer -= 256;
                if (self->fadeTimer <= 0) {
                    func_800D6EA0(self);
                }
            }
        }
        self->vt->tick.fn((char *)self + self->vt->tick.offset);
        break;
    case 7:
        func_800D6EA0(self);
        break;
    }
    self->time = msg->time;
}
