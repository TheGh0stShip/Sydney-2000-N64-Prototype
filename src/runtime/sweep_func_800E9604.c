typedef struct VEntry {
    short offset;
    short pad;
    void (*fn)(void *, void *);
} VEntry;

typedef struct VTable {
    char pad[16];
    VEntry init;
} VTable;

typedef struct Sub {
    char pad0[4];
    int ready;
    char pad1[168];
    unsigned char active;
    char pad2[3];
    VTable *vtbl;
} Sub;

typedef struct Desc {
    char pad[216];
    int bit;
} Desc;

extern Desc D_800F5900;
extern void func_800ADC54(Sub *, int);
extern void func_8001A1D8(void *, float, float, float, float);
extern void func_800ADC38(Sub *);

void func_800E9604(char *obj, short x, short y, short w, short top, short bottom)
{
    Sub *sub = (Sub *)(obj + 27656);
    float hw;
    float height;

    if (sub->ready == 0) {
        sub->vtbl->init.fn((char *)sub + sub->vtbl->init.offset, &D_800F5900);
        func_800ADC54(sub, 1 << D_800F5900.bit);
        sub->active = 1;
    }
    hw = w * 0.5f;
    height = (float)top - (float)bottom;
    func_8001A1D8(obj + 27852, -hw, -(float)bottom, hw, height);
    *(float *)(obj + 27816) = x;
    *(float *)(obj + 27820) = y;
    func_800ADC38(sub);
}
