typedef struct {
    short offset;
    short pad;
    void (*func)(void *);
} VEntry800EE600;

extern void func_800AEAE8(void *, void *);
extern void func_800EF220(void *, int *);
extern int D_80100080[];

void func_800EE600(char *obj, int *msg)
{
    VEntry800EE600 *v;
    unsigned int k;

    switch (msg[0]) {
    case 3:
        break;
    case 5:
        if (*(int *)(obj + 480) == 0) {
            break;
        }
        func_800AEAE8(obj + 484, obj);
        func_800EF220(obj, msg);
        *(int *)(obj + 216) -= 256;
        *(int *)(obj + 212) -= 256;
        if (*(int *)(obj + 212) < 0) {
            *(int *)(obj + 480) = 0;
            v = (VEntry800EE600 *)(*(char **)(obj + 180) + 72);
            v->func(obj + v->offset);
        }
        if (*(int *)(obj + 472) != 0) {
            *(int *)(obj + 476) -= 256;
            if (*(int *)(obj + 476) < 0) {
                if (*(unsigned char *)(*(char **)(obj + 232) + 73) == 0) {
                    *(int *)(obj + 192) |= 4;
                } else {
                    *(int *)(obj + 192) &= ~4;
                }
                k = *(unsigned char *)(*(char **)(obj + 232) + 73);
                if (k >= 9) {
                    k = 0;
                }
                *(int *)(obj + 224) = D_80100080[k];
                *(int *)(obj + 472) = 0;
            }
        }
        break;
    }
    *(int *)(obj + 16) = msg[1];
}
