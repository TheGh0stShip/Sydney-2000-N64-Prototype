/* Limit a direction toward the target to the allowed motion step; return distance. */
typedef struct { float x,y,z; } Vector3;
typedef struct { float values[16]; Vector3 position; } MotionTransform;
typedef struct { unsigned char head[0xc]; int dirty; unsigned char gap10[0x28]; int changed; } MotionChild;
typedef struct { unsigned char head[0x14];MotionTransform transform; unsigned char gap60[0x68];float speed; unsigned char gapCC[0x24];int mode; unsigned char gapF4[0x30];MotionChild child; } MotionObject;
typedef char motion_object_pointer[sizeof(void *)==4?1:-1];
typedef char motion_child_offset[(unsigned long)&((MotionObject *)0)->child==0x124?1:-1];
typedef char motion_transform_size[sizeof(MotionTransform)==0x4c?1:-1];
extern float func_800AD6D0(Vector3 *,Vector3 *);
extern void func_800AEC9C(MotionChild *,Vector3 *);
float func_800B47B0(MotionObject *object,Vector3 *target) {
 Vector3 position,delta,direction;
 float maximum,distance;
 MotionTransform *transform=&object->transform;
 Vector3 *previous=&position;
 MotionChild *child;
 previous->x=transform->position.x;previous->y=transform->position.y;previous->z=transform->position.z;
 delta.x=target->x-previous->x;delta.y=target->y-previous->y;delta.z=target->z-previous->z;
 maximum=object->speed;
 distance=func_800AD6D0(&delta,&direction);
 if(distance<0.001f) {direction.x=0;direction.y=0;direction.z=0;}
 else {
  float step=distance;
  if(maximum<distance)step=maximum;
  direction.x*=step;direction.y*=step;direction.z*=step;
 }
 child=&object->child;
 func_800AEC9C(child,&direction);
 if(object->mode==4) {child->dirty=1;child->changed=1;}
 return distance;
}
