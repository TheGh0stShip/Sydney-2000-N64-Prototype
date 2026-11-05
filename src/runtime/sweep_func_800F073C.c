extern void func_80006B24(unsigned char *);

void func_800F073C(char *obj)
{
    *(float *)(obj + 476) -= 3.0f;
    if (*(float *)(obj + 476) < 4.0f) {
        *(float *)(obj + 476) = 4.0f;
    }
    if (255.0f < *(float *)(obj + 476)) {
        *(float *)(obj + 476) = 255.0f;
    }
    *(float *)(obj + 480) -= 3.0f;
    if (*(float *)(obj + 480) < 4.0f) {
        *(float *)(obj + 480) = 4.0f;
    }
    if (255.0f < *(float *)(obj + 480)) {
        *(float *)(obj + 480) = 255.0f;
    }
    *(float *)(obj + 484) -= 3.0f;
    if (*(float *)(obj + 484) < 4.0f) {
        *(float *)(obj + 484) = 4.0f;
    }
    if (255.0f < *(float *)(obj + 484)) {
        *(float *)(obj + 484) = 255.0f;
    }
    obj[433] = (unsigned int)*(float *)(obj + 476);
    obj[434] = (unsigned int)*(float *)(obj + 480);
    obj[435] = (unsigned int)*(float *)(obj + 484);
    func_80006B24((unsigned char *)obj + 432);
}
