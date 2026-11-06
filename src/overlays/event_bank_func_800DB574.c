#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

extern char *D_800FC270;

int func_800DB574(char *obj, unsigned char k)
{
    char *data;

    if (FIELD(obj, 1557, unsigned char) != 3) {
        data = D_800FC270;
        return FIELD(data,
                     2584 +
                         (FIELD(obj, 1550, unsigned char) *
                              FIELD(data, 2573, unsigned char) +
                          (k - FIELD(obj, 1553, unsigned char))) *
                             12,
                     signed char);
    }
    return 0;
}
