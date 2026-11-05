/* Draw a layer shifted by the object's vertical offset, with an optional
 * highlight width and the given colour word. */
typedef struct View {
    short x;
    short y;
    char pad[28];
    int width;
} View;

extern void func_800D33A0(void *layer, View *view, int a, int b);
extern int D_801006F0;
extern View D_800F18D8;

void func_8009D678(char *obj, int color, int highlight)
{
    int off;

    off = *(short *)(obj + 19076);
    D_800F18D8.y += off;
    D_801006F0 = *(volatile int *)&color;
    if (highlight) {
        D_800F18D8.width = 3840;
    } else {
        D_800F18D8.width = 0;
    }
    func_800D33A0(obj + 19088, &D_800F18D8, 0, -1);
    off = *(short *)(obj + 19076);
    D_800F18D8.y -= off;
}
