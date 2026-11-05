extern char *D_800FC270;
extern unsigned char D_80077621;
extern char D_800F3BC0[];
extern void func_800C0110(void *a, int b, int c, int d);

void func_800DAD74(char *obj)
{
    int sound;

    if (*(unsigned char *)(obj + 1557) < 2) {
        sound = 186;
        if (*(int *)(D_800FC270 + 2560) == 4) {
            if (D_80077621 == 0) {
                sound = 187;
            } else if (D_80077621 < 2) {
                sound = 188;
            } else {
                sound = 189;
            }
        }
        if (*(int *)(D_800FC270 + 2564) != 0 && *(int *)(obj + 24968) == 1) {
            func_800C0110(D_800F3BC0, sound, 3072, 0);
        }
    }
}
