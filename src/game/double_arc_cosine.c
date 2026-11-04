#ifndef LEAF_NAME
#define LEAF_NAME doubleArcCosine
#endif

#ifndef ATAN2_NAME
#define ATAN2_NAME doubleArcTangent2
#endif

extern double ATAN2_NAME(double numerator, double denominator);

double fabs(double value);
#pragma intrinsic (fabs)

double sqrt(double value);
#pragma intrinsic (sqrt)

double LEAF_NAME(double value) {
    register double absolute __asm__("$f2");
    register double denominator __asm__("$f14");

    absolute = fabs(value);
    if (absolute > 1.0) {
        return 0.0;
    }
    denominator = sqrt(1.0 - value * value);
    if (denominator != 0.0) {
        return 1.5707963267948966 - ATAN2_NAME(value, denominator);
    }
    if (value > 0.0) {
        return 0.0;
    }
    return 3.141592653589793;
}
