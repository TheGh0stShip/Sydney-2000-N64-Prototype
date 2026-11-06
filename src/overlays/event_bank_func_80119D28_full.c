/* event_bank whole function 0x119D28..0x11A1AC plus three leaf functions to 0x11A204.
 * Linked at 0x8007ECC8 (VRAM delta 0x7FF64FA0); rodata at 0x8007E730. */
typedef void (*VFn1)(char *);
typedef void (*VFn2)(char *, char *);

#define I32(p, o) (*(int *)((char *)(p) + (o)))
#define U32(p, o) (*(unsigned int *)((char *)(p) + (o)))
#define F32(p, o) (*(float *)((char *)(p) + (o)))
#define PTR(p, o) (*(char **)((char *)(p) + (o)))
#define U8(p, o) (*(unsigned char *)((char *)(p) + (o)))
#define S16(p, o) (*(short *)((char *)(p) + (o)))

typedef struct {
    float x, y, z;
} V3;

typedef struct {
    int id;
    float pos[3];
    float rot[9];
} Entry;

typedef struct {
    int flags;
    unsigned int level;
    char *name;
    int flagB;
    int flagA;
    int kind;
} Def;

extern char D_800F2758[];
extern char *D_800FC270;
extern Entry *D_800809CC[];
extern Def *D_800809E4[];
extern char D_80065BB0[];
extern char D_80065D10[];
extern char D_80065C60[];

extern void func_800AA804(void *, void *, int, const char *);
extern int func_80013E7C(char *, void *, int);
extern void *func_800AAA58(int, void *);
extern void func_800ADED4(void *);
extern void func_800ADC54(char *, int);
extern void func_800148F8(char *, char *);
extern void func_800AD2A8(char *, int, char *, int);
extern void func_800AD890(char *, int);

static inline void vcall2(char *o, char *s)
{
    char *v = PTR(o, 180);
    ((VFn2)PTR(v, 20))(o + S16(v, 16), s);
}

static inline void vcall1(char *o)
{
    char *v = PTR(o, 180);
    ((VFn1)PTR(v, 68))(o + S16(v, 64));
}

void func_80119D28(char *self, int mode, int arg2)
{
    unsigned int idx;
    Entry *list;
    Def *defs;
    unsigned int i;
    int ok;
    int prev;
    char *tmp;

    prev = -1;
    ok = 0;
    switch (mode) {
    case 0:
        idx = 0;
        break;
    case 1:
        idx = 1;
        break;
    case 3:
        idx = 2;
        break;
    case 5:
        idx = 3;
        break;
    case 2:
        idx = 5;
        break;
    case 4:
        idx = 4;
        break;
    default:
        I32(self, 196) = 0;
        return;
    }
    list = D_800809CC[idx];
    defs = D_800809E4[idx];
    I32(self, 196) = 0;
    while (({ list[I32(self, 196)].id; }) != -1)
        I32(self, 196)++;
    func_800AA804(D_800F2758, self + 200, I32(self, 196) * 212, "DRESSOBJ");
    for (i = 0; ({ i < U32(self, 196); }); i++) {
        if (prev != list[i].id) {
            if (defs[list[i].id].level <= U8(D_800FC270, 3416)
                && !(list[i].id == 0 && arg2 == 2 && idx < 2))
                ok = func_80013E7C(defs[list[i].id].name, &tmp, 0) != 0;
            else
                ok = 0;
            prev = list[i].id;
        }
        if (ok) {
            char *o;
            char *m;
            char *v;
            func_800ADED4(func_800AAA58(212, PTR(self, 200) + i * 212));
            I32(i * 212 + PTR(self, 200), 196) = *(int *)PTR(tmp, 12);
            func_800ADC54(i * 212 + PTR(self, 200), 1);
            U8(i * 212 + PTR(self, 200), 177) = 0;
            {
                int f = defs[list[i].id].flags;
                I32(i * 212 + PTR(self, 200), 192) |= f;
            }
            I32(i * 212 + PTR(self, 200), 0) = 60;
            if (defs[list[i].id].flagA)
                I32(i * 212 + PTR(self, 200), 192) |= 0x600;
            if (defs[list[i].id].flagB)
                I32(i * 212 + PTR(self, 200), 192) |= 0x4000;
            if (defs[list[i].id].kind) switch (defs[list[i].id].kind) {
            case 1:
                func_800148F8(i * 212 + PTR(self, 200), D_80065BB0);
                break;
            case 2:
                func_800148F8(i * 212 + PTR(self, 200), D_80065D10);
                break;
            case 3:
                func_800148F8(i * 212 + PTR(self, 200), D_80065C60);
                break;
            }
            vcall2(i * 212 + PTR(self, 200), self);
            vcall1(i * 212 + PTR(self, 200));
            o = PTR(self, 200) + i * 212;
            o = i * 212 + PTR(self, 200);
            m = o + 20;
            F32(m, 0) = F32(&list[i], 16);
            F32(m, 4) = F32(&list[i], 20);
            F32(m, 8) = F32(&list[i], 24);
            F32(m, 16) = F32(&list[i], 28);
            F32(m, 20) = F32(&list[i], 32);
            F32(m, 24) = F32(&list[i], 36);
            F32(m, 32) = F32(&list[i], 40);
            F32(m, 36) = F32(&list[i], 44);
            F32(m, 40) = F32(&list[i], 48);
            ((V3 *)(m + 64))->x = list[i].pos[0];
            ((V3 *)(m + 64))->y = list[i].pos[1];
            ((V3 *)(m + 64))->z = list[i].pos[2];
            func_800AD2A8(m, *(int *)PTR(tmp, 16), o + 84, 1);
            func_800AD890(i * 212 + PTR(self, 200), 1);
            v = PTR(PTR(i * 212 + PTR(self, 200), 208), 8);
            F32(v, 12) = F32(m, 64);
            F32(v, 16) = F32(m, 68);
            F32(v, 20) = F32(m, 72);
        } else {
            I32(i * 212 + PTR(self, 200), 196) = 0;
        }
    }
}

void func_8011A1AC(char *self, unsigned short idx, char **out)
{
    if (idx >= U32(self, 196)) {
        *out = 0;
        return;
    }
    *out = PTR(self, 200) + idx * 212;
}

void func_8011A1F0(void)
{
}

void func_8011A1F8(char *a, char *b)
{
    I32(a, 16) = I32(b, 4);
}
