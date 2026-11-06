typedef struct {
    char pad0[0xD53];
    unsigned char mode;
} Game;

extern Game *D_800FC270;
extern char D_800F2758[];
extern int D_80083B40[];
extern int D_80083B90[];
extern int D_80083BE0[];
extern int D_80083C30[];
extern void func_80005A3C(int, int, void *, int);

void func_8008393C(int arg0, int arg1, int arg2)
{
    switch (D_800FC270->mode) {
    case 0:
        func_80005A3C(D_80083B40[arg1], arg2, D_800F2758, 1);
        break;
    case 1:
        func_80005A3C(D_80083B90[arg1], arg2, D_800F2758, 1);
        break;
    case 2:
        func_80005A3C(D_80083BE0[arg1], arg2, D_800F2758, 1);
        break;
    case 3:
        func_80005A3C(D_80083C30[arg1], arg2, D_800F2758, 1);
        break;
    }
}
