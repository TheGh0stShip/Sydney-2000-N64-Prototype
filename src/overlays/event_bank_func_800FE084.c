typedef struct Obj {
    char pad0[0x1AE];
    short list[8];
} Obj;

extern unsigned int D_800F13F0;
extern unsigned short D_8007D958[];

void func_800FE084(Obj *obj)
{
    unsigned int s;
    unsigned int n;
    unsigned int i;

    s = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    n = s >> 30;
    D_800F13F0 = s;
    for (i = 0; i <= ({ unsigned int t = n; t; }); i++) {
        unsigned int r;

        r = (D_800F13F0 * 16807) & 0x7FFFFFFF;
        D_800F13F0 = r;
        r >>= 29;
        obj->list[i] = D_8007D958[r];
    }
    obj->list[i] = -1;
}
