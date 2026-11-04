#ifndef LEAF_NAME
#define LEAF_NAME doubleArcTangent
#endif

extern volatile const double negativeHalfPi __asm__("D_80002250");
extern volatile const double positiveHalfPi __asm__("D_80002258");
extern volatile const double unitLimit __asm__("D_80002260");
extern volatile const double fractionBase __asm__("D_80002268");
extern volatile const double upperHalfPi __asm__("D_80002270");
extern volatile const double negativeUnit __asm__("D_80002278");
extern volatile const double lowerHalfPi __asm__("D_80002280");
extern volatile const double lowerPi __asm__("D_80002288");
extern volatile const double upperPi __asm__("D_80002290");

double LEAF_NAME(double numerator, double denominator)
{
    double ratio;
    double reduced;
    double fraction = 0.0;
    double result;
    int i;

    if (denominator == 0.0 && numerator == 0.0) {
        return 0.0;
    }
    if (denominator == 0.0) {
        if (numerator > 0.0) {
            return positiveHalfPi;
        }
        return negativeHalfPi;
    }

    ratio = numerator / denominator;
    reduced = ratio;
    if (__builtin_fabs(ratio) > unitLimit) {
        reduced = unitLimit / ratio;
    }
    for (i = 14; i > 0; i--) {
        double term = (double)(i * i) * reduced * reduced;
        fraction = term / ((double)(2 * i + 1) + fraction);
    }
    result = reduced / (fractionBase + fraction);
    if (ratio > fractionBase) {
        result = upperHalfPi - result;
    }
    if (ratio < negativeUnit) {
        result = lowerHalfPi - result;
    }
    if (denominator > 0.0) {
        return result;
    }
    if (numerator > 0.0) {
        return result - lowerPi;
    }
    return result + upperPi;
}
