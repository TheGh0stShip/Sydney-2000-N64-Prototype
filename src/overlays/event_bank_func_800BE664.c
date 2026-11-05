#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

void func_800BE664(char *obj)
{
    unsigned char i;

    for (i = 0; i < FIELD(obj, 0x4900, int); i++) {
        { char *p = obj + i * 4; FIELD(p, 0x48AC, float) = FIELD(FIELD(p, 0x44E8, char *), 0x54, float); }
    }
}
