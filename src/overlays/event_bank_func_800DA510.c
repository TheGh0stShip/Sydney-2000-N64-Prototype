#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

extern char *D_800FC270;
extern char D_800F3BC0[];
extern unsigned int D_800F2714;
extern void func_800C0110(void *sound, int id, int a, int b);
extern void func_80075E10(void *obj);

#define PLAY(obj, id) \
    if (FIELD(D_800FC270, 2564, int) != 0 && FIELD(obj, 24968, int) == 1) { \
        func_800C0110(D_800F3BC0, id, 0, 0); \
    }

void func_800DA510(void *obj)
{
    int alt = -1;
    int flag = 1;
    int snd;
    int m;
    unsigned char f;
    signed char c;

    if (FIELD(D_800FC270, 2560, int) == 5
        && (c = *FIELD(obj, 24716, signed char *)) != 8) {
        snd = c + 25;
    } else {
        snd = FIELD(obj, 24716, unsigned char *)[1];
        m = FIELD(D_800FC270, 2564, int);
        if (m != 5) {
            snd += 192;
            if (m == 1) {
                int n = FIELD(D_800FC270, 2560, int);
                if (n == 0) {
                    alt = 283;
                } else if (n == 1) {
                    alt = 285;
                } else {
                    alt = 287;
                }
                flag = 0;
            }
        } else {
            snd += 347;
        }
    }
    PLAY(obj, snd);
    f = FIELD(obj, 24716, unsigned char *)[10];
    if (f & 0xe) {
        if (f & 8) {
            D_800F2714 = (D_800F2714 * 16807) & 0x7fffffff;
            snd = (D_800F2714 >> 29) ? 381 : 380;
        } else if (f & 4) {
            snd = 379;
        } else {
            snd = 147;
        }
        PLAY(obj, snd);
        flag = 0;
    }
    if (alt != -1) {
        PLAY(obj, alt);
    }
    if (flag == 1) {
        func_80075E10(obj);
    }
}
