typedef struct {
    char pad0[0x20];
    unsigned char state;      /* 0x20 */
    char pad21[0x3C - 0x21];
} Kind;
typedef struct {
    signed char kind;         /* 0x0 */
    char pad1[8];
    signed char value;        /* 0x9 */
    char padA[2];
} Entry;
typedef struct {
    Kind kinds[42];
    char pad9D8[0xA10 - 42 * 0x3C];
    Entry entries[16];        /* 0xA10 */
} Glob;
extern Glob *D_800FC270;
extern char D_800F1798[];
extern int func_800DA804(int a, int b, void *c, int d, int e);
signed char func_8009B73C(Entry **out)
{
    int done;
    int i;
    unsigned int state;
    Glob *g;
    Kind *kinds;
    Entry *list;
    func_800DA804(0, 0, D_800F1798, 0, 0);
    done = 0;
    i = 0;
    g = D_800FC270;
    list = g->entries;
    kinds = g->kinds;
    do {
        if (list[i].kind != 8) {
            Kind *kp = &kinds[list[i].kind];
            state = kp->state;
        } else {
            state = 3;
        }
        if (state == 1) {
            done = 1;
        } else {
            i++;
        }
    } while (!done);
    if (out) {
        *out = &list[i];
    }
    return list[i].value;
}
