extern void *func_800AEF6C(void *table, int index);
extern void func_800AF088(void *entry, float *out);
extern char D_80077640[];

typedef struct {
    char pad[64];
    float pos[3];
} Body;

static inline void vec_copy(float *dst, float *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

static inline void body_pos_copy(float *dst, Body *body)
{
    dst[0] = body->pos[0];
    dst[1] = body->pos[1];
    dst[2] = body->pos[2];
}

void func_801019B4(unsigned char *object)
{
    float out[3];

    func_800AF088(func_800AEF6C(D_80077640, object[733]), out);
    vec_copy((float *)(object + 84), out);
    body_pos_copy((float *)(object + 368), (Body *)(object + 20));
    body_pos_copy((float *)(object + 392), (Body *)(object + 20));
}
