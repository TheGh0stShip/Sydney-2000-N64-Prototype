typedef struct { short adj; short pad; void (*fn)(); } VEnt;
typedef struct { char pad[0xC]; float v; } Axis;
typedef struct { char pad[0xC0]; int flags; char rest[212 - 0xC4]; } Sub;
typedef struct { int type; int val; } Msg;
typedef struct {
    char pad0[0x10];
    int val;
    char pad14[0xB4 - 0x14];
    VEnt *vt;
    char padb8[0x1A8 - 0xB8];
    char ctl[0x1B0 - 0x1A8];
    float src;
    float dst;
    float scale;
    char pad1bc[0x1C4 - 0x1BC];
    float cur;
    float ratio;
    float lim;
    Axis *in;
    int blink;
    int t[2];
    char pad1e0[0x1E4 - 0x1E0];
    Sub subs[2];
} Meter;

extern int D_800F2770;
extern Axis *func_8001A154(char *c);
extern Axis *func_8001A148(char *c);
extern void func_8001A188(char *c, float v, float w);
extern void func_8001A1B0(char *c, float v, float w);
extern void func_800AC308(Meter *m);

static inline void toggle(Sub *u) { u->flags ^= 4; }

void func_800CD480(Meter *m, Msg *msg)
{
    unsigned int i;
    int t;
    Axis *ax;
    Axis *ay;

    switch (msg->type) {
    case 5:
        m->vt[4].fn((char *)m + m->vt[4].adj);
        if (m->blink != 0) {
            i = 0;
            while (1) {
                if (i >= 2) break;
                t = m->t[i];
                if (t > 0) {
                    m->t[i] = t - 256;
                    if (t - 256 <= 0) {
                        m->t[i] = t;
                        toggle(&m->subs[i]);
                    }
                }
                i++;
            }
        }
        if (D_800F2770 != 0) {
            if (m->in != 0) {
                m->cur = m->in->v;
            }
            if (m->cur > m->lim) {
                m->cur = m->lim;
            }
            if (m->cur < 0.0f) {
                m->cur = 0.0f;
            }
            if (m->lim != 1.0f) {
                m->ratio = m->cur / m->lim;
            } else {
                m->ratio = m->cur;
            }
            m->dst = m->src;
            ax = func_8001A154(m->ctl);
            ay = func_8001A148(m->ctl);
            func_8001A188(m->ctl, m->scale * m->ratio, ax->v);
            func_8001A1B0(m->ctl, m->ratio, ay->v);
        }
        break;
    case 7:
        m->vt[3].fn((char *)m + m->vt[3].adj);
        func_800AC308(m);
        break;
    case 0:
        break;
    }
    m->val = msg->val;
}
