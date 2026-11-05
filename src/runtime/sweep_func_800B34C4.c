extern void func_800B2158(char *, int);

void func_800B34C4(char *obj)
{
    if (*(unsigned short *)(obj + 212) & 4) {
        func_800B2158(obj, 0);
    } else {
        func_800B2158(obj, 1);
    }
}
