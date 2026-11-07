typedef unsigned char u8;
typedef int s32;
typedef struct { u8 pad[3416]; u8 flag; } State;
extern s32 D_80039450;
extern State *D_800FC270;
void func_8008F7D0(s32 mode)
{
    if (D_80039450 != 0) {
        switch (mode) {
        case 2:
        case 4:
        case 5:
        case 6:
        case 9:
            D_800FC270->flag = 1;
            return;
        case 0:
        case 1:
        case 3:
        case 7:
        case 8:
        case 10:
        case 11:
            break;
        }
    }
    D_800FC270->flag = 0;
}
