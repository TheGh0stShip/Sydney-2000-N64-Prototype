#include "sydney_types.h"

/* Handles one queued event for a competitor (start, input, signal, sound), then advances its clock. */
typedef struct { u8 unk_00; s8 unk_01; u8 unk_02; u8 unk_03; } Entry;
typedef struct { u8 b[4]; } Lut;
typedef struct { u8 pad[3]; u8 flags; } Pad;
typedef struct { u8 pad[0xD1B]; u8 unk_D1B; u8 pad2[3]; u8 unk_D1F; } Game;
typedef struct { s32 type; s32 time; u8 pad[8]; u32 arg; } Event;
typedef struct {
    u8 pad000[0x10];
    s32 time;
    u8 pad014[0xF10 - 0x14];
    s32 unk_F10;
    s32 unk_F14;
    u8 padF18[4];
    Pad *pad;
    u8 padF20[0x42E4 - 0xF20];
    Entry *table;
    Entry *cur;
    u8 unk_42EC;
    u8 unk_42ED;
    u8 unk_42EE;
    u8 unk_42EF;
    u8 pad42F0[0x44B0 - 0x42F0];
    s32 unk_44B0;
    u8 unk_44B4;
    u8 unk_44B5;
    u8 unk_44B6;
    u8 pad44B7;
    u8 unk_44B8;
} Obj;
extern Game *D_800FC270;
extern Lut D_800707D0;
extern u8 D_800F2AD8[];
extern u8 D_800F2758[];
void func_80015EAC(s32 a);
void func_800177AC(void);
void func_80070C08(Obj *o);
void func_800713B4(Obj *o, s32 dt);
void func_800718E0(Obj *o);
void func_800828B4(Obj *o, s32 a);
void func_80083700(Obj *o, s32 a);
void func_8008393C(Obj *o, s32 kind, Entry **out);
void func_80083A0C(Obj *o);
void func_800AA658(void *a, Entry **b);
void func_800BBD78(void *snd, s32 id, s32 a, void *b, s32 c);
void func_800BC07C(Pad *p, u8 v);
void func_800B6D50(Obj *o, Event *ev) {
    s32 dt = (ev->time - o->time) >> 8;
    switch (ev->type) {
    case 3: {
        Lut lut;
        u8 idx;
        Game *g;
        u8 sel, add;
        func_80015EAC(12);
        g = D_800FC270;
        sel = g->unk_D1B;
        add = g->unk_D1F;
        lut = D_800707D0;
        idx = lut.b[sel] + add;
        o->table = NULL;
        func_8008393C(o, 2, &o->table);
        o->cur = &o->table[idx];
        o->unk_42EC = o->unk_42ED = o->cur->unk_00;
        o->unk_42EE = o->cur->unk_02 + 10;
        o->unk_42EF = o->cur->unk_03;
        o->unk_F10 = o->cur->unk_01 * 7680.0f;
        func_80070C08(o);
        func_800177AC();
        break;
    }
    case 7:
        switch (ev->arg) {
        case 8:
        case 15:
            func_800BBD78(D_800F2AD8, 12, 1, o, 0);
            break;
        case 7:
        case 0x39:
            func_800AA658(D_800F2758, &o->table);
            func_800828B4(o, ev->arg);
            break;
        }
        break;
    case 1:
        func_80083700(o, ev->arg);
        break;
    case 2: {
        u8 *data = (u8 *)&ev->arg;
        if (o->unk_44B0 == 2) {
            u8 flags;
            func_800BC07C(o->pad, data[1]);
            flags = o->pad->flags;
            if (o->unk_44B8 == 0 && (flags & 0x10) && o->unk_44B5 == 0 && o->unk_44B4 != 0) {
                o->unk_44B5 = 1;
                if (o->unk_44B6 == 0) {
                    func_800718E0(o);
                }
            }
        } else {
            func_800BC07C(o->pad, data[1]);
            if (o->pad->flags != 0) {
                o->unk_F14 = 1;
            }
        }
        func_800713B4(o, dt);
        break;
    }
    case 5:
        func_80083A0C(o);
        func_800713B4(o, dt);
        break;
    case 12:
        break;
    }
    o->time = ev->time;
}
