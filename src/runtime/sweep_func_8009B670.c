typedef struct {
    char pad0[0x20];
    unsigned char state;
    char pad21[0x3C - 0x21];
} Kind;
typedef struct {
    signed char kind;         /* 0x0 */
    unsigned char variant;    /* 0x1 */
    char pad2[7];
    signed char value;        /* 0x9 */
    char padA[2];
} Entry;
typedef struct {
    Kind kinds[42];
    char pad9D8[0xA10 - 42 * 0x3C];
    Entry entries[16];        /* 0xA10 */
} Glob;
typedef struct {
    char pad0[0x1A8];
    unsigned char kind;       /* 0x1A8 */
    unsigned char variant;    /* 0x1A9 */
} Player;
extern Glob *D_800FC270;
extern char D_800F1798[];
extern int func_800DA804(int a, int b, void *c, int d, int e);
signed char func_8009B670(Player *p)
{
    int done;
    unsigned int i;
    unsigned int best;
    signed char n;
    Entry *list;
    n = func_800DA804(0, 0, D_800F1798, 0, 0);
    done = 0;
    i = 0;
    best = 0;
    list = D_800FC270->entries;
    while (1) {
        if (done) break;
        if (!(i < n)) break;
        if (p->variant == list[i].variant) {
            if (p->kind == list[i].kind) {
                done = 1;
            } else {
                best = i;
                i = best + 1;
            }
        } else {
            i++;
        }
    }
    if (done == 0) {
        return list[best].value;
    }
    return list[i].value;
}
