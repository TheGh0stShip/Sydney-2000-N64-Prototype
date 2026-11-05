typedef struct GameState {
    char pad[2560];
    int mode;
    int sound;
} GameState;

extern GameState *D_800FC270;
extern unsigned char D_800F2AD8[];
extern int D_800F2728;

extern int func_80075E54(unsigned char *state);
extern void func_800757A0(unsigned char *state);
extern void func_8009C0D8(int a, int b);
extern void func_8009BD50(int value);
extern void func_800834F4(void *object);
extern void func_8009D8F0(void *object);
extern void func_80073498(unsigned char *state);
extern void func_800AC334(void *object);
extern void func_800BBD78(void *list, int id, int flag, void *owner, int arg);
extern void func_800D771C(void *object);
extern void func_80075C80(unsigned char *state);
extern void func_80072EE4(unsigned char *state);

void func_80078970(unsigned char *state)
{
    switch (func_80075E54(state)) {
    case 2:
        func_800757A0(state);
        break;
    case 1:
        func_8009C0D8(1, -1);
        break;
    case 0:
        if (D_800FC270->mode == 4 &&
            (D_800FC270->sound == 2 || D_800FC270->sound == 4)) {
            func_8009BD50(state[1556]);
            func_800834F4(state + 1584);
            func_8009D8F0(state + 3660);
            if (state[65536 + 2841] >= 2) {
                func_800834F4(state + 28608);
                func_8009D8F0(state + 30684);
            }
            func_80073498(state);
            func_800AC334(state + 0x10A2C);
            func_800BBD78(D_800F2AD8, 12, 1, state, 2);
            func_800BBD78(D_800F2AD8, 13, 1, state, 2);
            D_800F2728 = 0;
            *(int *)(state + 65536 + 2824) = -7680;
            *(int *)(state + 172) = 0;
            *(int *)(state + 65536 + 2832) = 0;
            state[1556] = state[1557];
            func_800D771C(state + 0xD954);
            func_80075C80(state);
        } else {
            func_80072EE4(state);
        }
        break;
    }
}
