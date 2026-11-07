typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef struct {
    u8 pad0[4];
    u32 flags;
    s32 idx;
    u8 pad2[4];
    s16 h16;
    u16 h18;
} Info;
typedef struct { u8 pad[4]; u16 h4; } Ent;
typedef struct {
    u8 pad0[214];
    s16 h214;
    u8 pad1[220 - 216];
    Info *info;
} Obj;
extern u32 D_800FCCE8;
extern Ent *D_800FCB44[];
void func_800B0E3C(Obj *o);
void func_800B34F4(Obj *o);
s32 func_800D98FC(s32 a);
void func_800C3358(Obj *o);
s32 *func_800C2FE0(Obj *o, s32 *buf);
s32 *func_800C3C0C(Obj *o, s32 *buf);
s32 *func_800C3BFC(Obj *o, s32 *buf);
s32 *func_800C3B68(Obj *o, s32 *buf);
s32 *func_800C3AB0(Obj *o, s32 *buf);
s32 *func_800B1B4C(Obj *o, s32 *buf);
s32 *func_800B1B44(Obj *o, s32 *buf);
void func_800B31EC(s32 a);
void func_800B0CEC(Obj *o, u32 f);
s32 func_800B1D60(Obj *o, s32 idx, s32 v, s32 *p);
void func_800B18B4(Obj *o, s32 f, s32 r);
void func_800B0F60(Obj *o)
{
    s32 buf[10];
    u32 kind;
    s32 *p;
    s32 idx;
    s32 v;
    s16 r;
    Info *info;
    u32 fl = o->info->flags;
    if (fl & 0x10000) {
        if ((fl & 0xFFFF) == 17) {
            func_800B0E3C(o);
        }
        return;
    }
    func_800B34F4(o);
    info = o->info;
    if (info == 0) {
        return;
    }
    kind = (u16)info->flags;
    idx = info->idx;
    v = func_800D98FC(info->h18);
    switch (kind) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 14:
        p = 0;
        break;
    case 27:
        p = 0;
        func_800C3358(o);
        break;
    case 10:
    case 11:
    case 12:
    case 30:
        p = func_800C2FE0(o, buf);
        break;
    case 26:
        buf[0] = D_800FCCE8 / 30 + 1;
        p = buf;
        break;
    case 13:
        p = func_800C3C0C(o, buf);
        break;
    case 21:
        p = func_800C3BFC(o, buf);
        break;
    case 15:
    case 16:
        p = func_800C3B68(o, buf);
        break;
    case 17:
        p = func_800C3AB0(o, buf);
        break;
    case 18:
    case 19:
    case 29:
        p = func_800B1B4C(o, buf);
        break;
    case 20:
        p = func_800B1B44(o, buf);
        break;
    default:
        return;
    }
    switch (o->info->h16) {
    case 0:
        func_800B31EC(3);
        break;
    case 1:
        func_800B31EC(0);
        break;
    case 2:
        func_800B31EC(1);
        break;
    }
    if (kind - 15 < 2) {
        o->h214 = 17;
    }
    if (o->info->flags & 0x10000000) {
        o->h214 = 17;
    }
    func_800B0CEC(o, o->info->flags & 0x80000);
    r = func_800B1D60(o, idx, v, p);
    func_800B18B4(o, r > D_800FCB44[idx]->h4, r);
    o->h214 = -1;
}
