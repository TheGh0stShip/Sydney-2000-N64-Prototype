#ifndef LEAF_NAME
#define LEAF_NAME setByteReturnArgument
#endif
#ifndef FIELD_OFFSET
#define FIELD_OFFSET 0xD7
#endif
#ifndef FIELD_VALUE
#define FIELD_VALUE 1
#endif

typedef unsigned char u8;

void *LEAF_NAME(void *object, void *argument)
{
    ((u8 *)object)[FIELD_OFFSET] = FIELD_VALUE;
    return argument;
}
