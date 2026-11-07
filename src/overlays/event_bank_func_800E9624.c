typedef int s32;
typedef unsigned char u8;
typedef float f32;
typedef struct { f32 m[4][4]; f32 p[3]; } Mtx;
extern void func_80017B04(s32, f32);
extern void func_800AD9E8(u8 *);
extern void func_800B9FA4(u8 *, s32, s32, s32, s32, s32);
extern void func_800B9BD4(u8 *, s32, f32 *, f32 *, f32 *, s32);
extern void func_800B9964(u8 *, f32 *, f32 *, f32 *);
void func_8007B194(u8 *o, u8 flag)
{
    Mtx *m;
    Mtx *m2;
    Mtx *m3;
    f32 y;
    f32 *v;
    f32 a[4];
    f32 b[4];
    f32 c[2];
    y = 328.32535f;
    m = (Mtx *)(o + 20);
    m->m[2][1] = 0.0f;
    m->m[2][0] = 0.0f;
    m->m[1][2] = 0.0f;
    m->m[1][0] = 0.0f;
    m->m[0][2] = 0.0f;
    m->m[0][1] = 0.0f;
    m->p[2] = 0.0f;
    m->p[1] = 0.0f;
    m->p[0] = 0.0f;
    m->m[0][0] = m->m[1][1] = m->m[2][2] = 1.0f;
    func_80017B04(1, y);
    if (o[425] == 17 || o[425] == 3) {
        y = 329.96365f;
    }
    if (flag) {
        m2 = (Mtx *)(o + 20);
        m2->p[0] = 1669.4785f;
        m2->p[1] = y;
        m2->p[2] = 91.747597f;
    } else {
        m2 = (Mtx *)(o + 20);
        v = (f32 *)(o + 900);
        m2->p[0] = v[0];
        m2->p[1] = v[1];
        m2->p[2] = v[2];
    }
    func_800AD9E8(o);
    m3 = (Mtx *)(o + 20);
    v = (f32 *)(o + 368);
    v[0] = m3->p[0];
    v[1] = m3->p[1];
    v[2] = m3->p[2];
    v = (f32 *)(o + 392);
    v[0] = m3->p[0];
    v[1] = m3->p[1];
    v[2] = m3->p[2];
    func_800B9FA4(o, *(s32 *)(o + 892), -1, *(s32 *)(o + 632), 0, 0);
    if (!flag) {
        func_800B9BD4(o, 1, a, c, b, 0);
        func_800B9964(o, a, c, b);
    }
}
