#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

void func_800BCC68(char *obj)
{
    unsigned char i;

    for (i = 0; i < FIELD(obj, 0x4494, int); i++) {
        { char *p = obj + i * 4; FIELD(p, 0x4440, float) = FIELD(FIELD(p, 0x42FC, char *), 0x5C, float); }
    }
}
