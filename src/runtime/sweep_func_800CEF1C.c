extern void func_800ADC1C(void *p);
extern void func_8001A248(void *p);
extern void func_800B35F0(void *p);
extern int D_800F4940;

typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

void func_800CEF1C(unsigned char *object)
{
    Method *m = (Method *)(*(unsigned char **)(object + 180) + 72);

    m->fn(object + m->offset);
    D_800F4940 = 0;
    func_800ADC1C(object + 236);
    func_800ADC1C(object + 448);
    func_8001A248(object + 216);
    func_8001A248(object + 220);
    func_8001A248(object + 224);
    func_8001A248(object + 228);
    func_8001A248(object + 232);
    func_800B35F0(object + 1084);
}
