extern void func_800C0110(void *object);
extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];

void func_80087B3C(unsigned char *object, int value)
{
    if (value != -1) {
        if (*(int *)(D_800FC270 + 2564) != 0) {
            if (*(int *)(object + 21568) == 1) {
                func_800C0110(D_800F3BC0);
            }
        }
    }
}
