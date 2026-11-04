#ifndef LEAF_NAME
#define LEAF_NAME doubleTangent
#endif

#ifndef SINE_NAME
#define SINE_NAME doubleSine
#endif

#ifndef COSINE_NAME
#define COSINE_NAME doubleCosine
#endif

extern volatile const double tangentPi;
extern volatile const double tangentNegativeHalf;
extern volatile const double tangentPositiveHalf;
extern volatile const double tangentMaximum;
extern double SINE_NAME(double angle);
extern double COSINE_NAME(double angle);

double LEAF_NAME(double angle) {
    double quotient;
    double sine;
    double cosine;
    int turns;

    quotient = angle / tangentPi;
    if (angle >= 0.0) {
        quotient += tangentPositiveHalf;
    } else {
        quotient += tangentNegativeHalf;
    }
    turns = (int)quotient;
    angle -= (double)turns * tangentPi;
    if (angle == 0.0) {
        return 0.0;
    }
    sine = SINE_NAME(angle);
    cosine = COSINE_NAME(angle);
    if (cosine == 0.0) {
        return tangentMaximum;
    }
    return sine / cosine;
}
