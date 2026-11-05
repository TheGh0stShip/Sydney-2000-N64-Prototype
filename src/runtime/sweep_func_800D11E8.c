typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

void func_800AC334(void *object);
void func_800CE594(void);
void func_8001A248(void *sound);

void func_800D11E8(unsigned char *object)
{
    Method *m;
    unsigned char i;

    func_800AC334(object + 900);
    func_800AC334(object + 264);
    func_800AC334(object + 476);
    func_800AC334(object + 688);
    m = (Method *)(*(unsigned char **)(object + 180) + 24);
    m->fn(object + m->offset);
    object[176] = 0;
    func_800CE594();
    for (i = 0; i < 8; i++) {
        func_8001A248((int *)(object + 212) + i);
    }
    for (i = 0; i < 3; i++) {
        func_8001A248((int *)(object + 244) + i);
    }
    for (i = 0; i < 2; i++) {
        func_8001A248((int *)(object + 256) + i);
    }
}
