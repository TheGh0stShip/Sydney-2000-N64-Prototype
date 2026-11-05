#define D_80070900 (*(float *)0x80070900)

typedef struct {
    float x, y, z;
} Vec3;

extern void *D_800F267C;
extern void func_800B97D4(void *skeleton, int bone, float *out);
extern void func_800AD2A8(void *camera, Vec3 *in, Vec3 *out, int mode);
extern void func_800AC9B8(Vec3 *v, void *transform, void *basis);
extern void func_800AD434(void *object, float angle, int mode);
extern void func_800AD9E8(void *object);

void func_800B7614(unsigned char *object)
{
    float frame[20];
    Vec3 tail;
    Vec3 head;
    Vec3 diff;
    Vec3 step;
    Vec3 near;
    Vec3 far;
    float *target;

    func_800B97D4(object + 4552, 23, frame);
    head.x = frame[16];
    head.y = frame[17];
    head.z = frame[18];
    func_800B97D4(object + 4552, 31, frame);
    tail.x = frame[16];
    tail.y = frame[17];
    tail.z = frame[18];
    func_800AD2A8(object + 4572, &head, &far, 1);
    func_800AD2A8(object + 4572, &tail, &near, 1);
    diff.x = far.x - near.x;
    diff.y = far.y - near.y;
    diff.z = far.z - near.z;
    step.x = diff.x * D_80070900;
    step.y = diff.y * D_80070900;
    step.z = diff.z * D_80070900;
    func_800AC9B8(&step, object + 17392, D_800F267C);
    step.x = near.x + step.x;
    step.y = near.y + step.y;
    step.z = near.z + step.z;
    target = (float *)(object + 17392);
    target[16] = step.x;
    target[17] = step.y;
    target[18] = step.z;
    func_800AD434(target, 1.5707961f, 3);
    func_800AD9E8(object + 17372);
}
