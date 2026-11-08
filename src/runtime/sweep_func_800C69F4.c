extern int D_800F271C;
extern signed char D_80102030[];
extern signed char D_80102000[];

int func_800C69F4(void)
{
    unsigned char i;
    if (D_800F271C == 7) {
        for (i = 0; i < 12; i++) {
            if (D_80102030[i] != -1) {
                if (D_80102030[i] == -2) D_80102030[i] = -1;
                return 1;
            }
            if (D_80102000[i] != 10 && D_80102000[i] != -1) return 1;
        }
        return 0;
    }
    for (i = 0; i < 12; i++) {
        if (D_80102030[i] != -1) {
            if (D_80102030[i] == -2) D_80102030[i] = -1;
            return 1;
        }
    }
    return 0;
}
