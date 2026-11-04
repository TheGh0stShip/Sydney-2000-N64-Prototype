#ifndef LEAF_NAME
#define LEAF_NAME setWordReturnValue
#endif

#ifndef FIELD_VALUE
#define FIELD_VALUE 0
#endif

int LEAF_NAME(int *value) {
    return *value = FIELD_VALUE;
}
