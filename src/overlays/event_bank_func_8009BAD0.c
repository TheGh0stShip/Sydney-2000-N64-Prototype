typedef struct {
    char pad0[0xA00];
    int mode;
    int enabled;
} SoundCtx;

extern SoundCtx *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *, int, int, int);

#define PLAY(id) if (D_800FC270->enabled) func_800C0110(D_800F3BC0, (id), 0x300, 0)
#define PLAY1(id) if (D_800FC270->enabled == 1) func_800C0110(D_800F3BC0, (id), 0x300, 0)

void func_8009BAD0(void) {
    switch (D_800FC270->mode) {
    case 5:
        PLAY(29);
        break;
    case 4:
        switch (D_800FC270->enabled) {
        case 4:
            PLAY(529);
            PLAY(129);
            PLAY(532);
            break;
        case 5:
            PLAY(527);
            PLAY(129);
            PLAY(530);
            break;
        case 1:
            PLAY(528);
            PLAY(129);
            PLAY(531);
            break;
        }
        break;
    case 0:
        PLAY1(207);
        break;
    case 1:
        PLAY1(209);
        break;
    case 2:
        PLAY1(211);
        break;
    }
}
