#ifndef LEAF_NAME
#define LEAF_NAME splitValueHelpers
#endif

#ifndef FIRST_HELPER
#define FIRST_HELPER firstHelper
#endif

#ifndef SECOND_HELPER
#define SECOND_HELPER secondHelper
#endif

extern int FIRST_HELPER(int value);
extern int SECOND_HELPER(int value);

int LEAF_NAME(int input) {
    int value = FIRST_HELPER(input);

    SECOND_HELPER(value & ~1);
    return value & 1;
}
