extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *object, int type, int x, int y);

void func_800AEDBC(unsigned char *object)
{
    unsigned char state;
    int type;

    state = object[0x811E];
    if (state != 0 && state != 5 && state != 1) {
        return;
    }
    type = 103;
    if (*(int *)(object + 0x815C) != 0) {
        type = 477;
    }
    object = D_800FC270;
    if (*(int *)(object + 2564) != 0) {
        func_800C0110(D_800F3BC0, type, 0, 0);
    }
}
