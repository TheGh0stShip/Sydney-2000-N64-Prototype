#ifndef LEAF_NAME
#define LEAF_NAME doubleCosine
#endif

extern volatile const double cosinePi;
extern volatile const double cosineNegativeHalf;
extern volatile const double cosinePositiveHalf;
extern volatile const double cosineReductionPi;
extern volatile const double cosineCoefficient0;
extern volatile const double cosineCoefficient1;
extern volatile const double cosineCoefficient2;
extern volatile const double cosineCoefficient3;
extern volatile const double cosineCoefficient4;
extern volatile const double cosineCoefficient5;
extern volatile const double cosineCoefficient6;
extern volatile const double cosineTwo;
extern volatile const double cosineOne;

double LEAF_NAME(double angle) {
    double quotient;
    double squared;
    double fourth;
    double polynomial;
    double result;
    int turns;

    quotient = angle / cosinePi;
    if (angle >= 0.0) {
        quotient += cosinePositiveHalf;
    } else {
        quotient += cosineNegativeHalf;
    }
    turns = (int)quotient;
    angle -= (double)turns * cosineReductionPi;
    squared = angle * angle;
    fourth = squared * squared;
    polynomial = cosineCoefficient0 * squared + cosineCoefficient1;
    polynomial = polynomial * squared + cosineCoefficient2;
    polynomial = polynomial * squared + cosineCoefficient3;
    polynomial = polynomial * squared + cosineCoefficient4;
    polynomial = polynomial * squared + cosineCoefficient5;
    polynomial = polynomial * squared + cosineCoefficient6;
    result = cosineOne - squared / cosineTwo + fourth * polynomial;
    if ((turns & 1) != 0) {
        result = -result;
    }
    return result;
}
