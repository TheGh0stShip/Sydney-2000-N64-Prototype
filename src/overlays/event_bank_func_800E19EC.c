#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

extern char *D_800FC270;
extern char D_800F3BC0[];
extern unsigned int D_800F2714;
extern void func_800C0110(void *sound, int id, int a, int b);
extern void func_80076420(void *obj);

#define PLAY(obj, id) \
    if (FIELD(D_800FC270, 2564, int) != 0 && FIELD(obj, 25320, int) == 1) { \
        func_800C0110(D_800F3BC0, id, 0, 0); \
    }

void func_800E19EC(void *obj)
{
    int alt = -1;
    int flag = 1;
    int snd;
    int m;
    unsigned char f;
    signed char c;

    if (FIELD(D_800FC270, 2560, int) == 5
        && (c = *FIELD(obj, 25056, signed char *)) != 8) {
        snd = c + 73;
    } else {
        snd = FIELD(obj, 25056, unsigned char *)[1];
        m = FIELD(D_800FC270, 2564, int);
        if (m != 5) {
            snd += 241;
            if (m == 1) {
                int n = FIELD(D_800FC270, 2560, int);
                if (n == 0) {
                    alt = 332;
                } else if (n == 1) {
                    alt = 334;
                } else {
                    alt = 336;
                }
                flag = 0;
            }
        } else {
            snd += 395;
        }
    }
    PLAY(obj, snd);
    f = FIELD(obj, 25056, unsigned char *)[10];
    if (f & 0xe) {
        if (f & 8) {
            D_800F2714 = (D_800F2714 * 16807) & 0x7fffffff;
            snd = (D_800F2714 >> 29) ? 429 : 428;
        } else if (f & 4) {
            snd = 427;
        } else {
            snd = 196;
        }
        PLAY(obj, snd);
        flag = 0;
    }
    if (alt != -1) {
        PLAY(obj, alt);
    }
    if (flag == 1) {
        func_80076420(obj);
    }
}
