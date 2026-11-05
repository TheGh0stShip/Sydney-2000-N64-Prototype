typedef unsigned char u8;
typedef signed int s32;
typedef struct Obj {
    s32 unk0; u8 pad4[0xAC]; u8 unkB0; u8 unkB1; u8 padB2[2]; void *vtbl;
    s32 unkB8; s32 unkBC; s32 unkC0; s32 unkC4;
    u8 unkC8; u8 unkC9; u8 unkCA; u8 unkCB; s32 unkCC; s32 unkD0;
} Obj;
typedef char assert_size[(sizeof(Obj) == 0xD4) ? 1 : -1];
extern char D_80085F48[];
extern char D_80085EF8[];
extern void func_800AC3D4(Obj *obj);
Obj *func_800ADE10(Obj *obj)
{
    register Obj *p __asm__("$2");

    func_800AC3D4(obj);
    p = obj;
    p->vtbl = D_80085F48;
    p->unkCB = 0xFF;
    p->unk0 = 0x3C;
    p->unkB8 = 0;
    p->unkBC = 0;
    p->unkC0 = 0;
    p->unkC4 = 0;
    p->unkC8 = 0;
    p->unkC9 = 0;
    p->unkCC = 0;
    p->unkD0 = 0;
    p->vtbl = D_80085EF8;
    p->unkB1 = 0;
    return p;
}
