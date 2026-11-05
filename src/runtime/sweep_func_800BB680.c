typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    float m[16];
    Vec3 pos;
} Pose;

typedef struct {
    int type;
    int arg;
} Message;

typedef struct {
    short offset;
    short pad;
    void (*fn)(void *, int, Pose *);
} Method;

void func_800AD434(Pose *pose, float angle, int axis);
void func_800AC5CC(Pose *pose, void *parent, void *out, int flag);
void func_800AE1EC(void *obj, int arg);
void func_800ADFAC(void *obj);
void func_800AE304(void *obj);

void func_800BB680(char *obj, Message *msg)
{
    Pose pose;

    switch (msg->type) {
    case 3:
        break;
    case 5:
        {
            char *other = *(char **)(obj + 388);
            Method *m = (Method *)(*(char **)(other + 180) + 40);
            Vec3 *ofs;

            m->fn(other + m->offset, 39, &pose);
            ofs = (Vec3 *)(obj + 376);
            pose.pos.x += ofs->x;
            pose.pos.y += ofs->y;
            pose.pos.z += ofs->z;
            func_800AD434(&pose, 3.1415927f, 3);
            func_800AC5CC(&pose, *(char **)(obj + 388) + 20, obj + 20, 1);
            func_800AE1EC(obj, msg->arg);
        }
        break;
    }
    *(int *)(obj + 16) = msg->arg;
    if (*(int *)(obj + 296) == 0) {
        if (*(int *)(obj + 268) != 0) {
            func_800ADFAC(obj);
        }
        if (*(unsigned short *)(obj + 196) & 1) {
            func_800AE304(obj);
        }
    }
}
