/* Event-bank announcer cue selector (link VRAM 0x80075248), ROM 0x9A838..0x9ABD0. */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    s8 b0;
    u8 b1;
    u8 pad2[2];
    f32 f4;
    s8 b8;
    u8 pad9[3];
} Entry;

typedef struct {
    u8 pad0[0x20];
    u8 kind;
    u8 pad21[0x1B];
} Team;

typedef struct {
    Team team[1];
    u8 pad3C[0xA00 - 0x3C];
    s32 mode;
    s32 sound;
    u8 padA08[4];
    u8 count;
    u8 padA0D[3];
    Entry entry[8];
    u8 padA70[0xD10 - 0xA70];
    f32 limit;
} Game;

extern Game *D_800FC270;
extern u8 D_800F3BC0[];
extern char D_80071450[];
extern char D_80071480[];
extern void func_800AAA60(char *, s32, char *);
extern s32 func_8009B73C(s32);
extern void func_800C0110(void *, s32, s32, s32);

#define PLAY(x) func_800C0110(D_800F3BC0, (x), 0, 0)

void func_8009A838(u8 *obj)
{
    Game *g = D_800FC270;
    Entry *found = 0;
    s32 msg = -1;
    Entry *arr = g->entry;
    s32 kind;
    u32 i;
    s8 r;
    s32 hit;
    s32 sw;

    if (g->mode == 0) {
        msg = 206;
    } else if (g->mode == 1) {
        msg = 208;
    } else if (g->mode == 2) {
        msg = 210;
    }

    for (i = 0; i < D_800FC270->count; i++) {
        if (arr[i].b8 == 0) {
            found = &arr[i];
            break;
        }
    }
    if (found == 0) {
        func_800AAA60(D_80071450, 3937, D_80071480);
    }

    kind = found->b0;
    if (kind != 8) {
        kind = D_800FC270->team[kind].kind;
    } else {
        kind = 3;
    }

    switch (D_800FC270->mode) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 5:
        if (*(s8 *)(obj + 0x8050) < 2) {
            if (D_800FC270->sound) {
                PLAY(127);
            }
            return;
        }
        {
            s32 base;
            s32 id;
            s32 msg2;
            if (kind != 3) {
                base = 12;
                id = found->b0;
            } else {
                base = 135;
                id = found->b1;
                msg = -1;
            }
            msg2 = base + id;
            if (D_800FC270->sound) {
                PLAY(msg2);
            }
        }
        if (msg >= 0 && D_800FC270->sound) {
            PLAY(msg);
        }
        break;
    case 4:
        if (*(s8 *)(obj + 0x8050) < 2) {
            if (D_800FC270->sound) {
                PLAY(346);
            }
            return;
        }
        r = func_8009B73C(0);
        hit = 0;
        sw = D_800FC270->sound;
        switch (sw) {
        case 1:
            for (i = 0; i < D_800FC270->count; i++) {
                if (arr[i].b0 == 0 && arr[i].f4 >= D_800FC270->limit) {
                    hit = 1;
                }
            }
            if (hit) {
                if (D_800FC270->sound) {
                    PLAY(242);
                }
            } else {
                if (D_800FC270->sound) {
                    PLAY(235);
                }
            }
            break;
        case 4:
            if (r < 8) {
                PLAY(243);
            } else {
                PLAY(236);
            }
            break;
        case 5:

            if (r == 0) {
                PLAY(240);
            } else if (r == 1) {
                PLAY(238);
            } else if (r == 2) {
                PLAY(239);
            } else if (r == 3) {
                PLAY(237);
            } else {
                PLAY(232);
            }
            break;
        }
        break;
    }
}
