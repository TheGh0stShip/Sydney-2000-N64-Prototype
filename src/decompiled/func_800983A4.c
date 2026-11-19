#include "sydney_types.h"

/* Race-result timer: when it expires, judges the recorded time against record limits and plays the matching jingle. */
typedef struct Record {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} Record;

typedef struct Cfg {
    u8 unk_000[0x4FC];
    f32 limit4FC;
    u8 unk_500[0x528 - 0x500];
    f32 limit528;
    u8 unk_52C[0xA00 - 0x52C];
    s32 mode;
    u8 unk_A04[0xA10 - 0xA04];
    Record records[(0xDE4 - 0xA10) / 12];
    u8 unk_pad[(0xDE4 - 0xA10) % 12];
    f32 limitDE4;
} Cfg;

typedef struct Result {
    u8 unk_00[0x50];
    s8 lane;
    s8 row;
    u8 unk_52;
    u8 unk_53;
    u8 kind;
    u8 unk_55[0x6C - 0x55];
    s32 timer;
    u8 unk_70[0x8C - 0x70];
    f32 *times;
} Result;

typedef struct Player {
    u8 unk_000[0x1AA];
    u8 unk_1AA;
    u8 unk_1AB[0x300 - 0x1AB];
    s32 unk_300;
} Player;

typedef struct Game {
    u8 unk_0000[0x2B8];
    u8 unk_02B8[0x2F68 - 0x2B8];
    Player *player;
    u8 unk_2F6C[0x3DF4 - 0x2F6C];
    u8 unk_3DF4[0x8000 - 0x3DF4];
    Result result;
} Game;

typedef struct Msg {
    u8 unk_00[0x10];
    s32 id;
} Msg;

typedef struct Snd {
    u8 unk_00[0x68];
    s32 volume;
} Snd;

extern Cfg *D_800FC270;
extern s32 D_800F1270[];
extern Msg D_800F1280;
extern Snd D_800F1AE0;

void func_8009BD10(f32 t, s32 a, s32 b, s32 *c, s32 *d);
s32 func_8009BFE8(s32 a, Record *rec, u8 kind, f32 t);
s32 func_8001D4B8(Snd *snd, s32 id, s32 a, s32 b);
void func_8001D640(Snd *snd, s32 voice, s32 vol);
void func_800D33A0(void *p, Msg *msg, s32 a, s32 b);
void func_800B31EC(s32 a);
void func_80096C8C(void *p, s32 a, s32 b, f32 *times, s32 lane, s32 c);

static __inline__ void setVolume(Snd *snd, s32 voice, s32 vol) {
    func_8001D640(snd, voice, (snd->volume * vol) >> 15);
}

void func_80072DB4(Game *game) {
    Result *r;
    s32 jingle;
    f32 t;
    Msg *msg;
    s32 voice;
    s32 mode;

    game->result.timer -= 0x100;
    if (game->result.timer > 0) {
        return;
    }
    jingle = 0xC0;
    if (game->result.lane < 3) {
        t = game->result.times[game->result.row * 3 + game->result.lane];
    } else {
        t = game->result.times[game->result.row * 3 + 2];
    }
    if (t > 0.0f) {
        func_8009BD10(t, 2, 2, D_800F1270, &D_800F1270[1]);
        msg = &D_800F1280;
        msg->id = 0x18F;
        if (func_8009BFE8(2, &D_800FC270->records[game->result.row], game->result.kind, t) != 0) {
            msg->id = 0x25B;
            jingle = 0xDC;
        }
        if (D_800FC270->mode == 4 && D_800FC270->limit528 < t) {
            msg->id = 0x25A;
            jingle = 0xDC;
        }
        if (D_800FC270->mode == 5 && D_800FC270->limitDE4 < t) {
            D_800F1280.id = 0x25C;
            jingle = 0xDC;
        }
        mode = D_800FC270->mode;
        if (mode == 4 || mode == 0 || mode == 1 || mode == 2) {
            if (game->result.kind != 4 && D_800FC270->limit4FC < t) {
                D_800F1280.id = 0x259;
                jingle = 0xDC;
            }
        }
    } else {
        D_800F1280.id = 0x253;
        jingle = 0xC8;
    }
    voice = func_8001D4B8(&D_800F1AE0, jingle, 0, 0);
    setVolume(&D_800F1AE0, voice, 0x7FFF);
    func_800D33A0(game->unk_02B8, &D_800F1280, 1, -1);
    func_800B31EC(0);
    game->player->unk_300 = 1;
    r = &game->result;
    switch (r->kind) {
    case 5:
        r->unk_52 = 0x10;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        if (game->player->unk_1AA != 3) {
            func_80096C8C(game->unk_3DF4, 2, D_800FC270->records[r->row].unk_04, &r->times[r->row * 3], r->lane, 0);
        }
        r->unk_52 = 0x10;
        break;
    }
}
