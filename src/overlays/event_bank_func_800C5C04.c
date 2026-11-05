extern unsigned int D_800F2714;
extern unsigned char D_800F1AE0[];
extern float D_800723E0[3];
extern void func_800AD388(void *matrix, float angle, int axis);
extern void func_800AD2A8(void *matrix, void *in, void *out, int flags);
extern int func_8001D4B8(void *bank, int sound, int a, int b);
extern void func_8001D640(void *bank, int voice, int volume);
extern void func_800ADC38(void *object);
extern void func_800AD9E8(void *object);
extern int func_80071C4C(void *group, void *point);
extern void func_80083624(void *self, int message, int arg, int a, int b, int c);

#define UINT_FIX (*(const double *)0x80070910)
#define RAND_SCALE (*(const float *)0x80070918)
#define ANGLE_SCALE (*(const float *)0x8007091C)
#define ONE (*(const float *)0x80070920)
#define PULL_SCALE (*(const float *)0x80070924)
#define PULL_LIFT (*(const float *)0x80070928)

typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    float m[4][4];
    Vec3 t;
} Matrix;

static inline int scale_volume(int volume, int level)
{
    return (volume * level) >> 15;
}

static inline void mat_identity(Matrix *m, float one)
{
    m->m[2][1] = 0.0f;
    m->m[2][0] = 0.0f;
    m->m[1][2] = 0.0f;
    m->m[1][0] = 0.0f;
    m->m[0][2] = 0.0f;
    m->m[0][1] = 0.0f;
    m->t.z = 0.0f;
    m->t.y = 0.0f;
    m->t.x = 0.0f;
    m->m[2][2] = one;
    m->m[1][1] = one;
    m->m[0][0] = one;
}

typedef struct {
    char pad[64];
    Vec3 pos;
} Body;

static inline void copy_body_pos(Vec3 *out, Body *body)
{
    out->x = body->pos.x;
    out->y = body->pos.y;
    out->z = body->pos.z;
}

void func_800C5C04(unsigned char *p)
{
    Matrix rot;
    Vec3 dir;
    Vec3 out;
    Vec3 point;
    unsigned int seed;
    int bits;
    double d;
    float one;
    float k;
    float tx;
    int voice;
    Vec3 *pos;
    Vec3 *dst;
    Vec3 *target;
    Matrix *m;
    float angle;

    if (*(int *)(p + 18008) > 0 || p[18106] == 0) {
        return;
    }
    seed = (D_800F2714 * 16807) & 0x7FFFFFFF;
    bits = seed >> 19;
    d = bits;
    D_800F2714 = seed;
    if (bits < 0) {
        d += UINT_FIX;
    }
    angle = (float)d * RAND_SCALE * ANGLE_SCALE;
    one = ONE;
    dir.x = one;
    dir.y = 0.0f;
    dir.z = 0.0f;
    m = &rot;
    mat_identity(m, one);
    func_800AD388(m, angle, 3);
    func_800AD2A8(m, &dir, &out, 0);
    *(float *)(p + 18160) = *(float *)(p + 18020) * out.y;
    *(float *)(p + 18156) = *(float *)(p + 18020) * out.x;
    *(int *)(p + 18008) = *(int *)(p + 18012);
    voice = func_8001D4B8(D_800F1AE0, 135, 0, 1);
    func_8001D640(D_800F1AE0, voice, scale_volume(*(int *)(D_800F1AE0 + 104), 32767));
    *(int *)(p + 18016) = 256;
    func_800ADC38(p + 17784);
    target = (Vec3 *)D_800723E0;
    pos = &((Body *)(p + 17172))->pos;
    k = PULL_SCALE;
    tx = target->x;
    out.x = tx - pos->x;
    out.y = target->y - pos->y;
    out.z = target->z - pos->z;
    out.x = -out.x;
    out.y = -out.y;
    out.z = -out.z;
    dir.x = out.x * k;
    dir.y = out.y * k;
    dir.z = out.z * k;
    dir.y += PULL_LIFT;
    dst = (Vec3 *)(p + 17868);
    dst->x = tx + dir.x;
    dst->y = target->y + dir.y;
    dst->z = target->z + dir.z;
    func_800AD9E8(p + 17784);
    copy_body_pos(&point, (Body *)(p + 17172));
    if ((unsigned char)func_80071C4C(p + 17364, &point)) {
        p[18104] = 1;
    }
    if (--p[18106] == 0) {
        *(int *)(p + 18000) = 3;
    }
    func_80083624(p, 35, p[18106], 0, 0, 0);
}
