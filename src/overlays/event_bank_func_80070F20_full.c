/* Medal ceremony setup (C_Medal.cpp), ROM 0x70a30, link VRAM 0x80070F20. */
extern char *D_800FC270;
extern int D_800F2744;
extern char D_800F3BC0[];
extern char D_800F1AE0[];
extern unsigned short D_800F272C[];
extern float D_80073BB0[];
extern char D_800F2758[];
extern float D_80073BD4[];
extern float D_80073BF8[];
extern float D_80073C28[];
typedef struct { unsigned int v; } Seed;
extern Seed D_800F2714;
extern void *D_80073F58[];
extern void *D_80073F78[];
extern void *D_80073F80[];
extern int D_800456B4;
extern char D_80073FD0[];
extern volatile int D_800F2724;
extern char D_800F2AD8[];
extern char D_800F26E0[];
extern char D_800F26F4[];

extern void func_80037F30(void *p, int v, int n);
extern void func_80015EAC(int a);
extern void func_800C023C(void *a, int b);
extern void func_800AC37C(void *a, void *b);
extern void func_800A32EC(void *a, int b);
extern void func_80017B50(void *a);
extern void func_800AE420(void *a, void *b);
extern void func_80017D84(const char *s, int a);
extern void func_800AA804(void *a, void *b, int n, const char *s);
extern int func_800AAA58(int n, void *p);
extern void func_8007F23C(int a);
extern void func_8007E918(void *a, int b, int c, void *d);
extern void func_8007E1EC(int a);
extern void func_8007E0D8(void *a, int b, int c, void *d);
extern void func_8007EF58(int a);
extern void func_8007E46C(void *a, int b, int c, void *d);
extern void func_8007E434(int a);
extern void func_8007E100(void *a, int b, int c, void *d);
extern void func_8007E264(int a);
extern int func_800BA2D0(const char *s);
extern void func_800AAA60(const char *f, int l, const char *m);
extern int func_80013E7C(const char *s, int *h, int a);
extern void func_800ADC54(void *a, int b);
extern void func_800AD890(void *a, int b);
extern void func_800AD9E8(void *a);
extern void func_800ADC38(void *a);
extern void func_800A7610(void *a, int b, void *c, void *d);
extern void func_800AD388(void *a, float f, int b);
extern void func_800AD434(void *a, float f, int b);
extern void func_800A851C(void *a, int b, void *c, void *d);
extern void func_800AEDC0(void *a, const char *s, int n);
extern void func_800A97D4(void *a, void *b, const char *s, void *d);
extern int func_8007A760(int a, int b, int c);
extern void func_800B7130(void *a, int b, int c, int d, int e);
extern void func_800BA068(void *a, int b);
extern int func_800DAC28(int a);
extern void func_80017B04(int a, float f);
extern void func_800B9FA4(void *c, void *t, int a, float f, int b, int d);
extern void func_800B9E9C(void *c, void *t, int a, float f, int b);
extern void func_800B7578(void *a, int b, int c, int d, int e, float f, int g, int h);
extern void func_800B9DD0(void *a, int b, int c);
extern void func_800B9CDC(void *a, int b, int c);
extern void func_800B9AD0(void *a);
extern void func_800AD4E0(void *a, int b, int c);
extern void func_800BC274(void *a);
extern void func_800BC1E8(void *a, int b, int c, int d);
extern void func_800BBD78(void *a, int b, int c, void *d, int e);
extern void func_800AACB0(void *a, void *b, int c);
extern void func_800A9BE8(void *a, int b);
extern void func_800177AC(void);
extern void func_80073768(void *a, int b);
extern int func_8001D4B8(void *a, int b, int c, int d);
extern void func_8001D640(void *a, int b, int c);
extern void func_8001D5D8(void *a, int b, int c, int d, int e, int f);
extern void func_800AB9B8(void *a, void *b);

#define I32(p, o) (*(int *)((char *)(p) + (o)))
#define F32(p, o) (*(float *)((char *)(p) + (o)))
#define PTR(p, o) (*(char **)((char *)(p) + (o)))
#define U8(p, o) (*(unsigned char *)((char *)(p) + (o)))
#define U16(p, o) (*(unsigned short *)((char *)(p) + (o)))
#define S16(p, o) (*(short *)((char *)(p) + (o)))

typedef void (*VFn1)(char *);
typedef void (*VFn2)(char *, char *);

#define VCALL2(o, s) do { char *_o = (o); char *_v = PTR(_o, 180); \
    ((VFn2)PTR(_v, 20))(_o + S16(_v, 16), s); } while (0)
#define VCALL1(o) do { char *_o = (o); char *_v = PTR(_o, 180); \
    ((VFn1)PTR(_v, 68))(_o + S16(_v, 64)); } while (0)

#define VT1(o, a) do { char *_o = (o); char *_v = PTR(_o, 180); ((VFn1)PTR(_v, 68))((a) + S16(_v, 64)); } while (0)
#define VT2(o, a, s) do { char *_o = (o); char *_v = PTR(_o, 180); ((VFn2)PTR(_v, 20))((a) + S16(_v, 16), s); } while (0)
#define VC1(o, a) ((VFn1)PTR(PTR(o, 180), 68))((a) + S16(PTR(o, 180), 64))
#define VC2(o, a, s) ((VFn2)PTR(PTR(o, 180), 20))((a) + S16(PTR(o, 180), 16), s)

static inline void mtx_ident(char *m, float one)
{
    F32(m, 4) = F32(m, 8) = F32(m, 16) = F32(m, 24) = F32(m, 32) = F32(m, 36) = 0.0f;
    F32(m, 64) = F32(m, 68) = F32(m, 72) = 0.0f;
    F32(m, 0) = F32(m, 20) = F32(m, 40) = one;
}
static inline int vscale(int x, int v)
{
    return (x * v) >> 15;
}

static inline unsigned int RAND(unsigned int range)
{
    D_800F2714.v = (D_800F2714.v * 16807) & 0x7FFFFFFF;
    return ((D_800F2714.v >> 15) * range) >> 16;
}

typedef struct { float x, y, z; } Vec3;
static inline void vset(char *m, Vec3 *v)
{
    F32(m, 64) = v->x;
    F32(m, 68) = v->y;
    F32(m, 72) = v->z;
}

static inline void vcpy(char *d, Vec3 *v)
{
    F32(d, 0) = v->x;
    F32(d, 4) = v->y;
    F32(d, 8) = v->z;
}

static inline void setfl(char *o)
{
    I32(o, 192) = (I32(o, 192) & ~0x600) | 0x2000000;
}

static inline void fin(char *o)
{
    I32(o, 224) = 0x8000;
    func_800B9AD0(o);
}

static inline void fl4(char *o)
{
    U8(o, 185) = 1;
    U8(o, 184) = 0;
    U8(o, 186) = 1;
    U8(o, 187) = 1;
}

#define CHILD(s, n) ((s) + 1724 + (n) * 404)

void func_80070F20(char *self, int mode)
{
    int ids[3];
    int h;
    int *cfg;
    int type;
    float one;
    float ang;
    char *p;
    char *q;
    char *c;
    Vec3 *pos;
    Vec3 *src;
    char *cam;
    char *m;
    unsigned char n;
    int snd;

    h = 0;
    cfg = (int *)(D_800FC270 + 3388);
    func_80037F30(ids, 0, 12);
    func_80015EAC(12);
    I32(self, 5036) = D_800F2744;
    func_800C023C(D_800F3BC0, 12);
    func_800AC37C(D_800F3BC0, self);
    func_800A32EC(D_800F1AE0, 14);
    if (mode == 1)
        U8(self, 4456) = mode;
    else
        U8(self, 4456) = 0;
    I32(self, 2940) = 3;
    I32(self, 2936) = 0;
    S16(self, 2944) = 0;
    S16(self, 2946) = 0;
    U16(self, 2948) = D_800F272C[10];
    U16(self, 2950) = D_800F272C[11];
    I32(self, 2960) = 0xFF000000;
    cam = self + 2968;
    F32(self, 2952) = 1.63835001f;
    F32(self, 2956) = 16383.499f;
    PTR(self, 2964) = cam;
    func_80017B50(self + 2936);
    I32(self, 3344) = 1;
    F32(self, 3348) = D_80073BB0[0] + 39.3204002f;
    F32(self, 3352) = D_80073BB0[1] + 16.3834991f;
    F32(self, 3356) = D_80073BB0[2] + 81.9174957f;
    func_800AE420(cam, self + 3344);
    F32(cam, 244) = 1.57079637f;
    PTR(self, 184) = 0;
    PTR(self, 188) = 0;
    PTR(self, 196) = 0;
    PTR(self, 192) = 0;
    PTR(self, 200) = 0;
    I32(self, 216) = 0;

    switch (cfg[3]) {
    case 0:
        func_80017D84("GRAPHICS__CEREMONY__MEDALS_BGP", 0);
        func_800AA804(D_800F2758, self + 184, 5432, "Stadium");
        func_8007F23C(func_800AAA58(5432, PTR(self, 184)));
        func_8007E918(PTR(self, 184), 3, 0, self + 2936);
        VCALL2(PTR(self, 184), self);
        F32(self, 5024) = -1.63835001f;
        F32(self, 5020) = 1.65806258f;
        break;
    case 1:
        func_80017D84("GRAPHICS__CEREMONY__MEDALS_BGP", 0);
        func_800AA804(D_800F2758, self + 184, 5432, "Stadium");
        func_8007F23C(func_800AAA58(5432, PTR(self, 184)));
        func_8007E918(PTR(self, 184), 3, 1, self + 2936);
        VCALL2(PTR(self, 184), self);
        F32(self, 5024) = -1.63835001f;
        F32(self, 5020) = 1.65806258f;
        break;
    case 2:
        func_80017D84("GRAPHICS__CEREMONY__MEDALS_BGP", 0);
        func_800AA804(D_800F2758, self + 184, 5432, "Stadium");
        func_8007F23C(func_800AAA58(5432, PTR(self, 184)));
        func_8007E918(PTR(self, 184), 3, 2, self + 2936);
        VCALL2(PTR(self, 184), self);
        F32(self, 5024) = -2.29368997f;
        F32(self, 5020) = 1.83259547f;
        break;
    case 3:
        func_80017D84("GRAPHICS__CEREMONY__MEDALS_BGP", 0);
        func_800AA804(D_800F2758, self + 184, 5432, "Stadium");
        func_8007F23C(func_800AAA58(5432, PTR(self, 184)));
        func_8007E918(PTR(self, 184), 3, 3, self + 2936);
        VCALL2(PTR(self, 184), self);
        F32(self, 5024) = -0.655340016f;
        F32(self, 5020) = 1.83259547f;
        break;
    case 4:
        func_80017D84("GRAPHICS__CEREMONY__MEDALS_BGP", 0);
        func_800AA804(D_800F2758, self + 184, 5432, "Stadium");
        func_8007F23C(func_800AAA58(5432, PTR(self, 184)));
        func_8007E918(PTR(self, 184), 3, 4, self + 2936);
        VCALL2(PTR(self, 184), self);
        F32(self, 5024) = -0.655340016f;
        F32(self, 5020) = 2.00712848f;
        break;
    case 5:
        func_80017D84("GRAPHICS__CEREMONY__MEDALS_BGP", 0);
        func_800AA804(D_800F2758, self + 184, 5432, "Stadium");
        func_8007F23C(func_800AAA58(5432, PTR(self, 184)));
        func_8007E918(PTR(self, 184), 3, 5, self + 2936);
        VCALL2(PTR(self, 184), self);
        F32(self, 5024) = -2.12985516f;
        F32(self, 5020) = 1.79768896f;
        break;
    case 6:
        func_80017D84("GRAPHICS__ENVIRONMENTS__RANGE__OLYMPIC__OLYMPIC_BGP", 0);
        func_800AA804(D_800F2758, self + 192, 2056, "Range");
        func_8007E1EC(func_800AAA58(2056, PTR(self, 192)));
        func_8007E0D8(PTR(self, 192), 15, 6, self + 2936);
        VCALL2(PTR(self, 192), self);
        F32(self, 5024) = -0.983010054f;
        F32(self, 5020) = 1.83259547f;
        break;
    case 7:
        func_80017D84("GRAPHICS__ENVIRONMENTS__POOL__OLYMPIC__OLYMPIC_BGP", 0);
        func_800AA804(D_800F2758, self + 188, 1916, "Pool");
        func_8007EF58(func_800AAA58(1916, PTR(self, 188)));
        func_8007E46C(PTR(self, 188), 7, 7, self + 2936);
        VCALL2(PTR(self, 188), self);
        F32(self, 5024) = -1.80218506f;
        F32(self, 5020) = 1.98967516f;
        break;
    case 8:
        func_80017D84("GRAPHICS__ENVIRONMENTS__POOL__OLYMPIC__OLYMPIC_BGP", 0);
        func_800AA804(D_800F2758, self + 188, 1916, "Pool");
        func_8007EF58(func_800AAA58(1916, PTR(self, 188)));
        func_8007E46C(PTR(self, 188), 7, 7, self + 2936);
        VCALL2(PTR(self, 188), self);
        F32(self, 5024) = -1.80218506f;
        F32(self, 5020) = 1.98967516f;
        break;
    case 9:
        func_80017D84("GRAPHICS__ENVIRONMENTS__ARENA__OLYMPIC__OLYMPIC_BGP", 0);
        func_800AA804(D_800F2758, self + 196, 540, "Arena");
        func_8007E434(func_800AAA58(540, PTR(self, 196)));
        func_8007E100(PTR(self, 196), 19, 9, self + 2936);
        VCALL2(PTR(self, 196), self);
        I32(self, 216) = func_800BA2D0("ANIMATIONS__EVENTS__WEIGHTFACE_ANB");
        F32(self, 5024) = 0.655340016f;
        F32(self, 5020) = 1.83259547f;
        break;
    case 10:
        func_80017D84("GRAPHICS__ENVIRONMENTS__VELODROME__OLYMPIC__OLYMPIC_BGP", 0);
        func_800AA804(D_800F2758, self + 200, 328, "Velo");
        func_8007E264(func_800AAA58(328, PTR(self, 200)));
        func_8007E0D8(PTR(self, 200), 11, 10, (void *)1);
        VCALL2(PTR(self, 200), self);
        F32(self, 5024) = -1.31068003f;
        F32(self, 5020) = 1.91986191f;
        break;
    case 11:
        func_80017D84("GRAPHICS__CEREMONY__MEDALS_BGP", 0);
        func_800AA804(D_800F2758, self + 184, 5432, "Stadium");
        func_8007F23C(func_800AAA58(5432, PTR(self, 184)));
        func_8007E918(PTR(self, 184), 3, 0, self + 2936);
        VCALL2(PTR(self, 184), self);
        F32(self, 5024) = -1.80218506f;
        F32(self, 5020) = 1.98967516f;
        break;
    default:
        func_800AAA60("c:/dev/olympics_2000/code/common/C_Medal.cpp", 1247, "No event passed to medal ceremony");
        break;
    }

    U8(self, 4000) = 0;
    if (PTR(self, 184))
        U8(self, 4000) = 1;
    if (PTR(self, 192))
        U8(self, 4000) = 1;

    I32(self, 220) = 0;
    I32(self, 220) = func_80013E7C("GRAPHICS__CEREMONY__PODIUM_OBB", &h, 0);
    {
    char *p;
    char *m;
    p = self + 240;
    I32(self, 436) = I32(self, 220);
    func_800ADC54(p, 1);
    func_800AD890(p, 1);
    m = self + 260;
    I32(m, 64) = 0;
    I32(m, 72) = 0;
    F32(m, 68) = 9.17475986f;
    if (PTR(self, 196))
        F32(self, 328) += 16.3835011f;
    func_800AD9E8(p);
    func_800ADC38(p);
    }
    I32(self, 224) = 0;
    func_800A7610(self + 4464, 3, D_80073BD4, cfg);
    func_800AC37C(self + 4464, self);

    if ((unsigned int)(cfg[3] - 7) < 4) {
        char *p;
        char *q;
        I32(self, 224) = func_80013E7C("GRAPHICS__CEREMONY__SUSPENDER_OBB", &h, 0);
        p = self + 452;
        I32(self, 648) = I32(self, 224);
        func_800ADC54(p, 1);
        func_800AD890(p, 1);
        vset(self + 472, (Vec3 *)D_80073BD4);
        F32(self, 540) += 196.60199f;
        one = 1.0f;
        func_800AD9E8(p);
        n = 0;
        ang = -1.57079613f;
        VC1(self + 452, p);
        VC2(self + 452, p, self);
        for (; ({ n < 3; }); n++) {
            mtx_ident(self + n * 76 + 4792, one);
            q = self + (n * 76 + 4792);
            func_800AD388(q, ang, 3);
            func_800AD434(q, ang, 3);
            vcpy(self + n * 76 + 4856, (Vec3 *)D_80073BF8 + n);
            func_800A851C(self + 4464, n, self + 452, q);
        }
    } else {
        char *p;
        char *q;
        char *b;
        I32(self, 224) = func_80013E7C("GRAPHICS__CEREMONY__FLAGPOLEMEDAL_OBB", &h, 0);
        one = 1.0f;
        for (n = 0; ({ n < 3; }); ) {
            int i = n;
            p = self + (i * 212 + 452);
            b = self + i * 212;
            I32(b, 648) = I32(self, 224);
            func_800ADC54(p, 1);
            func_800AD890(p, 1);
            vset(b + 472, (Vec3 *)D_80073BD4 + i);
            func_800AD9E8(p);
            {
                char *_o = b + 452;
                char *_v = PTR(_o, 180);
                n++;
                ((VFn1)PTR(_v, 68))(p + S16(_v, 64));
            }
            VT2(b + 452, p, self);
            q = self + (i * 76 + 4792);
            mtx_ident(self + i * 76 + 4792, one);
            func_800AD434(q, -1.04719746f, 3);
            { char *r = self + i * 76; F32(r, 4860) = 78.6408005f; }
            F32(b, 540) -= i * 26.2135983f;
            func_800A851C(self + 4464, i, p, q);
        }
    }

    func_800AEDC0(self + 4248, "PATHS__VDMEDAL_PTB", 20);
    func_800AC37C(self + 4004, self);
    func_800A97D4(self + 4004, self + 2936, "PATHS__VDMEDAL_VDS", self + 4248);
    if ((unsigned int)(cfg[3] - 3) < 2)
        I32(self, 212) = func_800BA2D0("ANIMATIONS__CEREMONY__MEDALS2_ANB");
    else
        I32(self, 212) = func_800BA2D0("ANIMATIONS__CEREMONY__MEDALS_ANB");
    if (cfg[3] == 9)
        I32(self, 216) = func_800BA2D0("ANIMATIONS__EVENTS__WEIGHTFACE_ANB");

    one = 1.0f;
    D_800456B4 = 1;
    for (n = 0; ({ n < 3; }); n++) {
        int type;
        char *p;
        char *c;
        Vec3 *pos;
        Vec3 *src;
        type = cfg[3];
        if (type == 11)
            type = 12;
        ids[n] = func_8007A760(type, *(int *)((n << 2) + (char *)cfg), 6 - n);
        if (type == 12)
            type = 11;
        if (I32(self, 216)) {
            char *c;
            c = CHILD(self, n);
            func_800B7130(c, ids[n], I32(self, 212), 0, 1);
            func_800BA068(c, I32(self, 216));
        } else {
            func_800B7130(CHILD(self, n), ids[n], I32(self, 212), 0, 0);
        }
        p = CHILD(self, n);
        func_800AD890(p, 1);
        setfl(CHILD(self, n));
        func_800ADC54(p, 1);
        VC1(CHILD(self, n), p);
        pos = (Vec3 *)(self + n * 404 + 2092);
        src = (Vec3 *)D_80073BB0 + n;
        pos->x = src->x;
        pos->y = src->y;
        pos->z = src->z;
        F32(CHILD(self, n), 372) += D_80073C28[type * 17 + func_800DAC28(*(int *)((n << 2) + (char *)cfg))];
        if (PTR(self, 196))
            F32(CHILD(self, n), 372) += 16.3835011f;
        vset(CHILD(self, n) + 20, pos);
        func_800AD9E8(p);
        func_80017B04(0, -3276.69971f);
        switch (n) {
        case 0:
            D_800F2714.v = (D_800F2714.v * 16807) & 0x7FFFFFFF;
            func_800B9FA4(self + 1724, D_80073F58[D_800F2714.v >> 28], -1, one, 0, 0);
            D_800F2714.v = (D_800F2714.v * 16807) & 0x7FFFFFFF;
            func_800B9E9C(self + 1724, D_80073F58[D_800F2714.v >> 28], -1, one, 0);
            break;
        case 1:
            D_800F2714.v = (D_800F2714.v * 16807) & 0x7FFFFFFF;
            func_800B9FA4(self + 2128, D_80073F78[D_800F2714.v >> 30], -1, one, 0, 0);
            D_800F2714.v = (D_800F2714.v * 16807) & 0x7FFFFFFF;
            func_800B9E9C(self + 2128, D_80073F78[D_800F2714.v >> 30], -1, one, 0);
            break;
        case 2:
        default:
            func_800B9FA4(CHILD(self, n), D_80073F80[RAND(3)], -1, one, 0, 0);
            func_800B9E9C(CHILD(self, n), D_80073F80[RAND(3)], -1, one, 0);
            break;
        }
        if (I32(self, 216)) {
            char *c;
            c = CHILD(self, n);
            func_800B7578(c, 0, 33, 0, -1, one, 0, 1);
            func_800B9DD0(c, 0, -33);
            func_800B9CDC(c, 0, 2);
        }
        fin(CHILD(self, n));
    }

    I32(self, 236) = 0;
    I32(self, 232) = 0;
    I32(self, 228) = 0;
    D_800456B4 = 0;
    if (cfg[3] == 9) {
        I32(self, 228) = func_80013E7C("GRAPHICS__CEREMONY__GOLDMEDALLONG_OBB", &h, 0);
        I32(self, 232) = func_80013E7C("GRAPHICS__CEREMONY__SILVERMEDALLONG_OBB", &h, 0);
        I32(self, 236) = func_80013E7C("GRAPHICS__CEREMONY__BRONZEMEDALLONG_OBB", &h, 0);
    } else {
        I32(self, 228) = func_80013E7C("GRAPHICS__CEREMONY__GOLDMEDAL_OBB", &h, 0);
        I32(self, 232) = func_80013E7C("GRAPHICS__CEREMONY__SILVERMEDAL_OBB", &h, 0);
        I32(self, 236) = func_80013E7C("GRAPHICS__CEREMONY__BRONZEMEDAL_OBB", &h, 0);
    }
    I32(self, 1284) = I32(self, 228);
    I32(self, 1496) = I32(self, 232);
    I32(self, 1708) = I32(self, 236);
    for (n = 0; n < 3; n++) {
        char *p;
        p = self + (n * 212 + 1088);
        func_800ADC54(p, 1);
        func_800AD890(p, 1);
        VC1(self + n * 212 + 1088, p);
    }

    mtx_ident(D_80073FD0, 1.0f);
    func_800AD4E0(D_80073FD0, I32(self, 5020), 3);
    func_800AD388(D_80073FD0, 1.57079613f, 3);
    func_800AC37C(self + 2968, self);
    D_800F2724 = 1;
    func_800BC274(D_800F2AD8);
    func_800BC1E8(D_800F2AD8, 0, 0, *(signed char *)(D_800FC270 + 76));
    func_800BC1E8(D_800F2AD8, 0, 1, *(signed char *)(D_800FC270 + 76));
    func_800BBD78(D_800F2AD8, 13, 1, self, 2);
    func_800BBD78(D_800F2AD8, 12, 1, self, 2);
    func_800BBD78(D_800F2AD8, 0, 0, self, 3);
    func_800AACB0(D_800F26E0, self, 2);
    func_800AACB0(D_800F26E0, self, 1);
    I32(self, 5028) = 0x25800;
    U8(self, 4457) = 0;
    U8(self, 4460) = 0;
    U8(self, 4459) = 0;
    U8(self, 4458) = 0;
    U8(self, 4463) = 1;
    U8(self, 4462) = 1;
    U8(self, 4461) = 1;
    mtx_ident(self + 4284, 1.0f);
    fl4(self + 4264);
    func_800A9BE8(self + 4004, 0);
    func_800177AC();
    func_80073768(self, cfg[3]);
    snd = func_8001D4B8(D_800F1AE0, 95, 0, -1);
    func_8001D640(D_800F1AE0, snd, 0);
    func_8001D5D8(D_800F1AE0, snd, vscale(I32(D_800F1AE0, 104), 22936), 45, 0, 0);
    I32(self, 5032) = snd;
    func_8001D640(D_800F1AE0, func_8001D4B8(D_800F1AE0, 215, 0, 1), vscale(I32(D_800F1AE0, 104), 32767));
    U8(self, 204) = 0;
    U8(self, 205) = 0;
    if (U8(self, 4456))
        func_800AB9B8(D_800F26F4, self);
    I32(self, 4452) = 1;
}

