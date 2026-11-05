typedef struct {
    unsigned char pad[80];
    unsigned int flags;
} Entry;

int func_800B9CDC(unsigned char *object, unsigned short index, unsigned int value)
{
    if (index >= *(unsigned int *)(object + 212)) {
        return 1;
    }
    (*(Entry **)(object + 216))[index].flags =
        ((*(Entry **)(object + 216))[index].flags & 0x80000000U) | value;
    return 0;
}
