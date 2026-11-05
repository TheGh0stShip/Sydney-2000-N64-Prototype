unsigned int func_800F08F4(unsigned char *object)
{
    unsigned int i;
    unsigned int result = 0;

    for (i = 0; i < 24; i++) {
        if (*(int *)(*(unsigned char **)(object + 232) + 240) == 0) {
            result = i;
            break;
        }
        object += 4;
    }
    return result;
}
