typedef struct { short offset; short pad; void (*fn)(); } VEntry;
typedef struct { char pad[16]; VEntry attach; char pad2[64 - 24]; VEntry reset; } VTable;
typedef struct {
    char pad0[160];
    float x;
    float y;
    char pad1[176 - 168];
    unsigned char active;
    char pad2[180 - 177];
    VTable *vt;
    char pad3[192 - 184];
    unsigned int flags;
    int source;
    char pad4;
    unsigned char mode;
    char pad5[212 - 202];
} Particle;
typedef struct {
    char pad0[220];
    int sources[5];
    Particle particles[50];
    char pad1[10852 - 10840];
    unsigned short count;
} Emitter;
typedef struct { char pad[216]; int bit; } Config;

extern Config D_800F4D00;
extern void func_800ADC54(Particle *, int);

static __inline__ int source_valid(unsigned char i)
{
    return i < 5;
}

void func_800D75C0(Emitter *self, Emitter *owner)
{
    unsigned char i;
    int src;
    Particle *p;
    int mode;

    i = 0;
    mode = 2;
    for (; source_valid(i); i++) {
        p = &self->particles[self->count];
        src = self->sources[i];
        if (src == 0) {
            continue;
        }
        p->mode = mode;
        p->flags |= 0x20000;
        func_800ADC54(p, 1 << D_800F4D00.bit);
        p->source = src;
        p->flags |= 2;
        p->vt->reset.fn((char *)p + p->vt->reset.offset);
        p->vt->attach.fn((char *)p + p->vt->attach.offset, owner);
        p->active = 1;
        if (owner == self) {
            p->x = -222.0f;
            p->y = 1.0f;
        }
        self->count++;
        if (self->count >= 51) {
            break;
        }
    }
}
