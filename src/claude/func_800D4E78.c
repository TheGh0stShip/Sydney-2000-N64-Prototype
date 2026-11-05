typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct Entry {
    s32 unk0;
    char pad4[0xB0 - 0x4];
    u8 unkB0;
    char padB1[3];
    void *unkB4;
    char padB8[0xD4 - 0xB8];
    s16 unkD4;
    s16 unkD6;
    s16 unkD8;
    char padDA[2];
} Entry;
typedef char assert_entry_size[(sizeof(Entry) == 0xDC) ? 1 : -1];

typedef struct Mgr {
    char pad0[0xB4];
    void *unkB4;
    char padB8[0xD8 - 0xB8];
    s32 unkD8;
    char unkDC[0x280 - 0xDC];
    s32 unk280;
    s32 unk284;
    s32 unk288;
    s32 unk28C;
    s32 unk290;
    char unk294[0x914 - 0x294];
    char unk914[0x9E8 - 0x914];
    char unk9E8[0xACC - 0x9E8];
    s32 unkACC;
    s32 unkAD0;
    s32 unkAD4;
    s32 unkAD8;
} Mgr;

extern Mgr D_800F4D00;
extern Entry D_801028B0[10];
extern char D_8008A168[];
extern char D_8008A038[];
extern char D_80086598[];

extern void func_800AC3D4(Mgr *);
extern void func_800AE568(void *);
extern void func_800D28B0(void *);
extern void func_800ADED4(void *);
extern void func_800ADE10(Entry *);

void func_800D4E78(void)
{
    Mgr *m = &D_800F4D00;
    Entry *e;
    s32 i;

    func_800AC3D4(m);
    m->unkB4 = D_8008A168;
    m->unkD8 = 1;
    func_800AE568(m->unkDC);
    m->unk280 = 0;
    m->unkB4 = D_8008A038;
    m->unk288 = 0;
    func_800D28B0(m->unk294);
    func_800ADED4(m->unk914);
    func_800ADED4(m->unk9E8);
    m->unkAD0 = m->unkAD4 = m->unkAD8 = -1;
    m->unkACC = 0;
    m->unk284 = 0;
    m->unk28C = 0;
    m->unk290 = 0;
    e = D_801028B0;
    for (i = 9; i != -1; e++, i--) {
        func_800ADE10(e);
        e->unkB4 = D_80086598;
        e->unk0 = 0x3E;
        e->unkB0 = 1;
        e->unkD6 = -1;
        e->unkD8 = -1;
        e->unkD4 = 4;
    }
}
