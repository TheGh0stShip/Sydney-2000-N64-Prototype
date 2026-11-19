#include "sydney_types.h"

/* Message handler for an event object: start, sub-commands, and per-frame input handling. */
typedef struct { u32 type; s32 time; u8 unk_08[8]; union { u32 arg; u8 b[4]; } u; } Msg;
typedef struct { u8 b0, b1, b2, b3; } Pad;
typedef struct { u8 unk_000[0xD1B]; u8 unk_D1B; u8 unk_D1C[3]; u8 unk_D1F; } Ctx;
typedef struct Ev {
    u8 unk_0000[0x10]; s32 time; u8 unk_0014[0xF10 - 0x14]; s32 unk_F10; s32 unk_F14; u8 unk_F18[4]; Pad *pad;
    u8 unk_F20[0x42E4 - 0xF20]; u8 *table; u8 *entry; u8 unk_42EC, unk_42ED, unk_42EE;
    u8 unk_42EF[0x44AC - 0x42EF]; s32 mode; u8 unk_44B0, unk_44B1; u8 unk_44B2[2]; u8 unk_44B4;
} Ev;
typedef struct { u8 v[4]; } Bytes4;
extern Ctx *D_800FC270;
extern Bytes4 D_800707D0;
extern u8 D_800F2AD8[], D_800F2758[];
void func_80015EAC(s32 a);
void func_8008393C(Ev *e, s32 a, u8 **out, s32 b);
void func_80070BD0(Ev *e);
void func_800177AC(void);
void func_800BBD78(void *a, s32 b, s32 c, Ev *e, s32 d);
void func_800AA658(void *a, u8 **b);
void func_800828B4(Ev *e, s32 a);
void func_80083700(Ev *e, s32 a);
void func_800BC07C(Pad *p, u8 a);
void func_80071820(Ev *e);
void func_80083A0C(Ev *e);
void func_80071228(Ev *e, s32 dt);
void func_800CD070(Ev *e, Msg *m) {
    s32 dt = (m->time - e->time) >> 8;
    switch (m->type) {
    case 3: {
        Bytes4 offs;
        u8 idx;
        u8 *p;
        func_80015EAC(12);
        {
            Ctx *c = D_800FC270;
            u8 sel = c->unk_D1B;
            s32 base = c->unk_D1F;
            offs = D_800707D0;
            idx = offs.v[sel] + base;
            e->table = NULL;
            func_8008393C(e, 1, &e->table, base);
        }
        p = e->table + idx * 4;
        e->entry = p;
        e->unk_42EC = e->unk_42ED = p[0];
        e->unk_42EE = e->entry[2] + 10;
        e->unk_F10 = (s8)e->entry[1] * 7680.0f;
        func_80070BD0(e);
        func_800177AC();
        break;
    }
    case 7:
        switch (m->u.arg) {
        case 8:
        case 0xF:
            func_800BBD78(D_800F2AD8, 12, 1, e, 0);
            break;
        case 7:
        case 0x39:
            func_800AA658(D_800F2758, &e->table);
            func_800828B4(e, m->u.arg);
            break;
        }
        break;
    case 1:
        func_80083700(e, m->u.arg);
        break;
    case 12:
        break;
    case 2: {
        u8 *in = m->u.b;
        if (e->mode == 2) {
            func_800BC07C(e->pad, in[1]);
            if (e->pad->b3 & 0x10)
                e->unk_44B1 = 1;
            if (e->pad->b2 & 0x10) {
                e->unk_44B1 = 0;
                if (e->unk_44B0 == 0 && e->unk_44B4 == 0)
                    func_80071820(e);
            }
        } else {
            func_800BC07C(e->pad, in[1]);
            if (e->pad->b3)
                e->unk_F14 = 1;
        }
        func_80071228(e, dt);
        break;
    }
    case 5: {
        func_80083A0C(e);
        func_80071228(e, dt);
        break;
    }
    }
    e->time = m->time;
}
