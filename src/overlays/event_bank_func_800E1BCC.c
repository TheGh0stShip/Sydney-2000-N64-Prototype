#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

extern char *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *sound, int id, int a, int b);

#define PLAY(obj, id) \
    if (FIELD(D_800FC270, 2564, int) != 0 && FIELD(obj, 25320, int) == 1) { \
        func_800C0110(D_800F3BC0, id, 0, 0); \
    }

void func_800E1BCC(void *obj)
{
    int alt = -1;
    int snd;
    signed char c;
    char *g;
    signed char *e;

    if (FIELD(D_800FC270, 2560, int) == 5
        && (c = *FIELD(obj, 25056, signed char *)) != 8) {
        snd = c + 81;
    } else {
        g = D_800FC270;
        snd = FIELD(obj, 25056, unsigned char *)[1] + 293;
        if (FIELD(g, 2560, int) == 4 && FIELD(obj, 25381, unsigned char) != 0) {
            e = (signed char *)(g + 2576
                + FIELD(obj, 1550, unsigned char) * FIELD(obj, 1555, unsigned char) * 12);
            while (e[0] == 8) {
                e += 12;
            }
            if (*(short *)(e + 2) != -1) {
                if (FIELD(D_800FC270, 2564, int) == 5) {
                    c = e[8];
                    snd = 561;
                    if (c >= 3) {
                        if (c >= 4) {
                            alt = 348;
                        } else {
                            alt = 353;
                        }
                    } else if (c == 0) {
                        snd = 529;
                        alt = 356;
                    } else if (c == 1) {
                        snd = 465;
                        alt = 354;
                    } else {
                        snd = 497;
                        alt = 355;
                    }
                    snd += ((unsigned char *)e)[1];
                } else if (FIELD(D_800FC270, 2564, int) == 4) {
                    if (e[8] < 3) {
                        alt = 359;
                    } else {
                        alt = 352;
                    }
                } else {
                    if (e[8] < 3) {
                        alt = 357;
                    } else {
                        alt = 350;
                    }
                }
            } else {
                alt = 349;
            }
        }
    }
    PLAY(obj, snd);
    if (alt != -1 && FIELD(obj, 1550, unsigned char) == 0) {
        PLAY(obj, 360);
        PLAY(obj, alt);
    }
    FIELD(obj, 25320, int) = 0;
}
