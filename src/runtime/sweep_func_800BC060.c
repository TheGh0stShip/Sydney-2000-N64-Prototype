unsigned int func_800BC060(unsigned char *object)
{
    unsigned int result = object[1];
    if (result != 0) {
        result = object[0] & 0xF;
    }
    return result;
}
