#include "sydney_types.h"

/* Per-frame update of a scored event mode: countdown, play, result grading by thresholds, finish. */
typedef struct Snd { u8 pad[0x68]; s32 vol; } Snd;
typedef struct Pad { u8 unk_00, unk_01, unk_02, unk_03; } Pad;
typedef struct Obj {
    u8 pad00[0xF0C];
    s32 timer;
    u8 padF10[4];
    s32 unk_F14;
    u8 padF18[4];
    Pad *pad;
    u8 padF20[0x11C4 - 0xF20];
    s16 grade;
    u8 pad11C6[0x2598 - 0x11C6];
    u8 unk_2598[0x2A54 - 0x2598];
    s32 unk_2A54;
    u8 pad2A58[0x4574 - 0x2A58];
    u16 score;
    u8 pad4576[2];
    u8 unk_4578[0x4650 - 0x4578];
    u32 state;
    s32 unk_4654;
    s32 unk_4658;
    u8 pad465C[4];
    s32 unk_4660;
    u8 pad4664[0x46B8 - 0x4664];
    u8 unk_46B8;
    u8 unk_46B9;
    u8 unk_46BA;
    u8 pad46BB;
    u16 target;
    u8 pad46BE[2];
    u32 unk_46C0;
    u8 pad46C4[0x46EC - 0x46C4];
    f32 unk_46EC;
    f32 unk_46F0;
} Obj;
extern Snd D_800F1AE0;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern s32 func_8001D4B8(Snd *s, s32 id, s32 a, s32 b);
extern void func_8001D640(Snd *s, s32 h, s32 vol);
extern void func_8007136C(Obj *obj);
extern void func_80082618(Obj *obj);
extern void func_80082A84(Obj *obj, s32 id, u16 val, s32 a, s32 b, s32 c);
extern void func_80082BEC(Obj *obj, s32 a, s32 b);
extern void func_8008350C(Obj *obj);
extern void func_80083624(Obj *obj, s32 id, u16 val, s32 a, s32 b, s32 c);
extern void func_80083AD8(Obj *obj);
extern void func_800AACB0(void *list, Obj *obj, s32 a);
extern void func_800AB2A4(void *list, s32 time, s32 kind, Obj *o, s32 b, s32 c);
extern void func_800ADC1C(void *p);
extern void func_800C9EF8(void *p, s32 a);
static __inline__ void Snd_Play(Snd *snd, s32 id, s32 vol) {
    func_8001D640(snd, func_8001D4B8(snd, id, 0, 1), (snd->vol * vol) >> 15);
}
void func_800C5EBC(Obj *obj) {
    f32 lo;
    f32 got;
    f32 span;
    u8 level;
    f32 t;
    f32 r;

    if (obj->unk_4660 >= 0) {
        obj->unk_4660 -= 0x100;
        if (obj->unk_4660 < 0) {
            func_800ADC1C(obj->unk_4578);
        }
    }
    switch (obj->state) {
    case 0:
        obj->timer -= 0x100;
        if (obj->unk_F14 != 0 && obj->timer < 0) {
            obj->state = 1;
            obj->timer = 0x5A00;
            func_8008350C(obj);
            func_80082A84(obj, 0xB, 0, 0, 0, 0);
            func_80082A84(obj, 0x1F, 0, 0, 0, 0);
            func_80083AD8(obj);
        }
        break;
    case 1:
        obj->timer -= 0x100;
        if (obj->timer < 0) {
            obj->state = 2;
            obj->timer = obj->unk_4654;
            func_80082A84(obj, 0x23, obj->unk_46BA, 0, 0, 0);
            obj->unk_2A54 = 1;
        } else if (obj->timer < 0xC00) {
            func_80082BEC(obj, 0x1F, 0x20);
        }
        func_8007136C(obj);
        break;
    case 2:
        if (obj->unk_4658 < 0) {
            obj->unk_46EC = 0.0f;
            obj->unk_46F0 = 0.0f;
        } else {
            obj->unk_4658 -= 0x100;
            if (obj->unk_4658 < 0) {
                Snd_Play(&D_800F1AE0, 0xA8, 0x7FFF);
            }
            obj->unk_46F0 *= 0.3f;
            obj->unk_46EC *= 0.3f;
        }
        func_8007136C(obj);
        if (obj->unk_46B8 != 0) {
            func_800C9EF8(obj->unk_2598, (u8)(obj->score / obj->unk_46C0));
            func_80083624(obj, 0x25, obj->score, 0, 0, 0);
            obj->unk_46B8 = 0;
        }
        obj->timer -= 0x100;
        if (obj->timer < 0) {
            obj->state = 3;
        }
        break;
    case 3:
        level = obj->score / obj->unk_46C0;
        t = obj->target;
        r = obj->unk_46B9 * 100;
        func_800C9EF8(obj->unk_2598, level);
        lo = t * 100.0f / r;
        got = obj->score * 100.0f / r;
        span = 100.0f - lo;
        func_8008350C(obj);
        func_80082A84(obj, 0x14, 0, 0, 0, 0);
        func_80082A84(obj, 0xB, 0, 0, 0, 0);
        func_80082A84(obj, 0x27, obj->score, 0, 0, 0);
        func_80082A84(obj, 0x26, obj->target, 0, 0, 0);
        if (obj->score >= obj->target) {
            if (lo + span * 0.6f < got) {
                obj->grade = 100;
            } else if (lo + span * 0.3f < got) {
                obj->grade = 90;
            } else if (lo <= got) {
                obj->grade = 80;
            }
        } else {
            obj->grade = 0;
        }
        func_80082618(obj);
        obj->pad->unk_01 = 0;
        obj->pad->unk_00 = 0;
        func_800AACB0(D_800F26E0, obj, 2);
        obj->state = 4;
        obj->unk_F14 = 1;
        obj->timer = 0x5A00;
        break;
    case 4:
        obj->timer -= 0x100;
        if (obj->unk_F14 != 0 && obj->timer < 0) {
            func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 7);
        }
        break;
    }
}
