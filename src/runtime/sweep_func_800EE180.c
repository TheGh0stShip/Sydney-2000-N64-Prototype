typedef struct { short offset; short pad; void (*fn)(); } VEntry;
typedef struct { char pad[72]; VEntry stop; } VTable;
typedef struct {
    int id;
    char pad0[4];
    int kind;
    char pad1[45 - 12];
    unsigned char level;
    char pad2[52 - 46];
    int sound;
} Info;
typedef struct {
    char pad0[4];
    int owner;
    char pad1[16 - 8];
    int time;
    char pos[180 - 20];
    VTable *vt;
    char pad2[192 - 184];
    unsigned int flags;
    char pad3[212 - 196];
    int lifeTimer;
    int ageTimer;
    char pad4[224 - 220];
    int value;
    Info *info;
    int pending;
    int delay;
    int active;
    char link[4];
} Obj;
typedef struct { int type; int time; } Msg;

extern char D_800F26E0[];
extern int D_80100080[];
extern void func_800AEAE8(void *, Obj *);
extern void func_800AD434(void *, int, int);
extern void func_800EEDC4(Obj *, Msg *);
extern void func_800AB2A4(void *, int, int, ...);

void func_800EE180(Obj *self, Msg *msg)
{
    unsigned int level;

    switch (msg->type) {
    case 3:
        break;
    case 5:
        if (self->active == 0) {
            break;
        }
        func_800AEAE8(self->link, self);
        if ((unsigned int)(self->info->kind - 3) < 2) {
            func_800AD434(self->pos, self->info->sound, 3);
        }
        func_800EEDC4(self, msg);
        self->ageTimer -= 256;
        self->lifeTimer -= 256;
        if (self->lifeTimer < 0) {
            self->active = 0;
            self->vt->stop.fn((char *)self + self->vt->stop.offset);
            {
                int owner = self->owner;
                func_800AB2A4(D_800F26E0, msg->time, 12, owner, self, self->info->id);
            }
        }
        if (self->pending == 0) {
            break;
        }
        self->delay -= 256;
        if (self->delay >= 0) {
            break;
        }
        if (self->info->level == 0) {
            self->flags |= 4;
        } else {
            self->flags &= ~4;
        }
        level = self->info->level;
        if (level >= 9) {
            level = 0;
        }
        self->value = D_80100080[level];
        self->pending = 0;
        break;
    }
    self->time = msg->time;
}
