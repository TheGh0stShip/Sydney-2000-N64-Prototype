typedef struct GameState {
    char pad[2564];
    int sound;
} GameState;

extern GameState *D_800FC270;
extern unsigned char D_800F3BC0[];
#define D_80070CD8 (*(const float *)0x80070CD8)
#define D_80070CDC (*(const float *)0x80070CDC)
#define D_80070CE0 (*(const float *)0x80070CE0)
extern void func_800C0110(void *bank, int id, int a, int b);

#define PLAY(x) if (D_800FC270->sound != 0) func_800C0110(D_800F3BC0, (x), 0, 0)

void func_80077AF4(void *unused, unsigned char base, unsigned char type, float level)
{
    int id;

    switch (type) {
    case 0:
        if (level <= 0.0f) {
            id = base + 57;
            if (D_800FC270->sound != 0) {
                func_800C0110(D_800F3BC0, id, 0, 0);
                PLAY(139);
            }
        } else if (level <= D_80070CD8) {
            id = base + 53;
            if (D_800FC270->sound != 0) {
                func_800C0110(D_800F3BC0, id, 0, 0);
                PLAY(140);
            }
        } else {
            id = base + 49;
            if (D_800FC270->sound != 0) {
                func_800C0110(D_800F3BC0, id, 0, 0);
                PLAY(139);
            }
        }
        break;
    case 1:
        if (level <= 0.0f) {
            id = base + 59;
            if (D_800FC270->sound != 0) {
                func_800C0110(D_800F3BC0, id, 0, 0);
                PLAY(139);
            }
        } else if (level <= D_80070CDC) {
            id = base + 55;
            if (D_800FC270->sound != 0) {
                func_800C0110(D_800F3BC0, id, 0, 0);
                PLAY(140);
            }
        } else {
            id = base + 51;
            if (D_800FC270->sound != 0) {
                func_800C0110(D_800F3BC0, id, 0, 0);
                PLAY(139);
            }
        }
        break;
    case 2:
        if (level <= 0.0f) {
            id = base + 59;
            if (D_800FC270->sound != 0) {
                func_800C0110(D_800F3BC0, id, 0, 0);
                PLAY(139);
            }
        } else if (level <= D_80070CE0) {
            id = base + 55;
            if (D_800FC270->sound != 0) {
                func_800C0110(D_800F3BC0, id, 0, 0);
                PLAY(140);
            }
        } else {
            id = base + 51;
            if (D_800FC270->sound != 0) {
                func_800C0110(D_800F3BC0, id, 0, 0);
                PLAY(139);
            }
        }
        break;
    }
}
