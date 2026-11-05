typedef struct {
    float x;
    float y;
    float z;
} Vec3;

#define VEC3_COPY(dstAddr, srcAddr) \
    { \
        Vec3 *dst_ = (Vec3 *)(dstAddr); \
        Vec3 *src_ = (Vec3 *)(srcAddr); \
        dst_->x = src_->x; \
        dst_->y = src_->y; \
        dst_->z = src_->z; \
    }

extern void func_800B7368(void *self, void *state, int flag, int a, int b, int c, int d);

int func_800B9FA4(unsigned char *self, int a, int b, int c, int d, int keepSpeed)
{
    float speedA = *(float *)(self + 372);
    float speedB = *(float *)(self + 396);

    func_800B7368(self, self + 244, 0, a, b, c, d);
    VEC3_COPY(self + 368, self + 84);
    VEC3_COPY(self + 392, self + 84);
    if (keepSpeed != 0) {
        *(float *)(self + 372) = *(float *)(self + 396) = 0.0f;
    } else {
        *(float *)(self + 372) = speedA;
        *(float *)(self + 396) = speedB;
    }
    return 0;
}
