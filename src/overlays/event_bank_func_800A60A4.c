/* Play the stage/round announcement cues and then refresh the stage display. */
typedef struct {
    unsigned char pad0[0xA00];
    int stage;
    int round;
} StageTable;

typedef struct {
    unsigned char pad0[0x7CA8];
    int active;
    signed char attempt;
    unsigned char pad7CAD[2];
    unsigned char mode;
} StageOwner;

extern StageTable *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(char *bank, int id, int a, int b);
extern void func_80076BB4(StageOwner *p);

#define QUIET(p) ((unsigned char)((p)->mode - 3) < 2)

void func_800750A4(StageOwner *p)
{
    int round = D_800FC270->round;
    int first;
    int second;
    int third;

    if (round == 0) {
        return;
    }
    second = -1;
    first = second;
    third = second;
    if (p->active != 0 && p->attempt == 0) {
        int stage = D_800FC270->stage;
        if (stage == 5) {
            third = 24;
        } else if (stage != 4) {
            if (stage == 0) {
                third = 182;
            } else if (stage == 1) {
                third = 184;
            } else if (stage == 2) {
                third = 186;
            }
        } else if (round == 1) {
            third = 475;
            second = 113;
            first = 469;
        } else if (round == 4) {
            third = 476;
            second = 113;
            first = 470;
        } else if (round == 5) {
            third = 474;
            second = 113;
            first = 468;
        }
    }
    if (first != -1 && !QUIET(p)) {
        func_800C0110(D_800F3BC0, first, 0, 0);
    }
    if (second != -1 && !QUIET(p)) {
        func_800C0110(D_800F3BC0, second, 0, 0);
    }
    if (third != -1 && !QUIET(p)) {
        func_800C0110(D_800F3BC0, third, 0, 0x12C00);
    }
    func_80076BB4(p);
}
