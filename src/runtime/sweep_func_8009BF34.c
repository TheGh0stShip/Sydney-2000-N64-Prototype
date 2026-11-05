extern int D_801006E4;
extern int D_801006E8;
extern int D_801006EC;
extern void func_8009BEE0(int value);

void func_8009BF34(int a, int b)
{
    D_801006EC = b;
    D_801006E4 = a;
    D_801006E8 = -1;
    func_8009BEE0(11520);
}
