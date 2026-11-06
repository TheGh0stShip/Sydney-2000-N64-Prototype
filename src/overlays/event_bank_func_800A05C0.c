extern char *D_800FC270;
extern int D_8007589C[];
extern int D_800759F0;
extern void func_800D33A0(void *queue, void *message, int count, int timeout);

typedef struct {
    int pad0;
    float time;
    unsigned char pad8[2];
    unsigned char flags;
} Record;

void func_800A05C0(char *self, int announce)
{
    char *base = D_800FC270;
    Record *rec = (Record *)(base + 2576 + *(unsigned char *)(self + 24038) * 12);

    if (*(unsigned char *)(self + 24041) == 0) {
        int mode = *(int *)(base + 2560);

        if (mode != 6) {
            if (mode == 5) {
                if (rec->time < *(float *)(base + 3592)) {
                    *(float *)(base + 3592) = rec->time;
                    rec->flags |= 0x10;
                }
            } else {
                int k;
                float *best;

                if (mode == 4) {
                    k = 3;
                } else if (mode == 0) {
                    k = 0;
                } else if (mode == 1) {
                    k = 1;
                } else {
                    k = 2;
                }
                best = (float *)(D_800FC270 + k * 4);
                if (rec->time < best[339]) {
                    best[339] = rec->time;
                    rec->flags |= 0x10;
                }
            }
        }
    }
    if (announce == 1) {
        if (rec->flags & 0x10) {
            D_8007589C[4] = 691;
            D_8007589C[8] = 0x1800;
        } else {
            D_8007589C[4] = 694;
            D_8007589C[8] = 0;
        }
        D_800759F0 = *(int *)&rec->time;
        func_800D33A0(self + 13020, D_8007589C, 0, -1);
    }
}
