typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef struct { f32 x, y, z; } Vec;
typedef struct { f32 m[3][4]; u8 pad[16]; Vec t; } Mtx76;
typedef struct { u8 pad[4]; unsigned short id; u8 pad2[80 - 6]; s32 f80; } Sub;
typedef struct { s16 count; } Info;
typedef struct { u8 pad[28]; Info *info; } Src;
typedef struct {
    u8 pad0[196];
    Src *src;
    u8 pad1[212 - 200];
    s32 nsub;
    Sub *subA;
    u8 *subB;
    u8 pad2[232 - 224];
    f32 f232;
    u8 pad3[244 - 236];
    s32 f244;
    s16 f248;
    u8 pad4[324 - 250];
    s32 f324;
    Vec *scale;
    s32 f332;
    u8 pad5[340 - 336];
    s32 *morph;
    u8 pad6[352 - 344];
    Mtx76 *mats;
    u8 pad7[360 - 356];
    s32 f360;
} Obj;
extern void *D_800F2A30;
void func_800AA804(void *heap, void *dst, s32 size, char *name);
void func_8000A994(Src *src, s32 a);
static inline void setone(Vec *v)
{
    v->z = 1.0f;
    v->y = 1.0f;
    v->x = 1.0f;
}
static inline void ident(Mtx76 *mt)
{
    mt->m[2][1] = 0.0f;
    mt->m[2][0] = 0.0f;
    mt->m[1][2] = 0.0f;
    mt->m[1][0] = 0.0f;
    mt->m[0][2] = 0.0f;
    mt->m[0][1] = 0.0f;
    mt->t.z = 0.0f;
    mt->t.y = 0.0f;
    mt->t.x = 0.0f;
    mt->m[2][2] = 1.0f;
    mt->m[1][1] = 1.0f;
    mt->m[0][0] = 1.0f;
}
s32 func_800B7130(Obj *o, Src *src, s32 a2, f32 a3, s32 m)
{
    s32 n;
    s32 i;
    s32 j;
    n = src->info->count;
    o->src = src;
    func_800AA804(D_800F2A30, &o->mats, n * sizeof(Mtx76), "m_pMats");
    func_800AA804(D_800F2A30, &o->morph, n * sizeof(s32), "m_pMorph");
    func_800AA804(D_800F2A30, &o->scale, n * sizeof(Vec), "m_pScale");
    i = 0;
    while (1) {
        if (!(i < n)) break;
        ident(&o->mats[i]);
        o->morph[i] = 0;
        setone(&o->scale[i]);
        i++;
    }
    o->f332 = 0;
    o->f360 = a2;
    o->f244 = a2;
    o->f248 = 0;
    o->f324 = 0;
    o->nsub = m;
    if (m > 0) {
        o->subA = 0;
        func_800AA804(D_800F2A30, &o->subA, m * sizeof(Sub), "SubSkelA");
        for (j = 0; j < m; j++) {
            o->subA[j].id = 0xFFFF;
            o->subA[j].f80 = 0;
        }
        func_800AA804(D_800F2A30, &o->subB, n, "SubSkelB");
        for (j = 0; j < n; j++) {
            o->subB[j] = 0;
        }
    }
    o->f232 = a3;
    func_8000A994(src, a2);
    return 0;
}
