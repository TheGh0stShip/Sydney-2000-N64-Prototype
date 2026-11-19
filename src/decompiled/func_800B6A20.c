#include "sydney_types.h"

/* Event handler of a timed prompt object: start/attach/detach/tick events drive a small state machine. */
typedef struct VtEntry { s16 delta; s16 pad; void (*fn)(); } VtEntry;
typedef struct Actor { u8 pad00[0xB4]; VtEntry *vtbl; } Actor;
typedef struct Event {
    s32 type;
    s32 time;
    u8 pad08[4];
    Actor *actor;
    s32 arg;
    s32 id;
} Event;
typedef struct Game { u8 pad[0x9F8]; s32 unk_9F8; s32 unk_9FC; } Game;
typedef struct Prompt {
    u8 pad00[0x280];
    s32 unk_280;
    s32 timer;
    u8 state;
    u8 pad289[3];
    s32 unk_28C;
    s32 unk_290;
} Prompt;
extern Game *D_800FC270;
extern u8 D_800F26E0[], D_800F11A0[], D_800F2AD8[];
extern void func_800AB2A4(void *list, s32 time, s32 kind, Actor *a, s32 b, s32 c);
extern void func_80096398(void *list, Actor *a);
extern void func_800BC180(void *hud);
extern void func_800E8714(s32 a);
extern void func_800B7084(Prompt *p);
extern void func_800B705C(Prompt *p);
extern void func_800B6EA4(Prompt *p, s32 a);
extern void func_800B6C58(Prompt *p, s32 a, s32 b);
void func_800B6A20(Prompt *p, Event *e) {
    Actor *a;
    s32 arg;
    s32 id;

    switch (e->type) {
    case 7:
        id = e->arg;
        if (id == 0xF || id == 0x39) {
            if (p->state == 3 || id == 0x39) {
                func_800B7084(p);
                p->unk_290 = 1;
                p->unk_28C = 0;
            } else {
                p->unk_28C = 1;
            }
        }
        break;
    case 1:
        func_800B705C(p);
        p->state = 3;
        break;
    case 19:
        a = e->actor;
        ((void (*)(void *, Prompt *))a->vtbl[2].fn)((char *)a + a->vtbl[2].delta, p);
        func_800AB2A4(D_800F26E0, e->time, 3, a, 0, 0);
        break;
    case 20:
        a = e->actor;
        D_800FC270->unk_9FC = 0;
        ((void (*)(void *))a->vtbl[3].fn)((char *)a + a->vtbl[3].delta);
        func_80096398(D_800F11A0, a);
        arg = e->arg;
        func_800BC180(D_800F2AD8);
        p->unk_28C = 1;
        if (arg == 0 || arg == 0x39) {
            func_800B7084(p);
            p->unk_290 = 1;
        } else {
            func_800E8714(p->unk_280);
            func_800B6EA4(p, D_800FC270->unk_9F8);
            p->state = 1;
            p->timer = 0x12C00;
            p->unk_290 = 1;
        }
        p->unk_28C = 0;
        break;
    case 5:
        switch (p->state) {
        case 0:
            if (p->unk_28C == 1) {
                func_800B6C58(p, 5, p->unk_280);
                p->unk_28C = 0;
            }
            break;
        case 1:
            p->timer -= 0x100;
            if (p->timer <= 0) {
                p->state = 2;
            }
            break;
        case 2:
            func_800B705C(p);
            p->state = 0;
            break;
        }
        break;
    }
}
