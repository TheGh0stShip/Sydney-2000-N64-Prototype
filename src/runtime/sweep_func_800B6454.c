typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    float m[16];
    Vec3 pos;
} Pose;

typedef struct {
    float v[4];
} Quat;

typedef struct {
    char pad0[20];
    char sub20[64];
    Vec3 pos;
    char pad96[104];
    float speed;
    char pad204[172];
    int unk376;
    char unk380[16];
    Quat q396;
    Quat q412;
    float blend;
} Obj;

extern void func_800ACF20(Quat *a, Quat *b, float t, Quat *out);
extern void func_800AD1BC(Quat *q, Pose *pose);
extern void func_800B48CC(Obj *obj, int arg, int flag);
extern void func_800AC718(void *sub, Quat *q);
extern void func_800B3870(void *sub, Pose *pose, int size);

static inline void vec_copy(Vec3 *d, Vec3 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

void func_800B6454(Obj *obj) {
    Pose pose;
    Quat tmp;
    Quat *q;
    float step = *(float *)0x80086A9C;

    q = &obj->q396;
    if (obj->blend != 0.0f) {
        func_800ACF20(q, &obj->q412, obj->blend, &tmp);
        q = &tmp;
    }
    func_800AD1BC(q, &pose);
    vec_copy(&pose.pos, &obj->pos);
    func_800B48CC(obj, obj->unk376, 0);
    func_800AC718(obj->sub20, &obj->q412);
    step += obj->speed / *(float *)0x80086AA0;
    obj->blend += step;
    func_800B3870(obj->sub20, &pose, sizeof(Pose));
}
