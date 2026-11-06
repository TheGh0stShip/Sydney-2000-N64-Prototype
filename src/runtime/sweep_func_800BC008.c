/* Static array teardown: walks two arrays backwards (empty element dtors). */
typedef struct { char pad[24]; } Elem24;
typedef struct { char pad[8]; } Elem8;
extern Elem24 D_800F2AD8[13];
extern Elem8 D_800F2A70[13];

void func_800BC008(void) {
    Elem24 *p;
    Elem24 *base;
    Elem8 *q;
    char frame[16];

    if (D_800F2AD8 != 0) {
        base = D_800F2AD8;
        p = base + 13;
        while (base != p) {
            p--;
        }
    }
    if (D_800F2A70 != 0) {
        q = D_800F2A70 + 13;
        while (q != D_800F2A70) {
            q--;
        }
    }
}
