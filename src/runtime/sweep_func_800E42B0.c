typedef struct Block {
    int data[500];
} Block;

typedef struct BlockBank {
    int header[2];
    Block blocks[1];
} BlockBank;

extern char *D_800FC270;
extern BlockBank *D_800FF484;

void func_800E42B0(int unused, int index)
{
    *(Block *)(D_800FC270 + 524) = D_800FF484->blocks[index];
    D_800FC270[28] = D_800FC270[1265];
    *(short *)(D_800FC270 + 26) = 0;
    *(short *)(D_800FC270 + 20) = *(unsigned short *)(D_800FC270 + 1256);
    *(short *)(D_800FC270 + 22) = *(unsigned short *)(D_800FC270 + 1258);
    *(short *)(D_800FC270 + 24) = *(unsigned short *)(D_800FC270 + 1260);
    D_800FC270[3411] = D_800FC270[1267];
}
