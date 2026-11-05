extern float func_8002E810(float angle);
extern float func_8002EFF0(float angle);

void func_800AD4E0(float (*m)[4], float angle, int count) {
    float c;
    float s;
    float x;
    int i;

    if (angle == 0.0f) {
        return;
    }
    c = func_8002E810(angle);
    s = func_8002EFF0(angle);
    for (i = 0; i < count; i++) {
        x = m[i][1];
        m[i][1] = x * c - m[i][2] * s;
        m[i][2] = x * s + m[i][2] * c;
    }
}
