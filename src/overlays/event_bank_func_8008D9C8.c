extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern float D_80077668[][7];
extern void func_8009F450(void *a, float *b, float *c, float *d);
extern void func_800C0110(void *a, int b, int c, int d);

void func_8008D9C8(unsigned char *state)
{
    unsigned char kind = state[0x8417];
    float vec[4];
    float dist;
    float aux;
    float base;
    float mid;
    float near;
    int first;
    int second;
    int mode;

    if (kind != 0 && kind != 5 && kind != 1) {
        return;
    }
    first = -1;
    base = D_80077668[D_800FC270[0xD53]][*(int *)(D_800FC270 + 0xA00)];
    mid = base * *(float *)0x8007137C;
    near = base * *(float *)0x80071380;
    second = first;
    if (state[0x8417] == 5) {
        dist = (*(float **)(state + 0x844C))[(signed char)state[0x8415] * 3 + (signed char)state[0x8414]];
    } else {
        func_8009F450(state + 0x5A9C, vec, &dist, &aux);
        dist = dist / *(float *)0x80071384;
    }
    mode = *(int *)(D_800FC270 + 0xA00);
    if (mode < 6) {
        if (mode >= 0) {
            if (state[0x8417] == 5 &&
                (*(float **)(state + 0x844C))[(signed char)state[0x8415] * 3 + (signed char)state[0x8414]] == 0.0f) {
                first = 0xD2;
                second = 0xE1;
            } else if (dist <= near) {
                if (state[0x8417] == 5) {
                    first = 0x77;
                    second = 0xE0;
                } else {
                    first = 0xC6;
                }
            } else if (dist <= mid) {
                if (state[0x8417] == 5) {
                    first = 0x76;
                    second = 0xDF;
                } else {
                    first = 0xC5;
                }
            } else if (dist <= base) {
                if (state[0x8417] == 5) {
                    first = 0x78;
                    second = 0xE2;
                } else {
                    first = 0xC8;
                }
            } else {
                if (state[0x8417] == 5) {
                    first = 0x78;
                    second = 0xE2;
                } else {
                    first = 0xC7;
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
