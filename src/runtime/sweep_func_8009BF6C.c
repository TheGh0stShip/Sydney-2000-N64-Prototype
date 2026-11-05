extern unsigned char *D_800FC270;
extern int D_80100650;
extern unsigned char D_800F141C[];
extern int func_800D98FC(int id);
extern void func_800D33A0(void *object, void *data, int a, int b);

void func_8009BF6C(void *object, unsigned char *info)
{
    unsigned char index = info[424];
    int value;

    if (index != 8) {
        value = (int)(D_800FC270 + (index * 60 + 20));
    } else {
        value = func_800D98FC(info[425] + 181);
    }
    D_80100650 = value;
    func_800D33A0(object, D_800F141C, 1, -1);
}
