extern char D_800F1AE0[];
extern char D_800445F0[];
extern int D_800F57DC[];
extern int func_8001D6CC(void *, int, int, int);
extern void func_8001D640(void *, int, int);
extern void func_800083B8(void *);
extern int func_800B31DC(void);
extern void func_800B31EC(int);
extern void func_800D496C(char *);

void func_800D51A4(char *obj, int mode, short id)
{
    int voice;

    if (*(int *)(obj + 648) == 0) {
        *(short *)(obj + 2762) = id;
        *(int *)(obj + 2752) = mode;
        *(int *)(obj + 2756) = mode;
        *(unsigned char *)(obj + 2760) = *(unsigned char *)(obj + 2763);
        if (*(int *)(obj + 2772) != -1) {
            voice = func_8001D6CC(D_800F1AE0, *(int *)(obj + 2772), 0, 0);
            *(volatile int *)(D_800F1AE0 + 100);
            func_8001D640(D_800F1AE0, voice, 0);
        }
        func_800083B8(D_800445F0);
        if (*(int *)(obj + 2752) == 0) {
            if (*(short *)(obj + 2762) == -1) {
                D_800F57DC[4] = 42;
                D_800F57DC[5] = 0;
            }
        } else if (*(int *)(obj + 2752) == 1) {
            D_800F57DC[4] = 100;
            D_800F57DC[5] = 0;
        }
        *(int *)(obj + 2748) = func_800B31DC();
        func_800B31EC(3);
        func_800D496C(obj);
        *(int *)(obj + 648) = 1;
    }
    *(int *)(obj + 644) = 1;
}
