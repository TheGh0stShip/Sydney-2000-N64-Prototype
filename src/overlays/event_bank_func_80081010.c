extern void func_800DA804(int a, int b, void *result, int c, int d);
extern signed char func_8009B670(void *object);
extern void func_800C0110(void *object, int value, int a, int b);
extern int D_80071580[];
extern unsigned char D_800F3BC0[];

void func_80081010(unsigned char *object)
{
    unsigned char result[128];
    unsigned char *hi;
    signed char index;
    int value;

    func_800DA804(0, 0, result, 0, 0);
    hi = object + 0x8000;
    if (hi[3229] != 3) {
        index = func_8009B670(*(void **)(object + 21356));
        value = D_80071580[index];
        if (hi[3229] != 3 && hi[3229] != 4) {
            func_800C0110(D_800F3BC0, value, 15360, 0x12C00);
        }
    }
}
