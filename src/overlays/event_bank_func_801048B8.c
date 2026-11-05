extern void *func_800AEF6C(void *table, int index);
extern void func_800AE72C(void *dst, void *object, void *entry);

typedef struct {
    char pad[64];
    float pos[3];
} Body;

static inline void body_pos_copy(float *dst, Body *body)
{
    dst[0] = body->pos[0];
    dst[1] = body->pos[1];
    dst[2] = body->pos[2];
}

void func_801048B8(unsigned char *object)
{
    func_800AE72C(object + 652, object,
                  func_800AEF6C(*(unsigned char **)(object + 4) + 25052, object[733]));
    *(float *)(object + 84) -= *(float *)(object + 1240);
    *(float *)(object + 92) -= *(float *)(object + 1244);
    body_pos_copy((float *)(object + 368), (Body *)(object + 20));
    body_pos_copy((float *)(object + 392), (Body *)(object + 20));
}
