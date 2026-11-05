/* Activate a scene object: set the default mode word, and when a target is
 * supplied, register the object and kick the dependent subsystems. */
typedef struct SceneObj {
    char pad[184];
    void *target;
    unsigned char busy;
} SceneObj;

extern void func_800E9494(void *handle, int mode);
extern void func_800D53A0(void *ctx, int flag);
extern void func_800EDA60(void);
extern void func_800EE154(void);
extern void func_800BC180(void *list);
extern int D_800F2668;
extern SceneObj *D_800F2660;
extern void *D_800FF480;
extern char D_800F5900[];
extern char D_800F2AD8[];

void func_800AC030(SceneObj *obj, void *target)
{
    D_800F2668 = 0x70800;
    obj->busy = 0;
    if (target != 0) {
        D_800F2660 = obj;
        obj->target = target;
        func_800E9494(D_800FF480, 2);
        func_800D53A0(D_800F5900, 0);
        func_800EDA60();
        func_800EE154();
        func_800BC180(D_800F2AD8);
    }
}
