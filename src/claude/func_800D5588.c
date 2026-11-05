extern char D_800F5900[];
extern char D_8008A168[];
extern char D_8008A038[];
extern char D_8008A090[];
extern void func_800AC3D4(char *self);
extern void func_800AE568(char *self);
extern void func_800D28B0(char *self);
extern void func_800ADED4(char *self);

#define F(o) (*(int *)(D_800F5900 + (o)))

void func_800D5588(void)
{
    func_800AC3D4(D_800F5900);
    *(char **)(D_800F5900 + 0xB4) = D_8008A168;
    F(0xD8) = 1;
    func_800AE568(D_800F5900 + 0xDC);
    F(0x280) = 0;
    *(char **)(D_800F5900 + 0xB4) = D_8008A038;
    F(0x288) = 0;
    func_800D28B0(D_800F5900 + 0x294);
    func_800ADED4(D_800F5900 + 0x914);
    func_800ADED4(D_800F5900 + 0x9E8);
    F(0xAD8) = -1;
    F(0xAD4) = -1;
    F(0xAD0) = -1;
    F(0xACC) = 0;
    F(0x284) = 0;
    F(0x28C) = 0;
    F(0x290) = 0;
    *(char **)(D_800F5900 + 0xB4) = D_8008A090;
    F(0xADC) = 0;
    F(0xAE0) = 0;
}
