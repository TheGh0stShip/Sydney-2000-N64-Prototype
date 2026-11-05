extern int D_800F4920[8];
extern char D_80089AC0[];

int func_80019680(int *handle, char *name);
void func_8001A1D8(int *handle, int a, int b, float x, float y);
void func_800191E0(int *handle, int arg);

void func_800CE604(short x, short y)
{
    float fx = x;
    float fy = y;
    int *handle = D_800F4920;
    unsigned char i;

    i = 0;
    while (1) {
        if (i >= 8) {
            break;
        }
        *handle = 0;
        if (func_80019680(handle, D_80089AC0) == 0) {
            func_8001A1D8(handle, 0, 0, fx, fy);
            func_800191E0(handle, -1);
        }
        handle++;
        i++;
    }
}
