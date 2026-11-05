extern void func_800ADC38(void *p);
extern void func_800CEC00(void *object, int arg);
extern int D_800F4940;

typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

void func_800CEE60(unsigned char *object)
{
    Method *m = (Method *)(*(unsigned char **)(object + 180) + 64);

    m->fn(object + m->offset);
    D_800F4940 = 0;
    func_800ADC38(object + 236);
    func_800ADC38(object + 448);
    func_800ADC38(object + 660);
    func_800ADC38(object + 872);
    func_800CEC00(object, *(int *)(object + 212));
}
