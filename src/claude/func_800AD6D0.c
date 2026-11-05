typedef float f32;

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;
typedef char assert_size_Vec3f[(sizeof(Vec3f) == 0xC) ? 1 : -1];

extern float sqrtf(float);

f32 func_800AD6D0(Vec3f *src, Vec3f *dst) {
    f32 len;
    f32 inv;

    len = sqrtf(src->x * src->x + src->y * src->y + src->z * src->z);
    if (!((len < 0.0f) ? (-len <= 0.00390625f) : (len <= 0.00390625f))) {
        inv = 1.0f / len;
        dst->x = src->x * inv;
        dst->y = src->y * inv;
        dst->z = src->z * inv;
    } else {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
    }
    return len;
}
