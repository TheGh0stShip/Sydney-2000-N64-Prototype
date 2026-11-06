extern int D_800F2744;

void func_800AEBB8(unsigned char *state, float *position,
                   int arg2, int arg3, volatile float arg4)
{
    float *copy = (float *)(state + 0x2C);
    float final;
    int global;
    int *group = (int *)(state + 0x10);

    *(int *)(state + 0x00) = 0;
    *(int *)(state + 0x48) = 0;
    *(int *)(state + 0x1C) = 0;
    *(int *)(state + 0x28) = 0;
    *(int *)(state + 0x44) = 0;
    copy[0] = 0.0f;
    copy[1] = 0.0f;
    copy[2] = 0.0f;
    group[0] = 0;
    group[1] = 0;
    group[2] = 0;
    *(int *)(state + 0x00) = 3;
    copy[0] = position[0];
    copy[1] = position[1];
    copy[2] = position[2];
    final = arg4;
    *(int *)(state + 0x1C) = arg2;
    *(int *)(state + 0x20) = arg3;
    *(float *)(state + 0x24) = final;
    global = D_800F2744;
    *(int *)(state + 0x08) = 0;
    *(int *)(state + 0x28) = global;
}
