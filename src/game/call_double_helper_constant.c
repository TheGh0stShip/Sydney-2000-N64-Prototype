#ifndef LEAF_NAME
#define LEAF_NAME callDoubleHelperConstant
#endif

#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif

#ifndef ARGUMENT_VALUE
#define ARGUMENT_VALUE 1.0
#endif

extern double HELPER_NAME(double value, double argument);

double LEAF_NAME(double value) {
    asm volatile ("" : : : "memory");
    return HELPER_NAME(value, ARGUMENT_VALUE);
}
