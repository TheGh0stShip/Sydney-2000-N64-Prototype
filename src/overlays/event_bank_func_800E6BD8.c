extern void func_800AC334(void *object);
extern void func_800ADC1C(void *object);

static inline void release_part(unsigned char *part)
{
    func_800AC334(part);
    func_800ADC1C(part);
}

void func_800E6BD8(unsigned char *object)
{
    release_part(object + 1984);
    release_part(object + 2196);
    release_part(object + 2408);
    release_part(object + 712);
    release_part(object + 924);
    release_part(object + 1136);
    release_part(object + 1348);
}
