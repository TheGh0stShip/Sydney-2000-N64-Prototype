/* Apply a displacement toward the target when the child motion is inactive. */
typedef struct { float x,y,z; } Vector3;
typedef struct { float values[16]; Vector3 position; } MotionTransform;
typedef struct { unsigned char head[0x14];MotionTransform transform;unsigned char gap60[0xC8];int childState;unsigned char gap12C[0x48];float distance; } MotionObject;
typedef char motion_target_pointer[sizeof(void *)==4?1:-1];
typedef char motion_target_transform[sizeof(MotionTransform)==0x4c?1:-1];
typedef char motion_target_distance[(unsigned long)&((MotionObject *)0)->distance==0x174?1:-1];
extern float func_800AD7D0(Vector3 *);
extern void func_800AC9B8(Vector3 *,MotionTransform *,Vector3 *);
extern Vector3 *runtimeMotionUpVector;
/* Keep each temporary-vector argument in caller argument registers.
 * These empty constraints emit no instructions and avoid a redundant
 * callee-saved stack-address lifetime in SN GCC 2.8. */
#define FRESH_VECTOR(p) ({Vector3 *v=&(p); __asm__("" : "+r"(v) : : "$2","$3"); v;})
void func_800B4C2C(MotionObject *object,Vector3 *target) {
 Vector3 position,movement;
 MotionTransform *transform=&object->transform;
 if(!object->childState) {
  position.x=transform->position.x;position.y=transform->position.y;position.z=transform->position.z;
  movement.x=target->x-position.x;movement.y=target->y-position.y;movement.z=target->z-position.z;
  object->distance=func_800AD7D0(FRESH_VECTOR(movement));
  func_800AC9B8(FRESH_VECTOR(movement),transform,runtimeMotionUpVector);
 }
}
