extern float D_800847B0;
extern float D_800847B4;

int func_8009BEB8(float value)
{
    register float result asm("$f0") = value;
    register float divisor asm("$f2");

    result *= D_800847B0;
    divisor = D_800847B4;
    result /= divisor;
    return (int)result + 22100;
}
