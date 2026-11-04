#ifndef LEAF_NAME
#define LEAF_NAME callFunctionPointerRange
#endif

typedef void (*Function)(void);
typedef int s32;

void LEAF_NAME(s32 current, s32 end) {
    while (current < end) {
        Function function = *(Function *)current;

        current += sizeof(Function);

        if (function != 0) {
            function();
        }
    }
}
