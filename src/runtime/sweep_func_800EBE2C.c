extern void func_800EBC08(void *object, const float *values, float scale);

void func_800EBE2C(void *object, float x, float y, float z)
{
    float values[3];
    values[0] = x;
    values[1] = y;
    values[2] = z;
    func_800EBC08(object, values, 1.0f);
}
