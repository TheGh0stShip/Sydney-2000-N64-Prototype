typedef struct {
    float x, y, z;
} Vec3;

void func_800AD2A8(void *mtx, void *in, Vec3 *out, int flag);
void func_800B9480(void *obj);

void func_800B9964(char *obj, void *offset, int *moved, void *delta)
{
    Vec3 local;
    Vec3 step;

    func_800AD2A8(obj + 20, offset, &local, 0);
    if (*moved != 0) {
        Vec3 *base;
        Vec3 *saved;

        func_800AD2A8(obj + 20, delta, &step, 0);
        base = (Vec3 *)(obj + 368);
        base->x += step.x;
        base->y += step.y;
        base->z += step.z;
        saved = (Vec3 *)(obj + 392);
        saved->x = base->x;
        saved->y = base->y;
        saved->z = base->z;
    }
    {
        Vec3 *a = &local;
        Vec3 *b = (Vec3 *)(obj + 368);
        Vec3 *out = (Vec3 *)(obj + 84);

        out->x = a->x + b->x;
        out->y = a->y + b->y;
        out->z = a->z + b->z;
    }
    func_800B9480(obj);
}
