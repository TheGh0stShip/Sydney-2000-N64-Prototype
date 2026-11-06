/* Event-bank crowd/sfx message handler (link VRAM 0x80071D28), ROM 0xA9A38..0xA9EE4. */
typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x68];
    s32 volume;
} SndBank;

extern void *D_80070FB8[];
extern SndBank D_800F1AE0;
extern char D_800445F0[];
typedef struct { s32 pad[7]; s32 time; } AnimDef;
extern AnimDef D_80077C28;
extern AnimDef D_80077C50;

extern void func_800A9BE8(void *, s32);
extern void func_8001D5D8(SndBank *, s32, s32, s32, s32, s32);
extern void func_800084C0(void *, s32, f32);
extern void func_80008464(void *, s32);
extern void func_8007735C(u8 *);
extern void func_800772A4(u8 *);
extern void func_80077454(u8 *, s32, s32, s32);
extern void func_800D33A0(void *, AnimDef *, s32, s32);
extern void func_800767D4(u8 *);

typedef struct {
    s32 pad00;
    s32 pad04;
    s32 pad08;
    s32 pad0C;
    s32 kind;
} Msg;

#define W(o) (*(s32 *)(obj + (o)))
#define B(o) (*(u8 *)(obj + (o)))
#define P(o) (*(u8 **)(obj + (o)))
#define SUB B(0x811E)

void func_800A9A38(u8 *obj, Msg *msg)
{
    if (B(0x811D) == 21) {
        return;
    }
    {
        static void *const unused_tbl[] = { &&C4, &&C5, &&C12, &&C13, &&C14, &&C15, &&C16, &&C17 };
        unsigned int i = msg->kind - 4;
        if (i >= 14) return;
        goto *D_80070FB8[i];
    }
C4:
    switch (SUB) {
    case 0:
    case 1:
    case 3:
    case 4:
        func_800A9BE8(obj + 0x7F6C, 3);
        break;
    }
    switch (SUB) {
    case 0:
    case 1:
    case 5:
        {
            s32 l = W(0x8154);
            s32 m = 6553;
            func_8001D5D8(&D_800F1AE0, l, (D_800F1AE0.volume * m) >> 15, 120, 0, 0);
        }
        break;
    }
    return;
C5:
    B(0x811D) = 5;
    return;
C12:
    if (P(0x2DB8)[0x1AA] == 1 && SUB != 5) {
        func_800084C0(D_800445F0, P(0x2DB8)[0x2DC], 0.8f);
    }
    func_8007735C(obj);
    return;
C13:
    switch (SUB) {
    case 0:
    case 1:
    case 5:
        {
            s32 l = W(0x8154);
            s32 m = 9830;
            func_8001D5D8(&D_800F1AE0, l, (D_800F1AE0.volume * m) >> 15, 60, 0, 0);
        }
        break;
    }
    goto tail;
C14:
    if (P(0x2DB8)[0x1AA] == 1 && SUB != 5) {
        func_800084C0(D_800445F0, P(0x2DB8)[0x2DC], 0.9f);
    }
    return;
C15:
    switch (SUB) {
    case 5:
        func_800A9BE8(obj + 0x7F6C, 8);
        break;
    case 2:
        func_800A9BE8(obj + 0x7F6C, 13);
        break;
    }
    switch (SUB) {
    case 0:
    case 1:
    case 5:
        {
            s32 l = W(0x8154);
            s32 m = 13106;
            func_8001D5D8(&D_800F1AE0, l, (D_800F1AE0.volume * m) >> 15, 60, 0, 0);
        }
        break;
    }
    if (P(0x2DB8)[0x1AA] == 1 && SUB != 5) {
        func_80008464(D_800445F0, P(0x2DB8)[0x2DC]);
    }
    func_800772A4(obj);
    return;
C16:
    if (SUB == 2) {
        W(0x812C) = 0x16800;
        W(0x8134) = 1;
        W(0x1C2C) = 1;
        func_80077454(obj, 32, 0, 0);
        D_80077C28.time = W(0x812C) - 0x1E00;
        func_800D33A0(obj + 0x2B8, &D_80077C28, 1, -1);
        func_800A9BE8(obj + 0x7F6C, 14);
    }
    if (P(0x2DB8)[0x1AA] == 1 && SUB != 5) {
        func_800084C0(D_800445F0, P(0x2DB8)[0x2DC], 1.0f);
    }
    return;
C17:
    switch (SUB) {
    case 2:
        W(0x812C) = 0x10E00;
        W(0x8134) = 1;
        W(0x1C2C) = 1;
        D_80077C50.time = W(0x812C) - 0x1E00;
        func_800D33A0(obj + 0x2B8, &D_80077C50, 1, -1);
        func_80077454(obj, 29, 0, 0);
        func_800A9BE8(obj + 0x7F6C, 15);
        break;
    case 5:
        func_800A9BE8(obj + 0x7F6C, 9);
        break;
    }
    switch (SUB) {
    case 0:
    case 1:
    case 5:
        {
            s32 l = W(0x8154);
            s32 m = 24575;
            func_8001D5D8(&D_800F1AE0, l, (D_800F1AE0.volume * m) >> 15, 90, 0, 0);
        }
        break;
    }
    func_800767D4(obj);
tail:
    if (P(0x2DB8)[0x1AA] == 1 && SUB != 5) {
        func_80008464(D_800445F0, P(0x2DB8)[0x2DC]);
    }
}
