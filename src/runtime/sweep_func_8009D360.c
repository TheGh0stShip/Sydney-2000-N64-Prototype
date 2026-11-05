/* Draw a layer with a temporary vertical offset applied to the shared viewport. */
typedef struct View {
    short x;
    short y;
} View;

typedef struct Params {
    int mode;
    int value;
} Params;

extern void func_800D33A0(void *layer, View *view, int a, int b);
extern Params D_801006F0;
extern View D_800F1900;

void func_8009D360(char *obj, unsigned char mode, int value)
{
    int off;

    D_801006F0.mode = mode;
    D_801006F0.value = value;
    off = *(short *)(obj + 19076);
    D_800F1900.y += off;
    func_800D33A0(obj + 21888, &D_800F1900, 0, -1);
    off = *(short *)(obj + 19076);
    D_800F1900.y -= off;
}
