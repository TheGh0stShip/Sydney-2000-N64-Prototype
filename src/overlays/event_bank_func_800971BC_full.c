typedef struct {
    int pad[4];
    unsigned int kind;
} Msg;

extern void func_80076758(char *obj, int a, int b);
extern void func_800A9B78(void *a, void *b, int c, int d, int e);

void func_800971BC(char *obj, Msg *msg) {
    switch (msg->kind) {
    case 0:
        break;
    case 1:
    case 2:
        func_80076758(obj, *(int *)(obj + 0x2F68), 1);
        break;
    case 3:
        func_800A9B78(obj + 0x7DE4, obj + 0x2F6C, 1, 1, 2);
        break;
    case 6:
        func_800A9B78(obj + 0x7DE4, obj + 0x7F94, 1, 1, 2);
        break;
    case 7:
        func_800A9B78(obj + 0x7DE4, *(void **)(obj + 0x2F50), 1, 1, 2);
        break;
    case 12:
        func_800A9B78(obj + 0x7DE4, obj + 0x7F94, 1, 1, 1);
        func_800A9B78(obj + 0x7DE4, obj + 0x2F6C, 1, 1, 0);
        break;
    case 17:
        func_800A9B78(obj + 0x7DE4, obj + 0x2F6C, 1, 1, 1);
        func_800A9B78(obj + 0x7DE4, *(void **)(obj + 0x2F68), 1, 1, 0);
        break;
    case 18:
        func_800A9B78(obj + 0x7DE4, obj + 0x2F6C, 1, 1, 1);
        func_800A9B78(obj + 0x7DE4, obj + 0x7F94, 1, 1, 0);
        break;
    }
}
