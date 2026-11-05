extern unsigned char *D_800FC270;
extern unsigned char D_80077BB1;
extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *object, int id, int first, int second);

void func_800E21BC(unsigned char *object)
{
    int id;

    if (object[1557] < 2) {
        id = 235;
        if (*(int *)(D_800FC270 + 2560) == 4) {
            if (D_80077BB1 == 0) {
                id = 236;
            } else if (D_80077BB1 < 2) {
                id = 237;
            } else {
                id = 238;
            }
        }
        if (*(int *)(D_800FC270 + 2564) != 0 &&
            *(int *)(object + 25320) == 1) {
            func_800C0110(D_800F3BC0, id, 3072, 0);
        }
    }
}
