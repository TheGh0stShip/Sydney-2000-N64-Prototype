#ifndef LEAF_NAME
#define LEAF_NAME copyFieldIfStatusClear
#endif

#ifndef FIELD_OFFSET
#define FIELD_OFFSET 0x50
#endif

int LEAF_NAME(void *object, unsigned short status, int *destination) {
    if (status == 0) {
        *destination = *(int *)((char *)object + FIELD_OFFSET);
        return 0;
    }
    return -1000;
}
