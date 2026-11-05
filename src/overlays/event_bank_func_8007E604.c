typedef struct VTEntry {
    short pad0[8];
    short offset;
    short pad1;
    void (*fn)(void *self, void *arg);
} VTEntry;

extern unsigned char *D_800FC270;
extern unsigned char D_800F4D00[];
extern int func_800D98FC(int id);
extern void func_800D0C98(void *obj, int a, void *b, int c);
extern void func_800ADC54(void *obj, int mask);
extern void func_800D0B9C(void *obj);
extern void func_800CCAE0(void *obj);
extern void func_800CC99C(void *obj, float value);

void func_8007E604(unsigned char *object)
{
    unsigned char *hi = object + 0x8000;
    unsigned char *info = *(unsigned char **)(object + 21356);
    unsigned char index = info[424];
    unsigned char *base;
    unsigned char *entry;
    unsigned char *sub;
    VTEntry *vt;
    void *data;
    unsigned char *tbl;

    if (hi[3229] != 2) {
    base = D_800FC270;
    entry = base + (hi[3224] * 12 + 2576);
    if ((signed char)index != 8) {
        data = base + (index * 60 + 20);
        func_800D0C98(object + 21396, info[425], data, *(int *)(entry + 4));
    } else {
        int sel = info[425];
        data = (void *)func_800D98FC(13);
        func_800D0C98(object + 21396, sel, data, *(int *)(entry + 4));
    }
    tbl = D_800F4D00;
    sub = object + 21396;
    vt = *(VTEntry **)(sub + 180);
    vt->fn(sub + vt->offset, tbl);
    func_800ADC54(sub, 1 << *(int *)(tbl + 216));
    sub[176] = 1;
    func_800D0B9C(sub);
    func_800CCAE0(object + 31156);
    func_800CC99C(object + 31156, -1.0f);
    }
}
