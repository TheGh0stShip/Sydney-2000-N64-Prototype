#define D_80070800 (*(float *)0x80070800)
#define D_80070804 (*(float *)0x80070804)
#define D_80070808 (*(float *)0x80070808)
#define D_8007080C (*(float *)0x8007080C)

typedef struct {
    float x, y, z;
} Vec3;

extern void func_800B97D4(void *skeleton, int bone, float *out);
extern void func_800AD2A8(void *camera, Vec3 *in, Vec3 *out, int mode);
extern void func_800AD6D0(Vec3 *in, Vec3 *out);
extern void func_800AC9B8(Vec3 *v, void *transform, Vec3 *basis);

void func_800CF4EC(unsigned char *object)
{
    float frame[20];
    Vec3 diff;
    Vec3 step;
    Vec3 dir;
    Vec3 tail;
    Vec3 head;
    Vec3 far;
    Vec3 near;
    Vec3 basis;
    float lift;
    float scale;
    Vec3 *up;
    Vec3 *delta;
    float *target;

    up = &basis;
    up->x = 0.0f;
    up->y = D_80070800;
    up->z = D_80070804;
    func_800B97D4(object + 4552, 23, frame);
    head.x = frame[16];
    head.y = frame[17];
    head.z = frame[18];
    func_800B97D4(object + 4552, 31, frame);
    tail.x = frame[16];
    tail.y = frame[17];
    tail.z = frame[18];
    func_800AD2A8(object + 4572, &head, &far, 1);
    far.y += D_80070808;
    lift = D_80070808;
    func_800AD2A8(object + 4572, &tail, &near, 1);
    near.z += lift;
    diff.x = far.x - near.x;
    diff.y = far.y - near.y;
    diff.z = far.z - near.z;
    delta = &diff;
    func_800AD6D0(delta, &dir);
    scale = D_8007080C;
    step.x = dir.x * scale;
    step.y = dir.y * scale;
    step.z = dir.z * scale;
    func_800AC9B8(delta, object + 17660, up);
    step.x = near.x + step.x;
    step.y = near.y + step.y;
    step.z = near.z + step.z;
    target = (float *)(object + 17660);
    target[16] = step.x;
    target[17] = step.y;
    target[18] = step.z;
}
