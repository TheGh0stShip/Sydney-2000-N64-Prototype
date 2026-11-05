extern unsigned char *D_800FC270;
extern char D_800F5900[];
extern short D_800FE0EE;
extern void func_800B31EC(int mode);
extern int func_800B31F8(void);
extern void func_800B3208(int sound);
extern void func_800D53A0(void *queue, int event);
extern void func_800DFFF4(unsigned char *object, int mode);
extern void func_800E42B0(unsigned char *object, int index);
extern void func_800E9774(int handle);

void func_800E4458(unsigned char *object, int choice)
{
    int previous;

    if (choice == 10) {
        func_800B31EC(0);
        func_800D53A0(D_800F5900, 12);
        object[19102] = 1;
    } else if (choice < 10) {
    } else if (choice < 37) {
        if (choice >= 29) {
            func_800E42B0(object, choice - 29);
            if (D_800FC270[1266] != 0) {
                previous = func_800B31F8();
                func_800B3208(282);
                func_800E9774(*(int *)(object + 188));
                D_800FE0EE = 3;
                func_800D53A0(D_800F5900, 14);
                func_800B3208(previous & 0xFFFF);
                object[19102] = 1;
            } else {
                func_800DFFF4(object, 1);
            }
        }
    }
}
