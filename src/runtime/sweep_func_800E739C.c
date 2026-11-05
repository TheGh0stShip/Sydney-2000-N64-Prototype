extern short func_800E7180(void *, void *, void *, void *);

typedef struct {
    int unk0;
    unsigned char *tbl[1];
} Owner800E739C;

void func_800E739C(Owner800E739C *obj, char *ent)
{
    unsigned char *hdr;
    unsigned char *p;
    unsigned char n;
    short r;

    hdr = obj->tbl[*(unsigned short *)(ent + 24)];
    p = hdr + *(unsigned short *)(hdr + 2);
    *(void **)(ent + 44) = 0;
    n = hdr[1];
    while (n != 0) {
        r = func_800E7180(obj, ent, hdr + 408, p + 4);
        if (r == 1) {
            *(void **)(ent + 44) = p;
            return;
        }
        p = p + p[4] + 6;
        p = (unsigned char *)((int)p & ~1);
        n--;
    }
}
