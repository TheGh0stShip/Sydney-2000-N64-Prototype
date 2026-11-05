typedef struct {
    short *ptr;
    int id;
} Slot800DE4B8;

extern void func_800C3D90(void);
extern void func_800D9990(void);
extern void func_800C6CCC(void);
extern void func_800E9290(void);
extern void func_800DD6F0(void *, int);
extern void func_800D53A0(void *, int);
extern void func_800BC180(void *);
extern char *D_800FC270;
extern short *D_800FF484;
extern Slot800DE4B8 D_800FCD8C[];
extern char D_800F5900[];
extern char D_800F2AD8[];

void func_800DE4B8(char *obj, unsigned short mode, int arg)
{
    unsigned short i;

    if (arg != 0) {
        *(int *)(obj + 376) = 4;
        *(int *)(obj + 188) = arg;
        *(unsigned short *)(obj + 184) = mode;
        *(int *)(obj + 592) = -7680;
        func_800C3D90();
        *(int *)(D_800FC270 + 516) = *(int *)(D_800FC270 + 3432);
        *(short *)(D_800FC270 + 2524) = 0;
        func_800D9990();
        func_800C6CCC();
        if (*(unsigned short *)(obj + 184) == 2) {
            D_800FC270[508] = 0;
            *(short *)(obj + 596) = 0;
            func_800E9290();
            for (i = 0; i < 1; i++) {
                D_800FCD8C[i].ptr = D_800FF484 + i;
                D_800FCD8C[i].id = i + 29;
            }
            func_800DD6F0(obj, 0);
        } else {
            func_800D53A0(D_800F5900, 4);
        }
        func_800BC180(D_800F2AD8);
        *(int *)(obj + 172) = 0;
    }
}
