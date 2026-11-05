struct VEntry {
    short offset;
    short pad;
    void (*func)(void *object);
};
extern unsigned char D_800F2758[];
extern void func_800AA658(void *list, void *item);
extern void func_800E5F58(void *object);
extern void func_800AC334(void *object);
extern void func_800ADC1C(void *object);
extern void func_800D29E0(void *object);

void func_8009F7C8(unsigned char *object)
{
    unsigned char *part;
    struct VEntry *vt;

    if (*(int *)(object + 696) != 0) {
        func_800AA658(D_800F2758, object + 696);
        func_800E5F58(object + 212);
        part = object + 940;
        func_800AC334(part);
        func_800ADC1C(part);
        part = object + 1204;
        func_800D29E0(part);
        vt = *(struct VEntry **)(part + 180);
        vt[3].func(part + vt[3].offset);
        part[176] = 0;
    }
}
