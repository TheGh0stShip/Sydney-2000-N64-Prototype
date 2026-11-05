/* Draw a layer with the given colour, shifted by the object's vertical
 * offset unless the object is in fixed mode. */
typedef struct View {
    short x;
    short y;
} View;

extern void func_800D33A0(void *layer, View *view, int a, int b);
extern int D_801006F0;
extern View D_800F1978;

void func_8009D918(char *obj, int color)
{
    int off;

    D_801006F0 = *(volatile int *)&color;
    if (*(int *)(obj + 19080) == 0) {
        off = *(short *)(obj + 19076);
        D_800F1978.y += off;
        func_800D33A0(obj + 20488, &D_800F1978, 0, -1);
        off = *(short *)(obj + 19076);
        D_800F1978.y -= off;
    } else {
        func_800D33A0(obj + 20488, &D_800F1978, 0, -1);
    }
}
