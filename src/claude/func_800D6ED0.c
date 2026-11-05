typedef unsigned short u16;
typedef int s32;

typedef struct Src {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u16 unk24;
    u16 unk26;
} Src;

typedef struct Obj {
    char pad0[0xDC];
    s32 unkDC;
    s32 unkE0;
    s32 unkE4;
    s32 unkE8;
} Obj;

extern s32 func_800B31F8(void);
extern s32 func_800B31DC(void);
extern void func_800B3208(u16);
extern void func_800B31EC(s32);
extern void func_800B360C(Obj *, Src *);
extern void func_800B2158(Obj *, s32);

void func_800D6ED0(Obj *obj, Src *src)
{
    s32 a = func_800B31F8();
    s32 b = func_800B31DC();

    func_800B3208(src->unk26);
    func_800B31EC(src->unk24);
    func_800B360C(obj, src);
    obj->unkE0 = src->unk1C;
    obj->unkDC = src->unk18;
    obj->unkE8 = src->unk20;
    obj->unkE4 = src->unk20;
    if (obj->unkDC > 0) {
        func_800B2158(obj, 0);
    }
    func_800B3208(a);
    func_800B31EC(b);
}
