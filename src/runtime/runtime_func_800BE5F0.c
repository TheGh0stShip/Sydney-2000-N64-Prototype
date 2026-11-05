typedef struct RuntimeRecord {
    unsigned char pad[36];
    int value;
} RuntimeRecord;

extern RuntimeRecord D_800F3890[];
extern unsigned char D_800F3BB0;

void func_800BE5F0(void)
{
    unsigned char i;

    for (i = 0; i < 20; i++) {
        D_800F3890[i].value = 0;
    }
    D_800F3BB0 = 0;
}
