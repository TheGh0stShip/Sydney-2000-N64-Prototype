#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

extern char *D_800FC270;
extern char D_800F3BC0[];
extern unsigned int D_800F2714;
extern void func_800C0110(void *sound, int id, int a, int b);

void func_800DAAFC(void *obj)
{
    int alt;
    int snd;
    char *g = D_800FC270;
    int a = FIELD(g, 2560, int);
    int m;

    if (a == 4) {
        m = FIELD(g, 2564, int);
        if (m == 5) {
            snd = 414;
            goto none;
        } else if (m == a) {
            snd = 416;
            alt = 346;
        } else {
            snd = 415;
            alt = 345;
        }
    } else {
        D_800F2714 = (D_800F2714 * 16807) & 0x7fffffff;
        if ((D_800F2714 >> 29) != 0) {
            snd = 185;
        } else {
            snd = 184;
        }
    none:
        alt = -1;
    }
    if (FIELD(D_800FC270, 2564, int) != 0 && FIELD(obj, 24968, int) == 1) {
        func_800C0110(D_800F3BC0, snd, 0xc00, 0);
    }
    if (alt != -1) {
        if (FIELD(D_800FC270, 2564, int) != 0 && FIELD(obj, 24968, int) == 1) {
            func_800C0110(D_800F3BC0, alt, 0x4800, 0);
        }
    }
}
