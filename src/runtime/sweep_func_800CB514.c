extern void func_8001A248(void *p);
extern void func_800AC334(void *p);
extern void func_800B35F0(void *p);

typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

void func_800CB514(unsigned char *object)
{
    if (*(int *)(object + 1868) != 0) {
        unsigned char *child = object + 1672;
        Method *m = (Method *)(*(unsigned char **)(object + 1852) + 72);
        m->fn(child + m->offset);
        func_8001A248(object + 1868);
    }
    object += 2944;
    func_800AC334(object);
    func_800B35F0(object);
}
