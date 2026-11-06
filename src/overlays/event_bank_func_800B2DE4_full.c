typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef int s32; typedef short s16;
typedef struct { char pad[0x14]; u16 w; u16 h; } Res;
typedef struct { char pad[0x9FC]; s32 mode; u32 a00; s32 a04; u8 pad2[0xD53-0xA08]; u8 d53; u8 p54[4]; u8 flag; } G; extern G *D_800FC270;
extern s32 D_800F2728, D_800F2780, D_800F3884;
extern u32 D_800F2714, D_800F13F0;
extern char D_800F3BC0[], D_800F1AE0[]; extern void *D_800F272C[];
extern float D_80071304, D_80071308, D_8007130C, D_80071310, D_80071314, D_80071318;
typedef struct VFunc { short delta; short pad; void (*fn)(void *, void *); } VFunc;
typedef struct VObj { char pad[0xB0]; unsigned char active; char pad2[3]; VFunc *vtbl; } VObj;
typedef struct Ctx { char pad[0xD8]; int bit; } Ctx; extern Ctx D_800F4D00; extern void func_800ADC54(void *, int);
typedef struct Pool { void *heap; char *buf; void **list; void **cursor; unsigned short cap; unsigned short count; } Pool;
extern Pool D_800F26B0; extern char D_800F2758[]; extern char D_800707D0[], D_800707D8[];
extern int func_800AA804(void *, void *, int, char *);
extern void func_800AA658(void *, void *);
extern void func_800DAD10(void *, int, int, int);
extern void func_800B31EC(int);
extern int D_800479A8;
extern char D_80071218[], D_80071230[], D_80071250[], D_80071270[], D_80077640[];
extern void func_8007E0D8(void*, int, int, void*);
extern void func_800AEDC0(void*, void*, int); extern int func_800BA2D0(void*);
extern int func_800140A0(void*, int, int); extern void func_8009A680(int);
extern void func_80015EAC(s32); extern void func_800AC37C(void *, void *);
extern void func_800A32EC(void *, s32); extern void func_8009BE28(s32);
extern void func_800C023C(void *, s32); extern void func_8009BF34(s32, s32);
extern void func_80017D84(char *, s32);
extern void func_80017B50(void *); extern void func_800AE420(void *, void *);
extern void func_800D3FD0(void *, void *, int, int, int, int);
extern float stubf(int); extern void stub10(int,int,int,int,int,int,int,int,float,float); extern int stubi(int); extern void stubv(void *, float, float, float, float);
static inline u32 randRange(u32 n) { D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF; return ((D_800F2714 >> 15) * n) >> 16; }
static inline u32 randP(u32 *s, u32 n) { *s = (*s * 16807) & 0x7FFFFFFF; return ((*s >> 15) * n) >> 16; }
#define F(o,t) (*(t*)((char*)arg0+(o)))

extern char D_80077650[];
extern u16 func_8000EB20(char *); extern void func_80013208(void *, float, float, s32, s32);
extern void func_800AD890(void *, s32); extern void func_800ADC38(void *);
extern void func_800CCD60(void *, s32, s32); extern void func_800CCD10(void *, s32, s32, s32);
extern void func_8001A330(void *, s32); extern void func_8001A1D8(void *, float, float, float, float);
extern void func_8001A210(void *, float, float, float, float, s32); extern void func_800191E0(void *, u32);
extern void func_800A97D4(void *, void *, void *, void *); extern void func_800A9B78(void *, s32, s32, s32, s32);
extern u8 D_800F26E0[]; extern void *D_800F2744;
extern void func_800AB2A4(void *, void *, int, void *, int, int);
extern void func_800812EC(void *); extern void func_80074FB4(void *);
extern void *func_800D7A80(void *, int, float *, int, int);
extern void func_800D0D90(void *); extern void func_800EC010(void *); extern void func_800177AC(void);
typedef struct { void *head; char **buf; char **pool; char **cur; u16 cap; u16 count; } Pool2;
typedef struct VT { u8 pad[0x10]; s16 off; s16 pad2; void (*fn)(void *, void *); } VT;
typedef struct { u8 pad[0x40]; float x, y, z; } Sub;
typedef struct Obj { u8 pad0[0x60]; Sub sub; u8 pad1[0xB0 - 0x60 - sizeof(Sub)]; u8 on; u8 p3[3]; VT *vt;
    u8 p4[8]; u32 flags; u8 p5[5]; u8 c9; u8 p6[0xD4 - 0xCA]; } Obj;
typedef struct { u8 pad[0xD8]; s32 shift; } Cfg; extern Cfg *D_800F63F0;
#define INIT(o) do { Obj *_o = (Obj *)(o); _o->vt->fn((u8 *)_o + _o->vt->off, &D_800F4D00); \
    func_800ADC54(_o, 1 << D_800F4D00.bit); _o->on = 1; } while (0)
#define INIT2(o) do { Obj *_o = (Obj *)(o); Cfg *cf; _o->flags |= 0x20000; _o->c9 = 0; cf = D_800F63F0; \
    { float *v = (float *)((u8 *)(o) + 0x60); v[16] = 0.0f; v[17] = 6.0f; v[18] = 0.0f; } \
    _o->vt->fn((u8 *)_o + _o->vt->off, cf); func_800ADC54(_o, 1 << cf->shift); _o->on = 1; } while (0)
typedef struct { short off; short pad; void (*fn)(); } VEnt;
typedef struct { u8 pad[0x28]; float f28; } Obj28;
typedef struct { u8 pad[8]; Obj28 *o; } ObjD0;
typedef struct { u8 pad[0x10]; VEnt e10; u8 pad2[0x40-0x18]; VEnt e40; } VTbl;
typedef struct Slot { u8 pad[0xB4]; VTbl *vt; u8 pad2[0xD0-0xB8]; ObjD0 *d0; u8 pad3[0x134-0xD4]; } Slot;
typedef struct { float x, y, z; } Vec3;
#define B(o) (*(u8 *)((u8 *)c + (o)))
#define W(o) (*(u32 *)((u8 *)c + (o)))
#define H(o) (*(u16 *)((u8 *)c + (o)))
#define s7 arg0
#define c arg0
#define FL(o) (*(float *)((u8 *)c + (o)))
static __inline__ void Obj_init(Obj *o, Ctx *e, s32 one) { o->vt->fn((u8 *)o + o->vt->off, e); func_800ADC54(o, one << e->bit); o->on = one; }
static __inline__ void pool_free(Pool *p)
{
    void *h = p->heap;
    if (h != 0) {
        p->heap = 0;
        if (p->buf != 0) func_800AA658(h, &p->buf);
        if (p->list != 0) func_800AA658(h, &p->list);
        p->cap = 0; p->count = 0; p->cursor = 0; p->heap = 0;
    }
}
static __inline__ int pool_init(Pool *p, void *heap, unsigned short n, int size)
{
    char *b;
    if (p->heap != 0) return 0;
    p->heap = heap; p->cap = n;
    if (func_800AA804(heap, &p->list, n * 4, D_800707D0) == 0 &&
        func_800AA804(heap, &p->buf, n * size, D_800707D8) == 0) {
        p->cursor = p->list; b = p->buf;
        do { *p->cursor = b; b += size; p->cursor++; p->count++; n--; } while (n != 0);
        return 1;
    }
    pool_free(p);
    return 0;
}
void func_800B2DE4(u8 *arg0) {
    s32 seed; u32 r, t; G *g; u8 v; u16 i;
    char *heap; unsigned short n; char *b; void *h;
    func_80015EAC(6);
    D_800F2728 = 0;
    D_800F2780 = 0x4B000;
    seed = D_800F3884;
    if (seed == 0) seed = 1;
    r = (seed * 16807) & 0x7FFFFFFF;
    D_800F13F0 = r;
    t = (u32)-(r >> 15) >> 16;
    if (t == 0) t = 1;
    D_800F2714 = t;
    arg0[0x5B82] = 0; arg0[0x5B81] = 0; arg0[0x5B7D] = 0;
    g = D_800FC270;
    *(s32 *)(arg0 + 0x5B9C) = 0;
    switch (g->mode) {
    case 0:
        if (g->a04 != 0) arg0[0x5B7F] = ((u8 *)g)[0x9FF]; else arg0[0x5B7F] = 4;
        break;
    case 2:
        arg0[0x5B7F] = ((u8 *)g)[0x9FF];
        break;
    case 1:
        v = ((u8 *)g)[0x9FF];
        *(s32 *)(arg0 + 0x5B9C) = 1;
        arg0[0x5B7F] = v;
        break;
    }

    arg0[0x5B80] = arg0[0x5B7F];
    func_800C023C(D_800F3BC0, 6);
    func_800AC37C(D_800F3BC0, arg0);
    func_800A32EC(D_800F1AE0, 6);
    func_8009BE28(arg0[0x5B7F]);
    if (arg0[0x5B7F] != 4) {
        func_8009BF34(0x62, 0x3FFF);
    }
    switch (D_800FC270->a00) {
    case 3: case 5: case 6:
        func_80017D84("GRAPHICS__EVENTS__SKEET__OLYMPIC_BGP", -1);
        arg0[0x5B7C] = 1;
        break;
    case 0: case 1: case 2:
        func_80017D84("GRAPHICS__EVENTS__SKEET__NATIONAL_BGP", -1);
        arg0[0x5B7C] = 1;
        break;
    case 4:
        func_80017D84("GRAPHICS__EVENTS__SKEET__OLYMPIC_BGP", -1);
        switch (D_800FC270->a04) {
        case 2: arg0[0x5B7C] = 3; break;
        case 3: arg0[0x5B7C] = 2; break;
        case 5: arg0[0x5B7C] = 1; break;
        }
        break;
    }
    { Res *rs = (Res *)D_800F272C;
    F(0xBC,int)=3;
    F(0xB8,int)=0; F(0xC0,short)=0; F(0xC2,short)=0;
    F(0xC4,u16)=rs->w; F(0xC6,u16)=rs->h;
    F(0xD0,u32)=0xFF385C88;
    F(0xC8,float)=1.63835001f; F(0xCC,float)=16383.499f;
    F(0xD4,void*)=arg0+0xD8;
    func_80017B50(arg0+0xB8);
    F(0x250,int)=1; F(0x254,float)=950.24292f; F(0x258,float)=98.3009949f; F(0x25C,float)=-557.03894f;
    func_800AE420(arg0+0xD8, arg0+0x250);
    { char *a = arg0+0xD8; *(float*)(a+0xF4)=1.57079637f; func_800AC37C(a, arg0); }
    func_800D3FD0(&D_800F4D00, arg0, 1, 0xE2, 0x59, 0x82);
    }
    { int mode;
    { u32 rr; G *gg; rr = randRange(5); gg = D_800FC270;
    F(0x5BC0,u32) = rr + 205;
    switch (gg->a00) {
    case 0: mode = 12; break;
    case 1: mode = 13; break;
    case 2: mode = 14; break;
    case 3: case 4: case 5: case 6:
    default: mode = 15; break;
    } }
    D_800479A8 = 1;
    func_8007E0D8(arg0 + 19020, mode, 6, arg0 + 184);
    func_800AC37C(arg0 + 19020, arg0);
    func_800AEDC0(D_80077640, "PATHS__PATHSSKEET_PTB", 20);
    *(int *)(arg0 + 22968) = func_800BA2D0("ANIMATIONS__EVENTS__SKEET_ANB");
    *(int *)(arg0 + 22972) = func_800BA2D0("ANIMATIONS__EVENTS__SHOTGUN_ANB");
    *(int *)(arg0 + 21912) = func_800140A0("GRAPHICS__EVENTS__SKEET__SHOTGUN_SKB", -1, 1);
    func_8009A680(6);
    }
    heap = D_800F2758;
    func_800DAD10(heap, 300, 7, 3);
    pool_init(&D_800F26B0, heap, 10, 220);
    func_800B31EC(0);
  {
          Slot *s, *p;     char *q; Pool2 *pl; char *buf;     float step; Vec3 v;
    Ctx *cx = &D_800F4D00; u8 *p0 = s7 + 0x394;
    Obj *o; char *ks;
    Obj_init((Obj*)p0, cx, 1);
    Obj_init((Obj*)(s7 + 0x2E08), cx, 1); Obj_init((Obj*)(s7 + 0x2EF4), cx, 1); Obj_init((Obj*)(s7 + 0x346C), cx, 1);
    Obj_init((Obj*)(s7 + 0x39E4), cx, 1); Obj_init((Obj*)(s7 + 0x3F5C), cx, 1); Obj_init((Obj*)(s7 + 0x44D4), cx, 1);
    *(s32 *)(p0 + 0x2A68) = 0xC3;
    *(s32 *)(p0 + 0x2A6C) = 0xC2;
    F(0x38C, s32) = 0;
    func_80013208(s7 + 0x38C, 3.2767f, 3.2767f, func_8000EB20("GUNSIGHT"), 2);
    F(0x390, s32) = 0;
    func_80013208(s7 + 0x390, 3.2767f, 3.2767f, func_8000EB20("HIGHSIGHT"), 2);
    { Obj *o2 = (Obj *)(s7 + 0x2B8);
    F(0x37C, s32) = F(0x38C, s32);
    func_800AD890(o2, 1);
    o2->flags |= 0x400000;
    func_800ADC54(o2, 1);
    F(0x5B99, u8) = 1;
    func_800ADC38(o2);
    o2->flags |= 4; }
    func_800CCD60(s7 + 0x5254, 30, 16);
    func_800CCD10(s7 + 0x5254, 536, 205, 2);
    { Obj *o = (Obj *)(s7 + 0x5818); *(s32 *)o = 0; func_8001A330(o, 0xFFFF);
    func_8001A1D8(o, 0.0f, 1.0f, 602.0f, 15.0f);
    func_8001A210(o, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(o, 0x82000000); }
    { Obj *o = (Obj *)(s7 + 0x581C); *(s32 *)o = 0; func_8001A330(o, 0xFFFF);
    func_8001A1D8(o, 0.0f, 0.0f, 602.0f, 1.0f);
    func_8001A210(o, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(o, 0xFF000000); }
    { Obj *o = (Obj *)(s7 + 0x5820); *(s32 *)o = 0; func_8001A330(o, 0xFFFF);
    func_8001A1D8(o, 0.0f, 15.0f, 602.0f, 16.0f);
    func_8001A210(o, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(o, 0xFF000000); }
    { Obj *_o = (Obj *)(s7 + 0x559C); Cfg *cf;
    F(0x5660, s32) = F(0x5818, s32); F(0x5734, s32) = F(0x581C, s32); F(0x5808, s32) = F(0x5820, s32);
    _o->flags |= 0x20000; _o->c9 = 0; cf = D_800F63F0;
    { float *v = (float *)((u8 *)(s7 + 0x559C) + 0x60); v[16] = 0.0f; v[17] = 6.0f; v[18] = 0.0f; }
    _o->vt->fn((u8 *)_o + _o->vt->off, cf); func_800ADC54(_o, 1 << cf->shift); _o->on = 1; }
    INIT2(s7 + 0x5670);
    { Obj *_o = (Obj *)(s7 + 0x5744); Cfg *cf; i = 0; _o->flags |= 0x20000; _o->c9 = 0; cf = D_800F63F0;
    { float *v = (float *)((u8 *)_o + 0x60); v[16] = 0.0f; v[17] = 6.0f; v[18] = 0.0f; }
    _o->vt->fn((u8 *)_o + _o->vt->off, cf); func_800ADC54(_o, 1 << cf->shift); _o->on = 1; }
    ks = D_80077650;
    func_800AEDC0(ks, "PATHS__VDSKEET_PTB", 20);
    o = (Obj *)(s7 + 0x59C8);
    func_800AC37C(o, s7);
    func_800A97D4(o, s7 + 0xB8, "PATHS__VDSKEET_VDS", ks);
    func_800A9B78(o, F(0x532C, s32), 0, 1, 2);
    func_800AA804(D_800F2758, s7 + 0x5BA4, 14400, "KEYSTORE");
    F(0x5BA8, u16) = 900;
    F(0x5B78, u8) = 0; F(0x5B79, u8) = 0; F(0x5B7A, u8) = 0; F(0x5B7B, u8) = 0;
    F(0x5BAC, s32) = F(0x5BA4, s32);
    do { u8 *bb = s7 + i; i++; bb[0x5BC4] = 0x80; bb[0x5BCD] = 0; } while (i < 9);

    if (B(0x5B7F) == 2) { B(0x5B78) = 2; B(0x5B7B) = 2; }
    func_800AB2A4(D_800F26E0, D_800F2744, 24, c, 0, 0);
    { G *gg; B(0x5B81) = 0; gg = D_800FC270; W(0x5B74) = 0; W(0xAC) = 0;
    switch (gg->d53) {
    case 0: FL(0x5BB0) = 26.213598f; break;
    case 1: FL(0x5BB0) = 22.9369f; break;
    case 2: FL(0x5BB0) = 19.6602f; break;
    case 3: FL(0x5BB0) = 16.3835f; break;
    } }
    i = 0;
    while (1) {
        if (i >= 2) break;
        p = (Slot *)(c + (i * 0x134 + 0x5330));
        func_800812EC(p);
        s = (Slot *)((u8 *)(i * 0x134 + (u32)c) + 0x5330);
        s->vt->e10.fn((u8 *)p + s->vt->e10.off, c);
        i++;
        s->vt->e40.fn((u8 *)p + s->vt->e40.off);
        func_800ADC54(p, 1);
        func_800AD890(p, 1);
        s->d0->o->f28 = FL(0x5BB0);
        func_800AB2A4(D_800F26E0, D_800F272C[6], 3, p, 0, 0);
    }
    func_80074FB4(c);
    s = (void *)((char *)c + 0x5824);
    func_800AC37C(s, c);
    { u32 k; for (k = 0; k < 8; k++) ((u32 *)((char*)s + 0xB8))[k] = 0;
      for (k = 0; k < 4; k++) ((u32 *)((char*)s + 0xD8))[k] = 0; }
    *(short *)((char*)s + 0x17C) = 15;
    pool_init((Pool *)((char*)s + 0x160), D_800F2758, 30, 0x210);
    step = 32.767f; v.x = 98.300995f; { Vec3 *pv = &v; pv->y = 0.0f; pv->z = -196.60199f; }
    for (i = 0; i < 5; i++) {
        if (D_800FC270->flag) {
            *(void **)((i << 2) + c + 0x59A4) = func_800D7A80(c + 0x5824, 3, &v.x, 0, 1);
            v.x += step;
        }
    }
    W(0x5B84) = 0x5A00;
    func_800D0D90(c + 0x5BD8);
    func_800EC010(c + 0x6480);
    B(0x5B7E) = 1;
    func_800177AC();
  }
}
