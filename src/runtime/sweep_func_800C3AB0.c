typedef struct {
    void *value;
    int type;
    int mask;
    unsigned short *table;
} Flag;

int func_800D98FC(int id);

int *func_800C3AB0(char *obj, int *out)
{
    Flag *flag = *(Flag **)(*(char **)(obj + 220) + 28);
    int v = 0;

    switch (flag->type) {
    case 0:
        v = *(int *)flag->value;
        break;
    case 1:
        v = *(short *)flag->value;
        break;
    case 2:
        v = *(signed char *)flag->value;
        break;
    }
    {
        int bits = v & flag->mask;
        v = bits != 0;
    }
    *out = func_800D98FC(flag->table[v]);
    return out;
}
