extern int D_800F2744;

void func_800AEC9C(unsigned char *object, float *position)
{
    float *current = (float *)(object + 44);
    float *velocity = (float *)(object + 16);

    *(int *)(object + 0) = 0;
    *(int *)(object + 72) = 0;
    *(int *)(object + 28) = 0;
    *(int *)(object + 40) = 0;
    *(int *)(object + 68) = 0;
    current[0] = 0.0f;
    current[1] = 0.0f;
    current[2] = 0.0f;
    velocity[0] = 0.0f;
    velocity[1] = 0.0f;
    velocity[2] = 0.0f;
    *(int *)(object + 0) = 1;
    current[0] = position[0];
    current[1] = position[1];
    current[2] = position[2];
    *(int *)(object + 8) = 0;
    *(int *)(object + 40) = D_800F2744;
}
