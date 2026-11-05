typedef struct {
    char pad0[524];
    int state[12];
    char pad1[1266 - 572];
    unsigned char flag;
    char pad2[1372 - 1267];
    unsigned char slots[32][4];
    unsigned char order[12];
    unsigned char seen[12];
    int count;
    char block[948];
    int timers[12];
} Ctx;

extern Ctx *D_800FC270;
extern void func_800B3AFC(void *, int, int);
extern void func_800E287C(void *, int);

void func_800E2788(void *self)
{
    unsigned int i;

    D_800FC270->count = 0;
    for (i = 0; i < 12; i++) {
        D_800FC270->seen[i] = 0;
        D_800FC270->timers[i] = 0;
        if (D_800FC270->state[i] == 3) {
            D_800FC270->order[D_800FC270->count] = i;
            D_800FC270->count++;
        }
    }
    for (i = 0; i < 32; i++) {
        D_800FC270->slots[i][0] = i;
        D_800FC270->slots[i][1] = D_800FC270->slots[i][2] = D_800FC270->slots[i][3] = 0;
    }
    func_800B3AFC(D_800FC270->block, 0, 948);
    D_800FC270->flag = 1;
    func_800E287C(self, 1);
}
