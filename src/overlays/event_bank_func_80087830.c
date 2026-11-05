extern void func_800C0110(void *object, int id, int a, int b);
extern unsigned char *D_800FC270;
extern unsigned char D_80077741;
extern unsigned char D_800F3BC0[];

void func_80087830(unsigned char *object)
{
    int id;
    unsigned char kind;

    if (object[1557] < 2 && *(int *)(D_800FC270 + 2560) == 4) {
        kind = D_80077741;
        id = 164;
        if (kind != 0) {
            id = 166;
            if (kind < 2) {
                id = 165;
            }
        }
        if (id != -1 && *(int *)(D_800FC270 + 2564) != 0
            && *(int *)(object + 21568) == 1) {
            func_800C0110(D_800F3BC0, id, 3072, 0);
        }
    }
}
