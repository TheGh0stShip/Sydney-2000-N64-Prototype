#ifndef LEAF_NAME
#define LEAF_NAME valueInRange
#endif

#ifndef RANGE_MIN
#define RANGE_MIN 0
#endif

#ifndef RANGE_MAX
#define RANGE_MAX 1
#endif

int LEAF_NAME(int *value) {
    int current = *value;
    int result = 0;

    if (current < RANGE_MAX) {
        result = current >= RANGE_MIN;
    }
    return result;
}
