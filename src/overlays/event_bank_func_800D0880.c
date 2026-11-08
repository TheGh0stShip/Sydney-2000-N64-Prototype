typedef struct {
    signed char kind;
    signed char rate;
    char p2[2];
    signed char a[10];
    signed char b[10];
    signed char c[10];
    unsigned char d34;
    unsigned char d35;
} Entry;

typedef struct {
    char p0[3856];
    int f3856;
    char pF14[13268];
    Entry *cur;
    Entry *tracks;
    char p42F0[1094];
    short f18230;
    short f18232;
    char p473A[22];
    float f18256;
    char p4754[4];
    float f18264;
    float f18268;
    float f18272;
    char p4764[4];
    float f18280;
    float f18284;
    char p4770[21];
    unsigned char kind;
} Game;

extern void func_8008393C(Game *g, int id, Entry **out);

void func_80070D10(Game *g, unsigned char n, int add)
{
    unsigned char tbl[4] = { 0, 1, 3, 6 };
    unsigned char idx;
    unsigned char i;

    idx = tbl[n] + add;
    g->tracks = 0;
    func_8008393C(g, 19, &g->tracks);
    g->cur = g->tracks + idx;
    g->kind = g->cur->kind;
    g->f18256 = g->cur->rate / 100.0f;
    g->f18264 = g->cur->a[0] * 10 + g->cur->b[0];
    g->f18268 = 0.0f;
    for (i = 0; g->cur->a[i] != 0; i++) {
        g->f18268 += g->cur->a[i] * 10 + g->cur->b[i];
    }
    g->f18284 = 0.0f;
    if (g->cur->kind == 1) {
        for (i = 0; g->cur->c[i] != 0; i++) {
            g->f18284 += g->cur->c[i];
        }
    } else {
        g->f18284 = g->f18268;
    }
    g->f18272 = g->f18268;
    g->f18280 = g->cur->c[0];
    g->f3856 = g->cur->c[0] * 7680;
    g->f18232 = (signed char)g->cur->d34;
    g->f18230 = (signed char)g->cur->d35;
}
