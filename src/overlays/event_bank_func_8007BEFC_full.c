typedef struct SoundBank {
    char pad0[0x68];
    int volume;
} SoundBank;

extern SoundBank D_800F1AE0;
extern int func_8001D4B8(SoundBank *bank, int id, int a, int b);
extern void func_8001D640(SoundBank *bank, int voice, int vol);
extern void func_8001D5D8(SoundBank *bank, int voice, int a, int id, int b, int c);
extern void func_800D0C20(char *a, int b, char *c, int d, int e);
extern void func_800A9BE8(char *obj, int mode);

#define S32(o) (*(int *)(self + 0x8000 + (o)))
#define U8(o) (*(unsigned char *)(self + 0x8000 + (o)))

void func_8007BEFC(char *self)
{
    int id;
    int voice;

    S32(0x464C) -= 256;
    if (S32(0x464C) <= 0) {
        switch (U8(0x4650) & 7) {
        case 1:
            id = 216;
            break;
        case 2:
            id = 215;
            break;
        case 3:
        default:
            id = 217;
            break;
        }
        if (U8(0xC9D) != 4) {
            SoundBank *bank = &D_800F1AE0;
            int scale = 32767;
            int v;
            v = func_8001D4B8(bank, id, 0, 1);
            func_8001D640(bank, v, (bank->volume * scale) >> 15);
            S32(0x4640) = v;
        }
        S32(0x464C) = S32(0xCA0) + 256;
    }
    S32(0xCA0) -= 256;
    if (S32(0xCA0) <= 0) {
        if (U8(0xC9D) == 2) {
            S32(0xC94) = 13;
        } else if (U8(0xC9D) != 5) {
            S32(0xC94) = 11;
            S32(0xCA0) = 0x12C00;
            if (U8(0xC9D) != 4) {
                SoundBank *bank = &D_800F1AE0;
                int scale = 26213;
                voice = func_8001D4B8(bank, 256, 0, -1);
                func_8001D640(bank, voice, 0);
                func_8001D5D8(bank, voice, (bank->volume * scale) >> 15, 75, 0, 0);
                S32(0x4648) = voice;
            }
            func_800D0C20(self + 0x5394, *(int *)(self + 0x5370), self + 0x5378,
                          *(unsigned char *)(self + 0x7804), *(unsigned char *)(self + 0x7805));
            func_800A9BE8(self + 0x86F8, 7);
            *(int *)(*(char **)(self + 0x536C) + 0xAC) = 0;
        } else {
            S32(0xCA0) = -256;
            S32(0xC94) = 12;
        }
    }
}
