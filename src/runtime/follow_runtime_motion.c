/* Follow a target transform, optionally smoothing the tracked position. */
typedef struct { float x,y,z; } Vector3;
typedef struct { float values[16]; Vector3 position; } MotionTransform;
typedef struct { unsigned char head[0x14]; MotionTransform transform; unsigned char gap60[0x114]; float distance; } MotionObject;
typedef struct { int initialized; Vector3 current,target;float factor,threshold; } MotionSmoothing;
extern float func_800AD7D0(Vector3 *);
extern void func_800AC9B8(Vector3 *,MotionTransform *,Vector3 *);
extern Vector3 *runtimeMotionUpVector;
static inline void apply(MotionObject *o,Vector3 *m,MotionTransform *d) { o->distance=func_800AD7D0(m); func_800AC9B8(m,d,runtimeMotionUpVector); }
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
  apply(object,&movement,destination);
 }
}
