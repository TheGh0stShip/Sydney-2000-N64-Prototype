#ifndef LEAF_NAME
#define LEAF_NAME doubleSquareRoot
#endif

double sqrt(double value);
#pragma intrinsic (sqrt)

double LEAF_NAME(double value) {
    return sqrt(value);
}
