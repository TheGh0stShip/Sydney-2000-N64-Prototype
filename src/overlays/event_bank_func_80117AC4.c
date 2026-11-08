typedef struct VEntry {
    short delta;
    short pad;
    void (*fn)();
} VEntry;

typedef struct Inner {
    char pad0[40];
    float f28;
} Inner;

typedef struct Holder {
    char pad0[8];
    Inner *in;
} Holder;

typedef struct Part {
    char pad0[20];
    float m[19];        /* 20 */
    char pad1[180 - 96];
    VEntry *vt;         /* 180 */
    char pad2[196 - 184];
    int res;            /* 196 */
    char pad3[208 - 200];
    Holder *h;          /* 208 */
} Part;

typedef struct Obj {
    char pad0[732];
    Part *p;            /* 732 */
    char name[4];       /* 736 */
} Obj;

extern char D_800F2758[];

void func_800AA804(void *heap, void *slot, int size, char *tag);
void *func_800AAA58(int size, void *p);
void func_800ADED4(void *p);
int func_80013E7C(char *path, void *dst, int flags);
void func_800ADC54(void *p, int mask);
void func_800AD434(float *m, float a, int axis);
void func_800AD388(float *m, float a, int axis);
void func_800AD890(void *p, int on);
void func_800AD9E8(void *p);

void func_80117AC4(Obj *o, int mode, int *bit)
{
    float *m;

    func_800AA804(D_800F2758, &o->p, 212, "DIV_BRD");
    func_800ADED4(func_800AAA58(212, o->p));
    if (mode != 7) {
        o->p->res = func_80013E7C("GRAPHICS__ENVIRONMENTS__POOL__COMMONOBJECTS__DIVINGBN_OBB", o->name, 0);
    } else {
        o->p->res = func_80013E7C("GRAPHICS__ENVIRONMENTS__POOL__COMMONOBJECTS__DIVINGB_OBB", o->name, 0);
    }
    if (o->p->res != 0) {
        func_800ADC54(o->p, 1 << *bit);
        o->p->vt[2].fn((char *)o->p + o->p->vt[2].delta, o);
        {
            float *mm = o->p->m;
            mm[9] = 0.0f;
            mm[8] = 0.0f;
            mm[6] = 0.0f;
            mm[4] = 0.0f;
            mm[2] = 0.0f;
            mm[1] = 0.0f;
            mm[18] = 0.0f;
            mm[17] = 0.0f;
            mm[16] = 0.0f;
            mm[0] = mm[5] = mm[10] = 1.0f;
        }
        if (mode != 7) {
            func_800AD434(o->p->m, -1.5707961f, 3);
            func_800AD388(o->p->m, -1.5707961f, 3);
            m = o->p->m;
            m[16] = 1552.3365f;
            m[17] = 179.27632f;
            m[18] = 95.0243f;
        } else {
            m = o->p->m;
            m[16] = 1552.3365f;
            m[17] = 179.27632f;
            m[18] = -32.767f;
        }
        func_800AD890(o->p, 1);
        o->p->h->in->f28 = 327.669983f;
        func_800AD9E8(o->p);
        o->p->vt[8].fn((char *)o->p + o->p->vt[8].delta);
    }
}
