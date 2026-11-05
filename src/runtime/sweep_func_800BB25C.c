typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    float m[16];
    Vec3 pos;
} Pose;

void func_800ACF20(void *from, void *to, float t, void *out);
void func_800AD1BC(void *quat, void *mtx);
void func_800B48CC(void *obj, int a, int b);
void func_800AC718(void *dst, void *src);
void func_800B3870(void *dst, void *src, int size);

void func_800BB25C(char *obj)
{
    Pose pose;
    float quat[4];
    void *q;
    float *src;

    if (*(float *)(obj + 428) != 0.0f) {
        func_800ACF20(obj + 396, obj + 412, *(float *)(obj + 428), quat);
        q = quat;
    } else {
        q = obj + 396;
    }
    func_800AD1BC(q, &pose);
    src = (float *)(obj + 84);
    pose.pos.x = src[0];
    pose.pos.y = src[1];
    pose.pos.z = src[2];
    func_800B48CC(obj, *(int *)(obj + 376), 0);
    func_800AC718(obj + 20, obj + 412);
    *(float *)(obj + 428) += 0.005f;
    func_800B3870(obj + 20, &pose, sizeof(Pose));
}
