#define F(p, o) (*(float *)((char *)(p) + (o)))
#define I(p, o) (*(int *)((char *)(p) + (o)))

void func_8011F4B4(char *self)
{
    float a = *(float *)0x80080C28;
    float b = *(float *)0x80080C2C;
    float c = *(float *)0x80080C30;

    I(self, 0x10C0) = 0;
    F(self, 0x10B0) = a;
    F(self, 0x10AC) = b;
    F(self, 0x10BC) = c;
}
