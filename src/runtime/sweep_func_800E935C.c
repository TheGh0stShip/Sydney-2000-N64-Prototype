typedef struct {
    short delta;
    short index;
    void (*fn)(char *, void *);
} VEntry;

extern char D_800F5900[];
extern void func_8001A330(char *, int);
extern void func_8001A1D8(char *, float, float, float, float);
extern void func_8001A210(char *, float, float, float, float, int);
extern void func_800191E0(char *, unsigned int);
extern void func_800ADC54(char *, int);

void func_800E935C(char *obj)
{
    char *sprite;
    char *node;
    VEntry *v;

    sprite = obj + 27652;
    func_8001A330(sprite, 0xFFFF);
    func_8001A1D8(sprite, -103.0f, -7.0f, 103.0f, 7.0f);
    func_8001A210(sprite, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(sprite, 0xFF808080);
    *(int *)(obj + 27852) = *(int *)(obj + 27652);
    node = obj + 27656;
    node[201] = 1;
    *(int *)(node + 192) |= 0x20000;
    func_800191E0(sprite, 0x78FFFFFF);
    func_800ADC54(node, 1);
    *(int *)(node + 192) |= 2;
    v = &(*(VEntry **)(node + 180))[2];
    v->fn(node + v->delta, D_800F5900);
    func_800ADC54(node, 1 << *(int *)(D_800F5900 + 216));
    node[176] = 1;
    *(short *)(obj + 27868) = 128;
    *(short *)(obj + 27870) = -1;
    *(short *)(obj + 27872) = 0;
    *(int *)(obj + 29364) = -1;
}
