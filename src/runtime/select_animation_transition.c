/* Capture rotation endpoints and select an animation, optionally starting a blend. */
typedef struct { float value[4]; } Quaternion;
typedef struct { float value[16]; float x,y,z; } Transform;
typedef struct { unsigned char head[0x14]; Transform transform; unsigned char gap60[0x118]; int animation; Quaternion previous,current; float phase,rate; } AnimatedObject;
typedef char animation_pointer_layout[sizeof(void *)==4?1:-1];
typedef char animation_transform_layout[sizeof(Transform)==0x4c?1:-1];
typedef char animation_phase_layout[(unsigned long)&((AnimatedObject *)0)->phase==0x19c?1:-1];
extern void func_800ACF20(Quaternion *,Quaternion *,float,Quaternion *);
extern void func_800AD1BC(Quaternion *,Transform *);
extern void func_800B48CC(AnimatedObject *,int,int);
extern void func_800AC718(Transform *,Quaternion *);
extern void func_800B3870(void *,void *,unsigned int);
extern void func_800B3ECC(AnimatedObject *);
void func_800B3F88(AnimatedObject *object,int animation,int immediate) {
 func_800AC718(&object->transform,&object->previous);
 func_800B48CC(object,animation,0);
 func_800AC718(&object->transform,&object->current);
 object->animation=animation;
 if (!immediate) { object->phase=0.0f; object->rate=0.005f;func_800B3ECC(object); }
}
