extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern float D_80076F18[][7];
extern void func_800A1F24(void *a, float *b, float *c, float *d);
extern void func_800C0110(void *a, int b, int c, int d);

void func_8009A4F8(unsigned char *state)
{
    unsigned char kind = state[0x8054];
    float vec[4];
    float dist;
    float aux;
    float base;
    float near;
    float mid;
    int first;
    int second;
    int mode;

    if (kind != 0 && kind != 5 && kind != 1) {
        return;
    }
    first = -1;
    second = first;
    if (state[0x8054] == 5) {
        dist = (*(float **)(state + 0x808C))[(signed char)state[0x8051] * 3 + (signed char)state[0x8050]];
    } else {
        func_800A1F24(state + 0x2F6C, vec, &dist, &aux);
        dist = dist / *(float *)0x80071444;
    }
    mode = *(int *)(D_800FC270 + 0xA00);
    if (mode < 6) {
        if (mode >= 0) {
            if (state[0x8054] == 5 &&
                (*(float **)(state + 0x808C))[(signed char)state[0x8051] * 3 + (signed char)state[0x8050]] == 0.0f) {
                first = 0xD8;
            } else {
                base = D_80076F18[D_800FC270[0xD53]][*(int *)(D_800FC270 + 0xA00)];
                near = base * *(float *)0x80071448;
                mid = base * *(float *)0x8007144C;
                if (dist <= near) {
                    if (state[0x8054] == 5) {
                        first = 0x7A;
                        second = 0xE5;
                    } else {
                        first = 0xCA;
                    }
                } else if (dist <= mid) {
                    if (state[0x8054] == 5) {
                        first = 0x79;
                        second = 0xE4;
                    } else {
                        first = 0xC9;
                    }
                } else if (dist <= base) {
                    if (state[0x8054] == 5) {
                        first = 0x7B;
                        second = 0xE6;
                    } else {
                        first = 0xCC;
                    }
                } else {
                    if (state[0x8054] == 5) {
                        first = 0x7B;
                        second = 0xE6;
                    } else {
                        first = 0xCB;
                    }
                }
            }
        }
    }
    if (first > 0 && *(int *)(D_800FC270 + 0xA04) != 0) {
        func_800C0110(D_800F3BC0, first, 0, 0);
    }
    if (second > 0 && *(int *)(D_800FC270 + 0xA04) != 0) {
        func_800C0110(D_800F3BC0, second, 0, 0);
    }
}
