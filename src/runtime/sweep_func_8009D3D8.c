/* Prepare and draw a layer; unless the object is in fixed mode the shared
 * viewport is temporarily shifted by the object's vertical offset. */
typedef struct View {
    short x;
    short y;
} View;

extern void func_800D29E0(void *layer);
extern void func_800D33A0(void *layer, View *view, int a, int b);
extern int D_801006F0;
extern View D_800F1950;

void func_8009D3D8(char *obj, unsigned char mode)
{
    int off;

    D_801006F0 = mode;
    func_800D29E0(obj + 20488);
    if (*(int *)(obj + 19080) == 0) {
        off = *(short *)(obj + 19076);
        D_800F1950.y += off;
        func_800D33A0(obj + 20488, &D_800F1950, 0, -1);
        off = *(short *)(obj + 19076);
        D_800F1950.y -= off;
    } else {
        func_800D33A0(obj + 20488, &D_800F1950, 0, -1);
    }
}
