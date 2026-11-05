typedef struct {
    char pad0[20];
    unsigned char header[8];
    unsigned char kind;
    char pad1[524 - 29];
    int modes[12];
    unsigned char levels[252];
    char pad2[1256 - 824];
    unsigned char info[8];
    unsigned short infoKind;
    unsigned char infoZero;
    unsigned char infoFlag;
    char pad3[2524 - 1268];
    unsigned short row;
    unsigned short pad4;
    unsigned short col;
    char pad5[3408 - 2530];
    unsigned short flags;
    unsigned char pad6;
    unsigned char flagByte;
} State;

extern State *D_800FC270;
extern void func_800B3AFC(void *, int, int);
extern void func_800B3870(void *, void *, int);
extern void func_800E19B8(void *);

void func_800DFC4C(void *arg)
{
    unsigned int i;
    int fill = 0;
    unsigned char *p;
    unsigned char *end;

    for (i = 0; i < 12; i++) {
        if (D_800FC270->flags & 0x10) {
            D_800FC270->modes[i] = 3;
        } else {
            D_800FC270->modes[i] = 0;
        }
    }
    if (D_800FC270->flags & 0x10) {
        fill = 100;
        D_800FC270->flags |= 7;
    }
    p = D_800FC270->levels;
    end = p + 252;
    do {
        *p++ = fill;
    } while (p != end);
    func_800B3AFC((char *)D_800FC270 + 824, 0, 384);
    func_800B3870(D_800FC270->info, D_800FC270->header, 8);
    D_800FC270->infoKind = D_800FC270->kind;
    D_800FC270->infoZero = 0;
    D_800FC270->infoFlag = D_800FC270->flagByte;
    if (D_800FC270->flags & 0x10) {
        for (D_800FC270->row = 0; D_800FC270->row < 12; D_800FC270->row++) {
            for (D_800FC270->col = 0; D_800FC270->col < 4; D_800FC270->col++) {
                func_800E19B8(arg);
            }
        }
    }
}
