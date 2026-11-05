typedef struct {
    int words[5];
} Block20;

typedef struct {
    Block20 block;
    unsigned char pad[40];
} Entry60;

typedef struct {
    unsigned char pad0[40];
    Entry60 entries[7];
    unsigned char pad1[48];
    unsigned char count;
} Globals;

extern Globals *D_800FC270;

void func_800DE350(unsigned char *object, int index)
{
    unsigned int i;
    Globals *base;

    for (i = 0; i < D_800FC270->count; i++) {
        base = D_800FC270;
        base->entries[i].block =
            *(Block20 *)(object + (i * 240 + index * 20) + 652);
    }
}
