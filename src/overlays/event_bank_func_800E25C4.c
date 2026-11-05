extern void func_800CB7A8(void *p, float a, float b);

void func_800E25C4(char *obj)
{
    unsigned char i;

    i = 0;
loop:
    if (i < ((unsigned char *)obj)[1555]) {
        char *p = *(char **)((i << 2) + obj + 20208);

        if (p != 0) {
            func_800CB7A8(p + 1004, -40.958748f, 1.3106799f);
        }
        i++;
        goto loop;
    }
}
