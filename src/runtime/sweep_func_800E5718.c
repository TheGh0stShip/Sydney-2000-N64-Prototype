extern unsigned char D_800FF3CB;
extern unsigned char D_800FF3CF;
extern unsigned char D_800FF3D3;
extern unsigned char D_800FF3E4[];
extern void func_80006B24(void *);

void func_800E5718(char *output, int *entry)
{
    if (entry[0] == 5) {
        D_800FF3E4[1] = D_800FF3CB;
        D_800FF3E4[3] = D_800FF3CF;
        D_800FF3E4[2] = D_800FF3D3;
        func_80006B24(D_800FF3E4);
    }

    *(int *)(output + 16) = entry[1];
}
