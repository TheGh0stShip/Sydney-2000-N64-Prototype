typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[104]; s32 vol; } Snd;
typedef struct { u8 pad[6]; u16 h6; } Info;
typedef struct { s32 i0; s32 flags; u8 pad[20]; Info *info; } Desc;
typedef struct { s32 i0; s32 id; u8 pad[212]; Desc *desc; } Obj;
typedef struct { u8 pad[18]; u16 h18; } Ent;
extern Snd D_800F1AE0;
extern char D_800F26E0[];
extern s32 D_800F2744[];
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern Ent *func_800DCCF4(s32);
extern void func_800AB2A4(void *, s32, s32, s32, s32, s32);
extern void func_800B1550(Obj *, s32);
static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}
void func_800B1430(Obj *o, u8 *msg)
{
    if (msg[3] & 0x10) {
        if (o->desc->flags & 0x80000) {
            func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 89, 0, 1), scl(D_800F1AE0.vol, 32767));
        } else {
            s32 id;
            Info *info;
            func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 130, 0, 1), scl(D_800F1AE0.vol, 32767));
            id = o->id;
            info = o->desc->info;
            func_800DCCF4(id)->h18 = info->h6;
            func_800AB2A4(D_800F26E0, D_800F2744[0], 7, id, 0, 0);
        }
    } else {
        func_800B1550(o, msg[0]);
    }
}
