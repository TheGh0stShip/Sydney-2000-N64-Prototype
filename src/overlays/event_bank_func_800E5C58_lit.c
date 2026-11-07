typedef struct {
    char pad0[0x614];
    unsigned char phase;
    char pad615[0x10D28 - 0x615];
    float table[1][2];
} EventStage;

typedef struct {
    char pad0[4];
    EventStage *stage;
    char pad8[0x19C - 8];
    float speed;
    char pad1A0[0x1AA - 0x1A0];
    unsigned char kind;
    char pad1AB[0x2E7 - 0x1AB];
    unsigned char side;
} EventTeam;

typedef struct {
    char pad0[4];
    EventTeam *team;
    char pad8[0x31C - 8];
    float x;
    char pad320[4];
    float z;
    char pad328[0xAD0 - 0x328];
    int ready;
    float value;
    char padAD8[0xB4B - 0xAD8];
    unsigned char slot2;
    char padB4C[0xBDC - 0xB4C];
    float depth;
    unsigned char slot;
} EventPlayer;

extern unsigned int D_800F13F0;

void func_800E5C58(EventPlayer *p)
{
    EventTeam *team;
    EventStage *stage;
    unsigned char side;
    int hit;
    int hit2;
    unsigned int range;
    unsigned int v;
    float f;
    float lim;
    double d;

    team = p->team;
    stage = team->stage;
    if (team->kind == 4) {
        hit = 0;
        side = hit;
    } else {
        hit = 0;
        side = team->side;
    }
    switch (side) {
    case 0:
        if (p->z >= 0.0f && p->depth > (327.66998f) && p->x <= (327.66998f)) {
            hit = 1;
        }
        break;
    case 1:
        if (p->z < 0.0f && p->depth < (-327.66998f) && (-327.66998f) <= p->x) {
            hit = 1;
        }
        break;
    }
    if (hit) {
        if (stage->phase == 2) {
            p->value = (65.534f);
            stage->table[team->side][p->slot] = p->value;
        } else {
            hit = 0;
            if (stage->phase == 5 || team->kind == 4) {
                hit = 1;
            }
            if (hit) {
                p->value = stage->table[team->side][p->slot2];
            } else {
                hit2 = 0;
                if (team->kind != 1) {
                    hit2 = stage->phase != 5;
                }
                if (hit2) {
                    f = team->speed * (163.83499f) + (16.3835f);
                    lim = (2.1474836e+09f);
                    if (!(lim <= f)) {
                        range = (int)f;
                    } else {
                        f = f - lim;
                        range = (int)f;
                        range |= 0x80000000;
                    }
                    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
                    v = ((D_800F13F0 >> 15) * range) >> 16;
                    d = (int)v;
                    if ((int)v < 0) {
                        d += *(double *)0x80078B90;
                    }
                    p->value = d;
                    stage->table[team->side][p->slot] = p->value;
                }
            }
        }
        p->ready = 1;
    }
}
