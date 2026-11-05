int func_800AB640(unsigned char *stack)
{
    int *top = *(int **)(stack + 12);
    if (*(int **)(stack + 8) < top) {
        *(int **)(stack + 12) = top - 1;
        return top[-1];
    }
    return 0;
}
