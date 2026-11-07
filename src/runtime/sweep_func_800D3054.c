typedef struct VT { char p0[64]; short off; short p1; void (*fn)(char *); } VT;
typedef struct { char p0[180]; VT *vt; char p1[212 - 184]; } Elem;
typedef struct {
    char p0[172]; int state; char p1[180 - 176]; VT *vt;
    char p2[240 - 184]; int a240; char p3[252 - 244]; char snd[500 - 252];
    int a500; char p4[508 - 504]; char mtx[528 - 508]; Elem e[4];
    char p5[1384 - 528 - 4 * 212]; float pos; float spd; float lim; short h; unsigned short g;
} Obj;

extern void func_8001A1D8(char *, float, float, float, float);
extern void func_800B32D4(char *, int);
extern void func_800D29E0(Obj *);
extern void func_800D328C(Obj *);
extern void func_800D6EA0(char *);

void func_800D3054(Obj *o)
{
    unsigned char i;
    float f;

    switch (o->state) {
    case 0:
        o->a500 -= 256;
        if (o->a500 >= 0) break;
        o->pos += 6.0f;
        if (o->lim <= o->pos) {
            o->pos = o->lim;
            o->state = 1;
        }
        func_8001A1D8(o->mtx, 0.0f, 0.0f, o->spd, o->pos);
        func_800D328C(o);
        o->vt->fn((char *)o + o->vt->off);
        for (i = 0; i < 4; i++) {
            (o->e + i)->vt->fn((char *)&o->e[i] + (o->e + i)->vt->off);
        }
        break;
    case 1:
        o->h += 30;
        if (o->h >= 255) {
            o->h = 255;
            o->state = 2;
            o->a500 = o->a240;
        }
        func_800B32D4(o->snd, (unsigned char)o->h);
        break;
    case 2:
        if (o->a500 > 0) {
            o->a500 -= 256;
            if (o->a500 <= 0) {
                if (o->g == 0) {
                    o->h = 0;
                    o->pos = 0.0f;
                }
                o->state = 3;
            }
        }
        break;
    case 3:
        o->h -= 40;
        if (o->h > 0) {
            func_800B32D4(o->snd, (unsigned char)o->h);
            break;
        }
        func_800D6EA0(o->snd);
        o->state = 4;
    case 4:
        f = o->pos - 10.0f;
        o->pos = f;
        if (1.0f < f) {
            func_8001A1D8(o->mtx, 0.0f, 0.0f, o->spd, f);
            func_800D328C(o);
        } else {
            o->pos = 0.0f;
            func_800D29E0(o);
        }
        break;
    case 5:
        break;
    }
}
