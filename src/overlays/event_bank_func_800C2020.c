typedef struct {
    char pad[0xC0];
    int flags;
    char pad2[0xD4 - 0xC4];
} Obj;

typedef struct {
    char pad0[0x4304];
    Obj a[4];
    char pad1[0x4664 - 0x4304 - 4 * 0xD4];
    Obj b[4];
    char pad2[0x4A90 - 0x4664 - 4 * 0xD4];
    Obj c;
    char pad3[0x4B78 - 0x4A90 - 0xD4];
    unsigned short count;
    char pad4[2];
    int timer;
    char pad5[2];
    unsigned char listA[20];
    unsigned char listB[20];
    unsigned char idxA;
    unsigned char idxB;
    unsigned char mode;
    unsigned char cur;
    char pad6[0x4BBC - 0x4BAE];
    int flag;
} Ctx;

extern unsigned int D_800F2714;
extern float D_80072AF0[][3];

typedef struct { char pad[0x40]; float v[3]; } Sub;

static __inline__ void setv(Sub *s, float *v) {
    s->v[0] = v[0];
    s->v[1] = v[1];
    s->v[2] = v[2];
}
static __inline__ void clr(Obj *o) { o->flags &= ~4; }
static __inline__ void set(Obj *o) { o->flags |= 4; }

void func_800C2020(Ctx *p) {
    float *v;

    p->timer--;
    if (p->mode == 0) {
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        p->cur = D_800F2714 >> 29;
        if (p->flag == 1) {
            v = D_80072AF0[p->cur];
            setv((Sub *)((char *)p + 0x4AA4), v);
            clr(&p->c);
            p->flag = 0;
            goto tail;
        }
    } else if (p->flag == 1) {
        p->cur = p->listA[p->idxA];
        v = D_80072AF0[p->listA[p->idxA++]];
        setv((Sub *)((char *)p + 0x4AA4), v);
        if (p->idxA == p->count) {
            p->idxA = 0;
        }
        clr(&p->c);
        p->flag = 0;
        goto tail;
    } else {
        p->cur = p->listB[p->idxB++];
        if (p->idxB == p->count) {
            p->idxB = 0;
        }
    }
tail:
    clr(&p->a[p->cur]);
    set(&p->b[p->cur]);
}
