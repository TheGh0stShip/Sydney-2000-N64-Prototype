#define D_8007088C (*(float *)0x8007088C)
#define D_80070890 (*(float *)0x80070890)
#define D_80070894 (*(float *)0x80070894)
#define D_80070898 (*(float *)0x80070898)

extern int func_80013E7C(void *name, void *out, int flags);
extern void func_800ADC54(void *object, int mode);
extern void func_800ADC38(void *object);
extern void func_800AC37C(void *object, void *source);
extern char D_80070834[];
extern char D_80070860[];

void func_800C792C(unsigned char *object)
{
    unsigned char *part;
    int value;
    float width;
    float spacing;
    float height;
    float offset;

    *(int *)(object + 17136) = 0;
    if (func_80013E7C(D_80070834, object + 17136, 0) == 0) {
        return;
    }
    part = object + 17164;
    value = **(int **)(*(unsigned char **)(object + 17136) + 12);
    *(int *)(object + 17160) = value;
    *(int *)(object + 17360) = value;
    func_800ADC54(part, 1);
    func_800ADC38(part);
    func_800AC37C(part, object);
    height = D_8007088C;
    width = D_80070890;
    *(float *)(object + 17256) = width;
    *(float *)(object + 17252) = height;

    if (func_80013E7C(D_80070860, object + 17136, 0) == 0) {
        return;
    }
    part = object + 17380;
    value = **(int **)(*(unsigned char **)(object + 17136) + 12);
    *(int *)(object + 17376) = value;
    *(int *)(object + 17576) = value;
    func_800ADC54(part, 1);
    func_800ADC38(part);
    func_800AC37C(part, object);
    spacing = D_80070894;
    *(float *)(object + 17468) = spacing;
    offset = (**(signed char **)(object + 17596) - 1) * spacing + D_80070898;
    *(float *)(object + 17472) = width;
    *(float *)(object + 17468) = offset;
}
