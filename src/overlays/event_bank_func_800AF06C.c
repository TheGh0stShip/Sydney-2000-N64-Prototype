extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *object, int type, int x, int y);

void func_800AF06C(unsigned char *object)
{
    object += 0x8000;
    if (object[286] < 2 && *(int *)(D_800FC270 + 2564) != 0) {
        func_800C0110(D_800F3BC0, 480, 0, 0);
    }
}
