typedef unsigned char u8;
typedef signed char s8;
typedef struct GEnt { s8 s0; u8 u1; char pad2[6]; s8 s8_; char pad9[3]; } GEnt;
typedef struct G {
    char pad0[0x508];
    float f508;
    char pad50C[0x534 - 0x50C];
    float f534;
    char pad538[0xA00 - 0x538];
    int kind;
    int iA04;
    char padA08[0xA0C - 0xA08];
    u8 count;
    char padA0D[3];
    GEnt ents[1];
    char padA1C[0xDF0 - 0xA1C];
    float fDF0;
} G;
typedef struct P {
    char pad[0x1A8];
    u8 u1A8;
    u8 u1A9;
    char pad1AA[0x2FC - 0x1AA];
    int i2FC;
    char pad300[0x1100 - 0x300];
    int i1100;
} P;
typedef struct Ent { char pad[4]; u8 type; char pad5[0x1C - 5]; } Ent;
typedef struct Obj {
    char pad[0x59CC];
    P *p59CC;
    char pad59D0[0x75A8 - 0x59D0];
    s8 cur;
    char pad75A9[2];
    u8 u75AB;
    char pad75AC[0x75FC - 0x75AC];
    Ent *ents;
} Obj;
extern G *D_800FC270;
extern char D_800F3BC0[];
extern int D_800714B0[];
extern s8 func_8009B670(P *);
extern void func_800C0110(void *, int, int, int);
void func_800944A8(Obj *o)
{
    int id = -1;
    int found = 0;
    int kind = D_800FC270->kind;
    GEnt *ents = D_800FC270->ents;
    GEnt *e;
    int i;
    s8 x;
    s8 r;
    float f;
    if (o->u75AB < 2) {
        i = found;
        e = ents;
        while (1) {
            P *p;
            int m;
            if (found) break;
            p = o->p59CC;
            m = 0;
            if (p->u1A9 == e->u1) {
                if (p->u1A8 == e->s0) m = 1;
            }
            if (m) {
                found = 1;
            } else {
                e++;
                i++;
            }
        }
        x = ents[i].s8_;
        r = func_8009B670(o->p59CC);
        f = o->p59CC->i1100;
        f /= 100.0f;
        if (kind < 6) {
        if (kind >= 0) {
            if (kind == 5 ? D_800FC270->fDF0 < f : D_800FC270->f508 < f) {
                if (kind == 4) {
                    if (o->p59CC->i2FC == 0) id = 293;
                } else {
                    if (o->p59CC->i2FC == 0) id = 65;
                }
            } else if (kind == 4 && D_800FC270->f534 < f) {
                id = 292;
            } else if (o->p59CC->i2FC != 0 && o->ents[o->cur].type < 3) {
                id = 32;
            } else if (x == -1 || r < x) {
                if (r < D_800FC270->count - 1) {
                    id = D_800714B0[r];
                } else {
                    id = 99;
                }
            } else {
                return;
            }
        }
        }
        if (id != -1 && D_800FC270->iA04 != 0) {
            func_800C0110(D_800F3BC0, id, 0, 0);
        }
    }
}
