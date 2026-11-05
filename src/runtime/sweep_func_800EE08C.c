extern int func_800D98FC(int);
extern unsigned short D_800FFE20[];
extern char D_800FFE98[];

void func_800EE08C(unsigned short mask, int *out)
{
    unsigned int bit;
    unsigned char idx;
    unsigned char n;

    bit = 1;
    idx = 0;
    for (n = 6; n != 0; n--) {
        if (mask != 0) {
            while ((mask & bit) == 0) {
                bit <<= 1;
                idx++;
            }
            mask ^= bit;
            *out = func_800D98FC(D_800FFE20[idx]);
        } else {
            *out = (int)D_800FFE98;
        }
        out++;
    }
}
