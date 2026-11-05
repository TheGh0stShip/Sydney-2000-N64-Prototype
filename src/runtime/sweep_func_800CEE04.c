extern void func_800ADC1C(void *p);
extern void func_800B35F0(void *p);

typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

void func_800CEE04(unsigned char *object)
{
    Method *m = (Method *)(*(unsigned char **)(object + 180) + 72);

    m->fn(object + m->offset);
    func_800ADC1C(object + 236);
    func_800ADC1C(object + 448);
    func_800ADC1C(object + 660);
    func_800ADC1C(object + 872);
    func_800B35F0(object + 1084);
}
