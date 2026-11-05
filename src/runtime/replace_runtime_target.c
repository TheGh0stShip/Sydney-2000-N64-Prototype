/* Replace a controller target through its adjusted detach/attach methods. */
typedef struct RuntimeNode RuntimeNode;
typedef struct {short delta,pad;void (*invoke)(void *,RuntimeNode *);} AttachMethod;
typedef struct {short delta,pad;void (*invoke)(void *);} DetachMethod;
typedef struct {unsigned char head[0x10];AttachMethod attach;DetachMethod detach;} RuntimeMethods;
struct RuntimeNode {unsigned int kind;RuntimeNode *parent;unsigned char gap8[0xac];RuntimeMethods *methods;};
typedef struct {unsigned char head[0x1c];RuntimeNode *target;} TargetController;
typedef char replace_target_attach[sizeof(AttachMethod)==8?1:-1];
typedef char replace_target_detach[sizeof(DetachMethod)==8?1:-1];
typedef char replace_target_pointer[sizeof(void *)==4?1:-1];
typedef char replace_target_methods[(unsigned long)&((RuntimeNode *)0)->methods==0xB4?1:-1];
extern void func_80013048(TargetController *,int);
void func_800B4ACC(TargetController *controller,RuntimeNode *previous,RuntimeNode *next) {
 RuntimeNode *owner=previous->parent;
 previous->methods->detach.invoke((unsigned char *)previous+previous->methods->detach.delta);
 next->methods->attach.invoke((unsigned char *)next+next->methods->attach.delta,owner);
 controller->target=next;
 func_80013048(controller,8);
}
