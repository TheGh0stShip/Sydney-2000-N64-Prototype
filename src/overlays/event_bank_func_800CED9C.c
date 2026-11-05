#define D_800708F4 (*(float *)0x800708F4)

typedef struct {
    float x, y, z;
} Vec3;

extern void *D_800F267C;
extern void func_800B97D4(void *skeleton, int bone, float *out);
extern void func_800AD2A8(void *camera, Vec3 *in, Vec3 *out, int mode);
extern void func_800AC9B8(Vec3 *v, void *transform, void *basis);
extern void func_800AD434(void *transform, float angle, int axis);
extern void func_800AD9E8(void *timer);

void func_800CED9C(unsigned char *object)
{
    float frame[16 + 4];
    Vec3 tail;
    Vec3 head;
    Vec3 diff;
    Vec3 step;
    Vec3 near;
    Vec3 far;
    float scale;
    float *target;

    func_800B97D4(object + 4552, 21, frame);
    head.x = frame[16];
    head.y = frame[17];
    head.z = frame[18];
    func_800B97D4(object + 4552, 29, frame);
    tail.x = frame[16];
    tail.y = frame[17];
    tail.z = frame[18];
    func_800AD2A8(object + 4572, &head, &far, 1);
    func_800AD2A8(object + 4572, &tail, &near, 1);
    diff.x = far.x - near.x;
    diff.y = far.y - near.y;
    diff.z = far.z - near.z;
    scale = D_800708F4;
    step.x = diff.x * scale;
    step.y = diff.y * scale;
    step.z = diff.z * scale;
    step.x = step.x + near.x;
    step.y = step.y + near.y;
    step.z = step.z + near.z;
    func_800AC9B8(&diff, object + 17392, D_800F267C);
    target = (float *)(object + 17392);
    target[16] = step.x;
    target[17] = step.y;
    target[18] = step.z;
    func_800AD434(object + 17392, 1.5707961f, 3);
    func_800AD9E8(object + 17372);
}
