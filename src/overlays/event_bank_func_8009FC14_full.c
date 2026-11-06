extern unsigned short D_80075724[];
extern unsigned int D_800F2714;
extern void func_800D2424(void *a, int b, int c);
extern void func_80074D14(char *self, int id, int vol, int d);

typedef struct {
    unsigned char pad[757];
    unsigned char flag;
    unsigned char pad2[2];
} Entry;

static inline Entry *GetEntry(char *self, unsigned int i)
{
    if (i >= *(unsigned int *)(self + 0x468C)) {
        i = *(unsigned int *)(self + 0x468C) - 1;
    }
    return &(*(Entry **)(self + 0x4688))[i];
}

static inline unsigned int Rand(unsigned int n)
{
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    return ((D_800F2714 >> 15) * n) >> 16;
}

void func_8009FC14(char *self, signed char idx, int pos, unsigned char quiet)
{
    int snd = -1;
    unsigned int bit = 1 << idx;
    unsigned int k;
    unsigned char kind;
    unsigned int flags;
    unsigned int r;
    int d;
    int v;

    if (idx < (signed char)(*(unsigned char *)(self + 0x468F) - 1)) {
        kind = GetEntry(self, idx)->flag;
        if ((*(unsigned char **)(self + 0x5CA0))[426] == 1) {
            func_800D2424(self + 18068, kind, idx);
        }
        if (pos == -7680) {
            goto check;
        }
        flags = *(unsigned int *)(self + 0x5E20);
        if (flags & bit) {
            goto check;
        }
        *(unsigned int *)(self + 0x5E20) = flags | bit;
        if (idx < (signed char)(*(unsigned char *)(self + 0x468F) - 2)) {
            snd = D_80075724[idx - 1];
            if (idx == *(unsigned char *)(self + 0x5E3D)) {
                int w = *(int *)(self + 0x5E48);
                if (w != -7680) {
                    d = w - pos;
                    if (d < -7680) {
                        snd = 239;
                    } else if (d >= 7681) {
                        snd = 238;
                    } else {
                        snd = 240;
                    }
                }
                *(int *)(self + 0x5E40) = pos;
            } else {
                r = Rand(100);
                if (r < 30) {
                    if (idx >= 2 && quiet == 0) {
                        if (GetEntry(self, idx - 1)->flag == 0) {
                            snd = 187;
                        } else {
                            snd = 188;
                        }
                    }
                } else if (r < 50) {
                    if (kind == 1) {
                        snd = 189;
                    }
                }
            }
        } else {
            snd = 190;
        }
    } else {
        if ((*(unsigned char **)(self + 0x5CA0))[426] == 1) {
            func_800D2424(self + 18068, 0, -1);
        }
        flags = *(unsigned int *)(self + 0x5E20);
        if (flags & bit) {
            goto check;
        }
        *(unsigned int *)(self + 0x5E20) = flags | bit;
        v = *(int *)(self + 0x5E4C);
        if (v != -7680) {
            d = v - pos;
            if (d < -15360) {
                if (d < -76800) {
                    snd = 186;
                }
            } else if (d < 15360) {
                snd = 185;
            }
        }
        *(int *)(self + 0x5E44) = pos;
    }
check:
    if (snd != -1) {
        func_80074D14(self, snd, 3840, 0);
    }
    *(int *)(self + 0x5E50) = 0x1C200;
}
