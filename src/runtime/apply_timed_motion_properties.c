/* Apply flagged motion resources and convert profile offsets into runtime deadlines. */
typedef unsigned char u8;typedef unsigned int u32;typedef unsigned short u16;
typedef struct {float x,y,z;} Vector3;
typedef struct {float speed;u32 unused[4];u32 begin,end,expiry;} MotionTiming;
typedef struct {u8 head[0xBC];u32 special,state;u16 flags,reserved;float speed;MotionTiming timing;u32 pending,mode;float f4,f8,fc;u8 gap100[0x24];u8 child[0x54];Vector3 velocity;} MotionObject;
typedef struct {u32 flags;u8 gap4[0x18];Vector3 velocity;u32 childHandle,secondaryHandle;MotionTiming timing;float advance;u32 reserved;float f58,f5c,f60;u16 objectFlags;} MotionProperties;
typedef struct {u8 head[0x18];u32 time;} RuntimeClock;
typedef char motion_timing_size[sizeof(MotionTiming)==32?1:-1];
typedef char motion_properties_flags[(unsigned long)&((MotionProperties *)0)->objectFlags==0x64?1:-1];
typedef char motion_object_child[(unsigned long)&((MotionObject *)0)->child==0x124?1:-1];
typedef char motion_pointer_size[sizeof(void *)==4?1:-1];
extern RuntimeClock runtimeClock;
extern void func_800B3870(void *,void *,u32);
extern void func_800B4C2C(MotionObject *,Vector3 *);
extern void func_800AEB68(void *,u32);
extern int func_800AE9DC(void *,float,MotionObject *);
void func_800B4CC0(MotionObject *object,MotionProperties *input) {
 if(input->flags&4) {Vector3 *src=&input->velocity,*dst=&object->velocity;dst->x=src->x;dst->y=src->y;dst->z=src->z;}
 if(input->flags&0x20) {
  func_800B3870(&object->timing,&input->timing,32);
  if(!object->timing.expiry)object->special=0;
  object->timing.expiry+=runtimeClock.time;
  object->timing.begin+=runtimeClock.time;
  object->timing.end+=runtimeClock.time;
  object->speed=object->timing.speed;
 }
 func_800B4C2C(object,&object->velocity);
 if(input->flags&8) {void *child=object->child;func_800AEB68(child,input->childHandle);func_800AE9DC(child,0.0f,object);}
 if(input->flags&0x200)object->f4=input->f5c;
 if(input->flags&0x400)object->flags=input->objectFlags;
 if(input->flags&0x800)object->fc=input->f60;
 if(input->flags&0x100)object->f8=input->f58;
}
