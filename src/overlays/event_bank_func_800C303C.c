#define D_80070844 (*(float *)0x80070844)

typedef struct {
    float x, y, z;
} Vec3;

extern void func_800B97D4(void *skeleton, int bone, float *out);
extern void func_800AD2A8(void *camera, Vec3 *in, Vec3 *out, int mode);
extern void func_800AD9E8(void *object);

void func_800C303C(unsigned char *object)
{
    float frame[20];
    Vec3 point;
    Vec3 from;
    Vec3 to;
    Vec3 step;
    Vec3 diff;
    Vec3 mid;
    float *matrix;
    float *target;

    func_800B97D4(object + 4552, 31, frame);
    matrix = frame;
    point.x = matrix[16];
    point.y = matrix[17];
    point.z = matrix[18];
    func_800AD2A8(object + 4572, &point, &from, 1);
    func_800B97D4(object + 4552, 23, matrix);
    point.x = matrix[16];
    point.y = matrix[17];
    point.z = matrix[18];
    func_800AD2A8(object + 4572, &point, &to, 1);
    diff.x = to.x - from.x;
    diff.y = to.y - from.y;
    diff.z = to.z - from.z;
    step.x = diff.x * D_80070844;
    step.y = diff.y * D_80070844;
    step.z = diff.z * D_80070844;
    mid.x = step.x + from.x;
    mid.y = step.y + from.y;
    mid.z = step.z + from.z;
    target = (float *)(object + 19108);
    target[16] = mid.x;
    target[17] = mid.y;
    target[18] = mid.z;
    func_800AD9E8(object + 19088);
}
