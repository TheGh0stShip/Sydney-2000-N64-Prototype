#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

extern char *D_800FC270;
extern char D_800F3BC0[];
extern unsigned int D_800F2714;
extern void func_800C0110(void *sound, int id, int a, int b);

#define PLAY(obj, id) \
    if (FIELD(D_800FC270, 2564, int) != 0 && FIELD(obj, 24968, int) == 1) { \
        func_800C0110(D_800F3BC0, id, 0, 0); \
    }

void func_800DA6F0(void *obj)
{
    int alt = -1;
    int snd;
    signed char c;
    char *g;
    signed char *e;

    if (FIELD(D_800FC270, 2560, int) == 5
        && (c = *FIELD(obj, 24716, signed char *)) != 8) {
        snd = c + 33;
    } else {
        g = D_800FC270;
        snd = FIELD(obj, 24716, unsigned char *)[1] + 244;
        if (FIELD(g, 2560, int) == 4 && FIELD(obj, 25009, unsigned char) != 0) {
            e = (signed char *)(g + 2576
                + FIELD(obj, 1550, unsigned char) * FIELD(obj, 1555, unsigned char) * 12);
            while (e[0] == 8) {
                e += 12;
            }
            if (*(short *)(e + 2) != -1) {
                if (FIELD(D_800FC270, 2564, int) == 5) {
                    c = e[8];
                    snd = 513;
                    if (c >= 3) {
                        if (c >= 4) {
                            alt = 300;
                        } else {
                            alt = 305;
                        }
                    } else if (c == 0) {
                        snd = 481;
                        alt = 308;
                    } else if (c == 1) {
                        snd = 417;
                        alt = 306;
                    } else {
                        snd = 449;
                        alt = 307;
                    }
                    snd += ((unsigned char *)e)[1];
                    D_800F2714 = (D_800F2714 * 16807) & 0x7fffffff;
                    if ((D_800F2714 >> 28) == 0) {
                        alt = 299;
                    }
                } else if (FIELD(D_800FC270, 2564, int) == 4) {
                    if (e[8] < 3) {
                        alt = 311;
                    } else {
                        alt = 304;
                    }
                } else {
                    if (e[8] < 3) {
                        alt = 309;
                    } else {
                        alt = 302;
                    }
                }
            } else {
                alt = 301;
            }
        }
    }
    PLAY(obj, snd);
    if (alt != -1 && FIELD(obj, 1550, unsigned char) == 0) {
        PLAY(obj, 312);
        PLAY(obj, alt);
    }
    FIELD(obj, 24968, int) = 0;
}
