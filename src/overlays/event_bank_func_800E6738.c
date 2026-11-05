typedef struct {
    short offset;
    short pad;
    void (*func)(void *object);
} Method;

extern void func_800ADC1C(void *object);
extern void func_800ADC38(void *object);

#define FLAGS(p) (*(unsigned int *)((unsigned char *)(p) + 192))
#define UPDATE_FLAGS(p) (FLAGS(p) = (FLAGS(p) | 0x01000000) & ~0x04000000)

void func_800E6738(unsigned char *object)
{
    unsigned char *part0 = object + 712;
    unsigned char *part1;
    unsigned char *part2;
    unsigned char *part3;
    unsigned char *part4;
    unsigned char *part5;
    Method *method;

    func_800ADC1C(part0);
    part1 = object + 1348;
    func_800ADC1C(part1);
    part2 = object + 924;
    func_800ADC1C(part2);
    part3 = object + 1136;
    func_800ADC1C(part3);
    part4 = object + 1560;
    func_800ADC1C(part4);
    part5 = object + 1772;
    func_800ADC1C(part5);

    method = (Method *)(*(unsigned char **)(object + 180) + 72);
    method->func(object + method->offset);

    UPDATE_FLAGS(part0);
    UPDATE_FLAGS(part1);
    UPDATE_FLAGS(part2);
    UPDATE_FLAGS(part3);
    UPDATE_FLAGS(part4);
    UPDATE_FLAGS(part5);
    UPDATE_FLAGS(object);

    func_800ADC38(part0);
    func_800ADC38(part1);
    func_800ADC38(part2);
    func_800ADC38(part3);
    func_800ADC38(part4);
    func_800ADC38(part5);

    method = (Method *)(*(unsigned char **)(object + 180) + 64);
    method->func(object + method->offset);
}
