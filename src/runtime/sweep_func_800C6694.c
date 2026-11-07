typedef struct {
    int v;
    char p0[10];
    unsigned short n;
    char p1[16];
} Rec;
typedef struct {
    int p0;
    int id;
} Obj;

extern signed char D_80102000[];
extern int D_80101940;
extern Rec *func_800DCCF4(int);
extern void func_800C6840(Obj *, int, int, int, int, int);

void func_800C6694(Obj *o)
{
    unsigned char cnt[12];
    unsigned char i;
    unsigned char j;
    unsigned char k;
    int flag;
    Rec *r;

    r = func_800DCCF4(o->id);
    r += (unsigned short)(r->n + 1);
    for (i = 0; i < 12; i++) {
        cnt[i] = 0;
    }
    for (i = 0; i < 12; i++) {
        signed char t = D_80102000[i] - 2;
        if (t != -1) {
            cnt[t]++;
        }
    }
    for (i = 0; i < 12; i++, r++) {
        D_80101940 = r->v;
        flag = 0;
        if (cnt[i] != 0) {
            k = 0;
            for (j = 0; j < 12; j++) {
                if (D_80102000[j] == i + 2) {
                    if (i >= 8) {
                        flag = 1;
                    }
                    func_800C6840(o, cnt[i], j, k, D_80101940, flag);
                    k++;
                }
            }
        }
    }
}
