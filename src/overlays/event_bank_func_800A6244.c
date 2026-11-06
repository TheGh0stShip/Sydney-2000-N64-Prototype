/* Announce the next pending competitor, or the stage cue when none is ready. */
typedef struct {
    signed char who;
    unsigned char lane;
    unsigned char pad2[6];
    signed char done;
    unsigned char pad9[3];
} CueEntry;

typedef struct {
    unsigned char pad0[0x20];
    unsigned char state;
    unsigned char pad21[0x3C - 0x21];
} CueRacer;

typedef struct {
    CueRacer racer[1];
} CueTableRacers;

typedef struct {
    unsigned char pad0[0xA00];
    int stage;
    unsigned char padA04[0xA0C - 0xA04];
    unsigned char count;
    unsigned char padA0D[3];
    CueEntry entry[1];
} CueTable;

typedef struct {
    unsigned char pad0[0x7CAF];
    unsigned char mode;
} CueOwner;

extern CueTable *D_800FC270;
extern char D_800F3BC0[];
extern signed char func_8009B73C(void *buf);
extern void func_800C0110(char *bank, int id, int a, int b);

#define QUIET(p) ((unsigned char)((p)->mode - 3) < 2)

void func_80075244(CueOwner *p)
{
    int id = -1;
    int lane = id;
    CueEntry *ent = D_800FC270->entry;
    unsigned char buf[8];
    unsigned int i;

    if (func_8009B73C(buf)) {
        for (i = 0; i < D_800FC270->count; i++) {
            if (ent[i].done == 0) {
                break;
            }
        }
        if (i != D_800FC270->count) {
            int who = ent[i].who;
            int st;
            if (who != 8) {
                st = ((CueTableRacers *)D_800FC270)->racer[who].state;
            } else {
                st = 3;
            }
            if (st == 3) {
                id = 114;
                lane = ent[i].lane;
            }
        }
        if (id != -1) {
            int snd = id + lane;
            if (!QUIET(p)) {
                func_800C0110(D_800F3BC0, snd, 7680, 23040);
            }
        }
        return;
    }
    switch (D_800FC270->stage) {
    case 0:
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 181, 7680, 23040);
        }
        break;
    case 1:
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 183, 7680, 23040);
        }
        break;
    case 2:
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 185, 7680, 23040);
        }
        break;
    }
}
