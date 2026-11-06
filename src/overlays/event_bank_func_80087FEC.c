#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

extern char *D_800FC270;

int func_80087FEC(char *obj, unsigned char k)
{
    char *d;

    if (FIELD(obj, 1557, unsigned char) != 3) {
        d = D_800FC270;
        return FIELD(d, 2584 + (FIELD(obj, 1550, unsigned char) * FIELD(d, 2573, unsigned char)
                                + (k - FIELD(obj, 1553, unsigned char))) * 12, signed char);
    }
    return 0;
}
