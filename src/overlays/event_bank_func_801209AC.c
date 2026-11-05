extern void func_800817B0(char *obj);

void func_801209AC(char *obj, int *msg)
{
    switch (msg[0]) {
    case 3:
        break;
    case 5:
        if (*(int *)(obj + 500) & 1) {
            func_800817B0(obj);
        }
        break;
    }
    *(int *)(obj + 16) = msg[1];
}
