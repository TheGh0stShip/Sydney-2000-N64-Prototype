typedef struct GameEntry {
    int unk0;
    int unk4;
    int value;
} GameEntry;

typedef struct GameState {
    char pad0[2560];
    int mode;
    int submode;
    char pad1[4];
    GameEntry entries[64];
} GameState;

extern GameState *D_800FC270;
extern void func_800971EC(void *object, void *actor, float scale, void *pos,
                          int first, int second);
extern void func_80096860(void *object, int slot, int value, int extra);
extern void func_80096C8C(void *object, int slot, int value, void *entry,
                          int index, int extra);
extern void func_80096F54(void *object, int slot, int value);
extern void func_800CEE04(void *object);

void func_800A5D64(unsigned char *object)
{
    unsigned char *part;
    int kind;
    int active;
    int index;

    active = 0;
    kind = (*(unsigned char **)(object + 12212))[426];
    if (kind == 1) {
        goto set;
    }
    if (kind == 2) {
    set:
        active = 1;
    }
    if (active && object[31919] != 2) {
        part = object + 13804;
        func_800971EC(part, *(void **)(object + 12212), 0.6666f,
                      *(unsigned char **)(object + 12212) + 808, -1, -1);
        func_80096860(part, 4,
                      *(int *)(*(unsigned char **)(object + 12212) + 420),
                      *(int *)(object + 12220));
        index = (signed char)object[31917];
        func_80096C8C(part, 4, D_800FC270->entries[index].value,
                      *(unsigned char **)(object + 31972) + index * 12,
                      (signed char)object[31916], *(int *)(object + 12216));
        if (object[31919] == 4 ||
            (D_800FC270->mode == 4 &&
             D_800FC270->submode == 1)) {
            func_80096F54(part, 4, *(int *)((unsigned char *)D_800FC270 + 3344));
        }
        func_800CEE04(object + 29936);
        *(int *)(object + 31948) = 0;
    }
}
