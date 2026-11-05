/* Follow a target transform, optionally smoothing the tracked position. */
typedef struct { float x,y,z; } Vector3;
typedef struct { float values[16]; Vector3 position; } MotionTransform;
typedef struct { unsigned char head[0x14]; MotionTransform transform; unsigned char gap60[0x114]; float distance; } MotionObject;
typedef struct { int initialized; Vector3 current,target;float factor,threshold; } MotionSmoothing;
typedef char motion_target_pointer[sizeof(void *)==4?1:-1];
typedef char motion_target_transform[sizeof(MotionTransform)==0x4c?1:-1];
typedef char motion_target_distance[(unsigned long)&((MotionObject *)0)->distance==0x174?1:-1];
typedef char motion_smoothing_layout[sizeof(MotionSmoothing)==0x24?1:-1];
extern float func_800AD7D0(Vector3 *);
extern void func_800AC9B8(Vector3 *,MotionTransform *,Vector3 *);
extern Vector3 *runtimeMotionUpVector;
/* Keep each temporary-vector argument in caller argument registers.
 * These empty constraints emit no instructions and avoid a redundant
 * callee-saved stack-address lifetime in SN GCC 2.8. */
#define FRESH_VECTOR(p) ({Vector3 *v=&(p); __asm__("" : "+r"(v) : : "$2","$3"); v;})
void func_800B48CC(MotionObject *object,MotionObject *target,MotionSmoothing *smoothing) {
 Vector3 position,delta,previous,movement;
 Vector3 *point;
 MotionTransform *source;
 MotionTransform *destination;
 if(target) {
  point=&position;
  source=&target->transform;
  point->x=source->position.x;point->y=source->position.y;point->z=source->position.z;
  if(smoothing) {
   Vector3 *history;
   if(!smoothing->initialized) {
    Vector3 *current=&smoothing->current;
    Vector3 *fresh=&smoothing->target;
    current->x=point->x;current->y=point->y;current->z=point->z;
    fresh->x=point->x;fresh->y=point->y;fresh->z=point->z;
   } else {
    Vector3 *current;
    float factor;
    history=&smoothing->target;
    delta.x=point->x-history->x;delta.y=point->y-history->y;delta.z=point->z-history->z;
    if(smoothing->threshold<=func_800AD7D0(&delta)) {
     history->x=point->x;history->y=point->y;history->z=point->z;
    }
    current=&smoothing->current;
    delta.x=history->x-current->x;delta.y=history->y-current->y;delta.z=history->z-current->z;
    factor=smoothing->factor;
    delta.x*=factor;delta.y*=factor;delta.z*=factor;
    current->x+=delta.x;current->y+=delta.y;current->z+=delta.z;
    point->x=current->x;point->y=current->y;point->z=current->z;
   }
  }
  destination=&object->transform;
  previous.x=destination->position.x;previous.y=destination->position.y;previous.z=destination->position.z;
  { Vector3 *fresh=&position; movement.x=fresh->x-previous.x;movement.y=fresh->y-previous.y;movement.z=fresh->z-previous.z; }
  object->distance=func_800AD7D0(FRESH_VECTOR(movement));
  func_800AC9B8(FRESH_VECTOR(movement),destination,runtimeMotionUpVector);
 }
}
