#ifndef LEAF_NAME
#define LEAF_NAME doubleAbsolute
#endif

double fabs(double value);
#pragma intrinsic (fabs)

double LEAF_NAME(double value) {
    return fabs(value);
}
