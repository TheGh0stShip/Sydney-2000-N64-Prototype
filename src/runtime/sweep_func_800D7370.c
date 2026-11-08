typedef struct {
    char p0[220];
    int bg;
    int top;
    int mid;
    int left;
    int right;
} Frame;

void func_8001A330(int *res, int v);
void func_8001A1D8(int *res, float x0, float y0, float x1, float y1);
void func_8001A210(int *res, float a, float b, float c, float d, int e);
void func_800191E0(int *res, unsigned int color);

void func_800D7370(Frame *f)
{
    int res;

    res = 0;
    func_8001A330(&res, 0xFFFF);
    func_8001A1D8(&res, -18.0f, -3.5f, 479.0f, 11.5f);
    func_8001A210(&res, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&res, 0x82000000);
    f->bg = res;
    res = 0;
    func_8001A330(&res, 0xFFFF);
    func_8001A1D8(&res, -19.0f, -4.5f, 480.0f, -3.5f);
    func_8001A210(&res, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&res, 0xFF000000);
    f->top = res;
    res = 0;
    func_8001A330(&res, 0xFFFF);
    func_8001A1D8(&res, -19.0f, 11.5f, 480.0f, 12.5f);
    func_8001A210(&res, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&res, 0xFF000000);
    f->mid = res;
    res = 0;
    func_8001A330(&res, 0xFFFF);
    func_8001A1D8(&res, -19.0f, -3.5f, -18.0f, 11.5f);
    func_8001A210(&res, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&res, 0xFF000000);
    f->left = res;
    res = 0;
    func_8001A330(&res, 0xFFFF);
    func_8001A1D8(&res, 479.0f, -3.5f, 480.0f, 11.5f);
    func_8001A210(&res, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&res, 0xFF000000);
    f->right = res;
}
