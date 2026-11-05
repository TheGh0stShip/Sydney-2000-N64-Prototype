typedef struct {
    int data[500];
} StreamBuffer;

typedef struct {
    unsigned short slots[2];
    int used[1];
    StreamBuffer buffers[1];
} StreamTable;

typedef struct {
    unsigned char pad[524];
    StreamBuffer buffer;
} GameState;

extern StreamTable *D_800FF484;
extern unsigned int D_800FF544;
extern unsigned short D_800FF548[];
extern GameState *D_800FC270;

void func_800E98B0(void)
{
    unsigned int i;
    unsigned short *source;

    i = 0;
    source = D_800FF548;
    D_800FF484->used[D_800FF544] = 1;
    for (; i < 1; i++) {
        D_800FF484->slots[i + D_800FF544] = *source++;
    }
    D_800FF484->buffers[D_800FF544] = D_800FC270->buffer;
}
