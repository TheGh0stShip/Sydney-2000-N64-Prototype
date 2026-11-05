int func_800B1968(char *obj)
{
    int **p = *(int ***)(*(char **)(obj + 220) + 28);
    switch ((int)p[1]) {
    case 2: return *(signed char *)p[0];
    case 1: return *(short *)p[0];
    case 0: return *(int *)p[0];
    }
    return 0;
}
