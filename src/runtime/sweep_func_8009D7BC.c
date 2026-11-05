/* Draw a layer; in fixed mode it is drawn at a fixed height of 120,
 * otherwise shifted by the object's vertical offset. */
typedef struct View {
    short x;
    short y;
} View;

extern void func_800D33A0(void *layer, View *view, int a, int b);
extern View D_800F1860;

void func_8009D7BC(char *obj)
{
    int off;
    int saved;

    if (*(int *)(obj + 19080) == 0) {
        off = *(short *)(obj + 19076);
        D_800F1860.y += off;
        func_800D33A0(obj + 19088, &D_800F1860, 0, -1);
        off = *(short *)(obj + 19076);
        D_800F1860.y -= off;
    } else {
        saved = D_800F1860.y;
        D_800F1860.y = 120;
        func_800D33A0(obj + 19088, &D_800F1860, 0, -1);
        D_800F1860.y = saved;
    }
}
