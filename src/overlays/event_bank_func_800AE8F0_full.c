typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s8 team;
    u8 sub;
    u8 pad2[6];
    s8 active;
    u8 pad9[3];
} Slot;

typedef struct {
    u8 pad[0x20];
    u8 mode;
    u8 rest[27];
} Team;

typedef struct {
    u8 pad[3];
    u8 state;
    u8 rest[28];
} Entry;

typedef struct {
    u8 pad[8];
    s8 kind;
} Info;

typedef struct {
    Team teams[8];
} Game;

extern u8 *D_800FC270;
extern u8 D_800F3BC0[];
extern void func_800C0110(void *a, s32 b, s32 c, s32 d);
extern void func_8009B73C(Info **out);

#define GAME_TYPE (*(s32 *)(D_800FC270 + 2560))
#define SOUND_ON (*(s32 *)(D_800FC270 + 2564))
#define NSLOTS (D_800FC270[2572])

void func_80076BE0(u8 *p)
{
    u8 mode;
    s32 cue;
    Slot *slots;
    Slot *cur;
    u32 i;
    u32 waiting;
    u8 team_mode;
    s32 type;
    Info *info;
    s32 base;
    s32 off;
    s8 kind;
    s32 id;

    mode = p[0x811E];
    if (mode != 0 && mode != 5 && mode != 1) {
        return;
    }
    cue = -1;
    cur = (Slot *)(D_800FC270 + 2576);
    slots = cur;
    type = GAME_TYPE;
    if (type == 0) {
        cue = 174;
    } else if (type == 1) {
        cue = 176;
    } else if (type == 2) {
        cue = 178;
    }
    for (i = 0; i < NSLOTS; i++) {
        if (slots[i].active == 0) {
            cur = &slots[i];
            break;
        }
    }
    if (cur->team != 8) {
        team_mode = ((Game *)D_800FC270)->teams[cur->team].mode;
    } else {
        team_mode = 3;
    }
    waiting = 0;
    for (i = 0; i < NSLOTS; i++) {
        if ((*(Entry **)(p + 0x813C))[i].state < 3) {
            waiting++;
        }
    }
    switch (GAME_TYPE) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 5:
        if (waiting != 0) {
            if (SOUND_ON) {
                func_800C0110(D_800F3BC0, 105, 0, 0);
            }
            return;
        }
        if (team_mode != 3) {
            base = 8;
            off = cur->team;
        } else {
            base = 108;
            off = cur->sub;
            cue = -1;
        }
        id = base + off;
        if (SOUND_ON) {
            func_800C0110(D_800F3BC0, id, 0, 0);
        }
        if (cue >= 0 && SOUND_ON) {
            func_800C0110(D_800F3BC0, cue, 0, 0);
        }
        break;
    case 4:
        if (waiting != 0) {
            if (SOUND_ON) {
                func_800C0110(D_800F3BC0, 297, 0, 0);
            }
            return;
        }
        if (SOUND_ON != 5) {
            return;
        }
        func_8009B73C(&info);
        kind = info->kind;
        if (kind == 0) {
            if (SOUND_ON) {
                func_800C0110(D_800F3BC0, 188, 0, 0);
            }
        } else if (kind == 1) {
            if (SOUND_ON) {
                func_800C0110(D_800F3BC0, 186, 0, 0);
            }
        } else if (kind == 2) {
            if (SOUND_ON) {
                func_800C0110(D_800F3BC0, 187, 0, 0);
            }
        } else if (kind == 3) {
            if (SOUND_ON) {
                func_800C0110(D_800F3BC0, 185, 0, 0);
            }
        } else {
            if (SOUND_ON) {
                func_800C0110(D_800F3BC0, 180, 0, 0);
            }
        }
        break;
    }
}
