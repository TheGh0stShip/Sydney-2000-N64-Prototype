typedef struct {
    char pad0[0x4F4];
    float best8[11];        /* 0x4F4 */
    float best4[11];        /* 0x520 */
    char pad54c[0xA00 - 0x54C];
    int mode;               /* 0xA00 */
    char pada04[0xDDC - 0xA04];
    float best2[11];        /* 0xDDC */
} Race;
typedef struct {
    char pad0[4];
    float time;              /* 0x04 */
    char pad8[2];
    unsigned char flags;    /* 0x0A */
} Entry;
typedef struct {
    char pad0[2];
    short y;                /* 0x02 */
    char pad4[4];
    int arg;                /* 0x08 */
    char padc[4];
    int text;               /* 0x10 */
} Msg;
extern Race *D_800FC270;
extern float D_80100650;
extern void *memcpy(void *d, const void *s, unsigned int n);
extern Msg D_800F13F4;
extern unsigned short D_800F15E4[3][12];
extern void func_800D33A0(int a, Msg *m, int b, int c);

int func_8009B4D4(int idx, Entry *e, int kind, int who, int arg, unsigned short y)
{
    Race *r = D_800FC270;
    float t;
    unsigned char f;

    if (r->mode == 6) {
        return 0;
    }
    if (kind == 4) {
        return 0;
    }
    t = e->time;
    if (kind == 0) {
        Race *p = D_800FC270;

        if (p->mode == 5) {
            if (t < p->best2[idx]) {
                p->best2[idx] = t;
                e->flags |= 2;
            }
        } else {
            if (p->mode == 4) {
                if (t < p->best4[idx]) {
                    p->best4[idx] = t;
                    e->flags |= 4;
                }
            }
            if (t < D_800FC270->best8[idx]) {
                D_800FC270->best8[idx] = t;
                e->flags |= 8;
            }
        }
    }
    if (e->flags & 0xE) {
        memcpy(&D_80100650, &t, sizeof(t));
        f = e->flags;
        if (f & 8) {
            D_800F13F4.text = D_800F15E4[2][idx];
        } else if (f & 4) {
            D_800F13F4.text = D_800F15E4[1][idx];
        } else {
            D_800F13F4.text = D_800F15E4[0][idx];
        }
        D_800F13F4.arg = arg;
        D_800F13F4.y = y + 35;
        func_800D33A0(who, &D_800F13F4, 0, -1);
        return 1;
    }
    return 0;
}
