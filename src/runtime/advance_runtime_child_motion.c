typedef struct { float x, y, z; } Vector3;
typedef struct { float values[16]; Vector3 position; } MotionTransform;
typedef struct {
    unsigned char head[0x14];
    MotionTransform transform;
    unsigned char gap60[0x114];
    float distance;
} MotionObject;
extern int func_800AE9DC(void *, float, MotionObject *);
extern float func_800AD7D0(Vector3 *);
extern void func_800AC9B8(Vector3 *, MotionTransform *, Vector3 *);
extern Vector3 *runtimeMotionUpVector;
static inline void apply(MotionObject *o, Vector3 *m, MotionTransform *d) { o->distance = func_800AD7D0(m); func_800AC9B8(m, d, runtimeMotionUpVector); }
void func_800B4B40(MotionObject *object, void *child, float advance)
{
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
    restored.x = transform->position.x;
    restored.y = transform->position.y;
    restored.z = transform->position.z;
    movement.x = next.x - restored.x;
    movement.y = next.y - restored.y;
    movement.z = next.z - restored.z;
    apply(object, &movement, transform);
}
