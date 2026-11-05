/* Advance child motion while preserving the displayed translation, then
 * measure the requested displacement and orient the object along it. */
typedef struct { float x, y, z; } Vector3;
typedef struct { float values[16]; Vector3 position; } MotionTransform;
typedef struct {
    unsigned char head[0x14];
    MotionTransform transform;
    unsigned char gap60[0x114];
    float distance;
} MotionObject;
typedef char child_motion_pointer[sizeof(void *) == 4 ? 1 : -1];
typedef char child_motion_transform[sizeof(MotionTransform) == 0x4C ? 1 : -1];
typedef char child_motion_distance[
    (unsigned long)&((MotionObject *)0)->distance == 0x174 ? 1 : -1];

extern int func_800AE9DC(void *, float, MotionObject *);
extern float func_800AD7D0(Vector3 *);
extern void func_800AC9B8(Vector3 *, MotionTransform *, Vector3 *);
extern Vector3 *runtimeMotionUpVector;

/* Empty operand constraints retain SN GCC 2.8's component and argument
 * lifetimes. They emit no instructions and preserve the o32 call ABI. */
#define MEASURE_ARGUMENT(p, last_component) \
    ({ Vector3 *v = &(p); \
       __asm__("" : "+r"(v) : "f"(last_component) : "$2", "$3"); v; })

void func_800B4B40(MotionObject *object, void *child, float advance) {
    Vector3 previous, next, restored, movement;
    MotionTransform *transform = &object->transform;
    Vector3 *saved = &previous;

    saved->x = transform->position.x;
    saved->y = transform->position.y;
    saved->z = transform->position.z;
    func_800AE9DC(child, advance, object);
    next.x = transform->position.x;
    next.y = transform->position.y;
    next.z = transform->position.z;
    transform->position.x = saved->x;
    transform->position.y = saved->y;
    transform->position.z = saved->z;

    __asm__("" : : "m"(transform->position) : "$f0");
    {
        register float first = transform->position.x;
        {
            register float nx = next.x;
            register float ny;
            float dz;
            Vector3 *argument;

            ny = next.y;
            restored.x = first;
            nx = nx - restored.x;
            {
                register float component = transform->position.y;
                restored.y = component;
            }
            ny = ny - restored.y;
            restored.z = transform->position.z;
            dz = next.z - restored.z;
            argument = MEASURE_ARGUMENT(movement, dz);
            movement.x = nx;
            movement.y = ny;
            __asm__("" : : "m"(movement.y));
            movement.z = dz;
            object->distance = func_800AD7D0(argument);
        }
    }
    func_800AC9B8(&movement, transform, runtimeMotionUpVector);
}
