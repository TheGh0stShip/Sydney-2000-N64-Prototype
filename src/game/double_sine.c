#ifndef LEAF_NAME
#define LEAF_NAME doubleSine
#endif

extern volatile const double sinePi;
extern volatile const double sineNegativeHalf;
extern volatile const double sinePositiveHalf;
extern volatile const double sineReductionPi;
extern volatile const double sineEpsilon;
extern volatile const double sineCoefficient0;
extern volatile const double sineCoefficient1;
extern volatile const double sineCoefficient2;
extern volatile const double sineCoefficient3;
extern volatile const double sineCoefficient4;
extern volatile const double sineCoefficient5;
extern volatile const double sineCoefficient6;
extern volatile const double sineCoefficient7;

double LEAF_NAME(double angle) {
    double quotient;
    double squared;
    double polynomial;
    int turns;

    quotient = angle / sinePi;
    if (angle >= 0.0) {
        quotient += sinePositiveHalf;
    } else {
        quotient += sineNegativeHalf;
    }
    turns = (int)quotient;
    angle -= (double)turns * sineReductionPi;
    if (__builtin_fabs(angle) > sineEpsilon) {
        squared = angle * angle;
        polynomial = sineCoefficient0 * squared + sineCoefficient1;
        polynomial = polynomial * squared + sineCoefficient2;
        polynomial = polynomial * squared + sineCoefficient3;
        polynomial = polynomial * squared + sineCoefficient4;
        polynomial = polynomial * squared + sineCoefficient5;
        polynomial = polynomial * squared + sineCoefficient6;
        polynomial = polynomial * squared + sineCoefficient7;
        angle += angle * (squared * polynomial);
    }
    if ((turns & 1) != 0) {
        angle = -angle;
    }
    return angle;
}
