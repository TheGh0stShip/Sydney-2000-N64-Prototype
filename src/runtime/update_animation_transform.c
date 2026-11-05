/* Blend quaternion animation, preserve the displayed transform, and advance phase. */
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
void func_800B3ECC(AnimatedObject *object) {
 Transform saved;
 Quaternion blended;
 Quaternion *rotation=&object->previous;
 if(object->phase!=0.0f) { func_800ACF20(rotation,&object->current,object->phase,&blended); rotation=&blended; }
 func_800AD1BC(rotation,&saved);
 { float *position=&object->transform.x; saved.x=position[0];saved.y=position[1];saved.z=position[2]; }
 func_800B48CC(object,object->animation,0);
 func_800AC718(&object->transform,&object->current);
 object->phase+=object->rate;
 func_800B3870(&object->transform,&saved,sizeof(saved));
}
