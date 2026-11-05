typedef struct VtblEntry {
    short delta;
    short index;
    void (*func)(void *self, int flags);
} VtblEntry;

typedef struct VObject {
    char pad[180];
    VtblEntry *vtbl;
} VObject;

typedef struct PlayerSlot {
    int active;
    char pad[56];
} PlayerSlot;

typedef struct LaneEntry {
    int unk0;
    float value;
    int unk8;
} LaneEntry;

extern char *D_800FC270;
extern char D_800F2AD8[];
extern char D_800F26E0[];
extern char D_800F2758[];
extern void func_800CEE04(void *obj);
extern void func_80097504(void *obj);
extern void func_800AC334(void *obj);
extern void func_800ADC1C(void *obj);
extern void func_800A2198(void *obj);
extern void func_800BBD78(void *queue, int id, int a2, int a3, int a4);
extern void func_800AACB0(void *list, void *obj, int arg);
extern void func_800AA658(void *list, void *slot);

void func_8009B898(char *obj)
{
    char *hi;
    char *ent;
    float best;
    int mode;

    best = 0.0f;
    hi = obj + 0x8000;
    *(int *)(hi + 124) = 1;
    func_800CEE04(obj + 14548);
    func_80097504(obj + 15860);
    func_800AC334(obj + 31992);
    func_800ADC1C(obj + 31992);
    func_800AC334(obj + 12140);
    func_800A2198(obj + 12140);

    ent = *(char **)(obj + 12136);
    if (ent != 0) {
        unsigned char slot = ent[424];
        int kind;
        if (slot != 8) {
            PlayerSlot *slots = (PlayerSlot *)(D_800FC270 + 72);
            slots[slot].active = 0;
        }
        kind = ent[426];
        if (kind < 4) {
            if (kind != 0) {
                LaneEntry *lanes = (LaneEntry *)(D_800FC270 + 2576);
                best = lanes[((signed char *)hi)[81]].value;
            }
        }
        if (*(int *)(D_800FC270 + 2560) == 5 && *(float *)(D_800FC270 + 3556) < best) {
            *(float *)(D_800FC270 + 3556) = best;
        }
        mode = *(int *)(D_800FC270 + 2560);
        if (mode == 4 || mode == 0 || mode == 1 || mode == 2) {
            if (obj[0x8054] != 4 && *(float *)(D_800FC270 + 1276) < best) {
                *(float *)(D_800FC270 + 1276) = best;
            }
        }
        if (*(int *)(D_800FC270 + 2560) == 4 && *(float *)(D_800FC270 + 1320) < best) {
            *(float *)(D_800FC270 + 1320) = best;
        }
        func_800BBD78(D_800F2AD8, ((signed char *)ent)[427], 0, 0, 5);
        func_800BBD78(D_800F2AD8, ((signed char *)ent)[427], 1, 0, 2);
        func_800AACB0(D_800F26E0, ent, 0);
        ((void (*)(void *))((VObject *)ent)->vtbl[3].func)(ent + ((VObject *)ent)->vtbl[3].delta);
        ((VObject *)ent)->vtbl[1].func(ent + ((VObject *)ent)->vtbl[1].delta, 2);
        func_800AA658(D_800F2758, obj + 12136);
    }
}
