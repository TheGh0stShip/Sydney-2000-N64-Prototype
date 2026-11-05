typedef struct Match {
    char pad0[1556];
    unsigned char mode;
    char pad1[0x10B06 - 1557];
    unsigned char phase;
    char pad2[0x10D28 - 0x10B07];
    int table[2][2];
    char pad3[0x10D39 - 0x10D38];
    unsigned char row;
    unsigned char col;
} Match;

extern unsigned int D_800F13F0;
extern void func_80074794(Match *self, int row, int col, int value);

void func_80079458(Match *self, unsigned char row, unsigned char col)
{
    int cur;

    if (self->mode == 5 && self->phase < 2 && row == self->row) {
        cur = self->col;
        if (cur == col) {
            func_80074794(self, row, cur, self->table[row][cur]);
            self->col++;
            D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
            self->row = D_800F13F0 >> 30;
        }
    }
}
