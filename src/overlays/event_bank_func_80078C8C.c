typedef struct Slot {
    short id;
    char pad2[10];
} Slot;

typedef struct GameState {
    char pad0[2572];
    unsigned char count;
    unsigned char stride;
    char pad1[2578 - 2574];
    Slot slots[1];
} GameState;

typedef struct Ext {
    char pad0[2820];
    unsigned char index;
    char pad1[2844 - 2821];
    int pending;
} Ext;

extern GameState *D_800FC270;
extern char D_800F1798[];
extern void func_80073E64(char *self);
extern void func_80075A2C(char *self);
extern void func_800DA804(int index, int flag, void *data, int a, int b);

static inline int Ext_hasMore(Ext *ext)
{
    return ext->index < D_800FC270->count;
}

void func_80078C8C(char *self)
{
    int mode = ((unsigned char *)self)[1556];
    Ext *ext;

    if (mode == 0 || mode == 5) {
        ext = (Ext *)(self + 0x10000);
        while (Ext_hasMore(ext)) {
            if (ext->pending == 0) {
                func_80073E64(self);
            } else {
                func_80075A2C(self);
            }
            func_800DA804(ext->index, 1, D_800F1798, 0, 0);
            ext->pending = 0;
            ext->index++;
        }
    } else if (mode == 4) {
        D_800FC270->slots[((Ext *)(self + 0x10000))->index * D_800FC270->stride].id = -1;
    }
}
