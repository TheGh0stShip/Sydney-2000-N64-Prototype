/* Runtime-stage C reconstruction: lay out the four one-unit border rectangles of a panel. */
typedef struct Rect { int unused; } Rect;

typedef struct Panel {
    char unused0[0x200];
    Rect top;
    Rect right;
    Rect left;
    Rect bottom;
    char unused210[0x358];
    float width;
    float height;
} Panel;

extern void func_8001A1D8(Rect *rect, float x0, float y0, float x1, float y1);

void func_800D328C(Panel *panel) {
    func_8001A1D8(&panel->top, 0.0f, 0.0f, panel->height, 1.0f);
    func_8001A1D8(&panel->right, 0.0f, panel->width - 1.0f, panel->height, panel->width);
    func_8001A1D8(&panel->left, 0.0f, 1.0f, 1.0f, panel->width - 1.0f);
    func_8001A1D8(&panel->bottom, panel->height - 1.0f, 1.0f, panel->height, panel->width - 1.0f);
}
