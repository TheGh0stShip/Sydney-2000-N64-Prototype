void func_8009D8F8(void *object, int value1, int value2)
{
    unsigned char *bytes = object;

    bytes[19064] = 5;
    *(int *)(bytes + 19072) = 0;
    *(int *)(bytes + 19068) = 1;
    *(int *)(bytes + 19056) = value1;
    *(int *)(bytes + 19060) = value2;
}
