typedef struct { float a, b, c; } V;
typedef struct {
    char pad[0x508];
    float m508;
    char p2[0x534 - 0x50C];
    float m534;
    char p3[0xA00 - 0x538];
    int mode;
    char p4[0xC];
    V arr[1];
    char p5[0xDF0 - 0xA1C];
    float mDF0;
} G;

extern G *D_800FC270;

void func_800954BC(char *object)
{
    float value = D_800FC270->arr[((signed char *)object)[0x75A8]].b;

    if (D_800FC270->mode == 5 && D_800FC270->mDF0 < value) {
        D_800FC270->mDF0 = value;
    }
    if (D_800FC270->mode == 4 || D_800FC270->mode == 0 ||
        D_800FC270->mode == 1 || D_800FC270->mode == 2) {
        if (*(unsigned char *)(object + 0x75AB) != 4) {
            if (D_800FC270->m508 < value) {
                D_800FC270->m508 = value;
            }
        }
    }
    if (D_800FC270->mode == 4 && D_800FC270->m534 < value) {
        D_800FC270->m534 = value;
    }
}
