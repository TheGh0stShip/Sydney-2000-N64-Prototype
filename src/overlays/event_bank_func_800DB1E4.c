extern void func_800CB838(void *p, float a);

void func_800DB1E4(char *obj)
{
    unsigned char i;

    i = 0;
loop:
    if (i < ((unsigned char *)obj)[1555]) {
        char *p = *(char **)((i << 2) + obj + 20188);

        if (p != 0) {
            func_800CB838(p + 1004, 65.534f);
        }
        i++;
        goto loop;
    }
}
