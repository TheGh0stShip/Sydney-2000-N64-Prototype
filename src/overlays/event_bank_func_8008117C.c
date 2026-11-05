extern void func_800C0110(void *);
extern char D_800F3BC0[];

void func_8008117C(char *obj)
{
    unsigned char state;

    state = (obj + 0x8000)[3229];
    if (state - 3 >= 2U) {
        func_800C0110(D_800F3BC0);
    }
}
