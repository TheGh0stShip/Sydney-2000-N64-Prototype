typedef struct VEntry {
    short offset;
    short pad;
    void (*fn)(void *);
} VEntry;

typedef struct VTable {
    char pad[72];
    VEntry entry;
} VTable;

typedef struct Part {
    char pad[180];
    VTable *vtbl;
    char pad2[28];
} Part;

typedef struct Unit {
    char pad0[180];
    VTable *vtbl;
    char pad1[28];
    char slots[4][236];
    char sub[212];
    Part parts[4];
    char pad3[24];
    unsigned char result;
} Unit;

extern void func_800ADC1C(void *);
extern void func_800D6EA0(void *);

int func_800D3E34(Unit *unit)
{
    unsigned char i;

    unit->vtbl->entry.fn((char *)unit + unit->vtbl->entry.offset);
    func_800ADC1C(unit->sub);
    i = 0;
    do {
        VTable *vt = ((Part *)((char *)unit->parts + i * sizeof(Part)))->vtbl;
        Part *part = &unit->parts[i];
        i++;
        vt->entry.fn((char *)part + vt->entry.offset);
    } while (i < 4);
    func_800D6EA0(unit->slots[0]);
    func_800D6EA0(unit->slots[1]);
    func_800D6EA0(unit->slots[2]);
    func_800D6EA0(unit->slots[3]);
    return unit->result;
}
