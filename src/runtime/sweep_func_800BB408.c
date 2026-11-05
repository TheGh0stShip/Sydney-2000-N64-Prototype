typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    int type;
    int arg;
} Message;

void func_800AD2A8(void *mtx, void *in, Vec3 *out, int flag);
void func_800BB25C(void *obj);
void func_800B48CC(void *obj, int a, int b);
void func_800AE1EC(void *obj, int arg);
void func_800ADFAC(void *obj);
void func_800AE304(void *obj);

void func_800BB408(char *obj, Message *msg)
{
    Vec3 pos;

    switch (msg->type) {
    case 3:
        break;
    case 5:
        if (*(char **)(obj + 380) != 0) {
            float *dst;
            float *src;

            func_800AD2A8(*(char **)(obj + 380) + 20, obj + 384, &pos, 1);
            dst = (float *)(obj + 20);
            src = &pos.x;
            dst[16] = src[0];
            dst[17] = src[1];
            dst[18] = src[2];
        }
        if (*(float *)(obj + 428) < 1.0f) {
            func_800BB25C(obj);
        } else {
            func_800B48CC(obj, *(int *)(obj + 376), 0);
        }
        func_800AE1EC(obj, msg->arg);
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
