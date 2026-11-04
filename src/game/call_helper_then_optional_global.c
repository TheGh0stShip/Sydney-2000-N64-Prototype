#ifndef LEAF_NAME
#define LEAF_NAME callHelperThenOptionalGlobal
#endif
#ifndef FIRST_HELPER_NAME
#define FIRST_HELPER_NAME firstHelper
#endif
#ifndef SECOND_HELPER_NAME
#define SECOND_HELPER_NAME secondHelper
#endif
#ifndef GLOBAL_BASE_NAME
#define GLOBAL_BASE_NAME globalBase
#endif
#ifndef GLOBAL_OFFSET
#define GLOBAL_OFFSET 0x4F9C
#endif
#ifndef SECOND_ARGUMENT_NAME
#define SECOND_ARGUMENT_NAME secondArgument
#endif

typedef struct {
    char padding[GLOBAL_OFFSET];
    int value;
} GlobalState;

extern GlobalState GLOBAL_BASE_NAME;
extern char SECOND_ARGUMENT_NAME[];
extern void FIRST_HELPER_NAME(int first, int second);
extern void SECOND_HELPER_NAME(void *first, int *second);

void LEAF_NAME(void) {
    FIRST_HELPER_NAME(2, 0);
    if (GLOBAL_BASE_NAME.value != 0) {
        SECOND_HELPER_NAME(
            SECOND_ARGUMENT_NAME,
            &GLOBAL_BASE_NAME.value
        );
    }
}
