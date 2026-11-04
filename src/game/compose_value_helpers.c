#ifndef LEAF_NAME
#define LEAF_NAME composeValueHelpers
#endif

#ifndef FIRST_HELPER
#define FIRST_HELPER firstHelper
#endif

#ifndef SECOND_HELPER
#define SECOND_HELPER secondHelper
#endif

extern int FIRST_HELPER(int value);
extern int SECOND_HELPER(int value);

int LEAF_NAME(int value) {
    return SECOND_HELPER(FIRST_HELPER(value) | value);
}
