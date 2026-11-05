typedef struct VTSlot {
    short offset;
    short pad;
    void (*fn)(void *self);
} VTSlot;

typedef struct Actor {
    unsigned char pad[176];
    unsigned char active;
    unsigned char pad2[3];
    VTSlot *vt;
} Actor;

extern unsigned char *D_800FC270;
extern void func_800CFFC4(void *actor);
extern void func_800CCB0C(void *sound);
extern void func_800D29E0(void *actor);
extern void func_800AC334(void *state);
extern void func_800751CC(unsigned char *object, int arg);
extern void func_800AC308(unsigned char *object);
extern void func_8007F754(unsigned char *object);
extern void func_800DA804(int a, int b, void *buf, int c, int d);


#define ROUND_INDEX ((object + 0x8000)[3224])
#define STAGE_INDEX ((object + 0x8000)[3225])
#define STAGE_COUNT ((object + 0x8000)[3226])

void func_8007F4B8(unsigned char *object)
{
    unsigned char buf[128];
    Actor *actor;
    unsigned char *state;

    actor = (Actor *)(object + 21396);
    actor->vt[3].fn((unsigned char *)actor + actor->vt[3].offset);
    actor->active = 0;
    func_800CFFC4(actor);
    func_800CCB0C(object + 31156);

    actor = (Actor *)(object + 13200);
    func_800D29E0(actor);
    actor->vt[3].fn((unsigned char *)actor + actor->vt[3].offset);
    actor->active = 0;

    actor = (Actor *)(object + 11564);
    actor->vt[3].fn((unsigned char *)actor + actor->vt[3].offset);
    actor->active = 0;

    actor = (Actor *)(object + 11800);
    actor->vt[3].fn((unsigned char *)actor + actor->vt[3].offset);
    actor->active = 0;

    actor = (Actor *)(object + 696);
    actor->vt[3].fn((unsigned char *)actor + actor->vt[3].offset);
    actor->active = 0;

    state = object + 0x87EC;
    if (*(int *)(state + 4) != 0) {
        func_800AC334(state);
    }
    func_800751CC(object, 0);
    func_800AC308(object);

    while (ROUND_INDEX + 1 < D_800FC270[2572]) {
        unsigned char *base = D_800FC270;
        unsigned char *slot = base + ROUND_INDEX * 12;
        signed char kind = slot[2576];

        if (kind == 8) {
            func_8007F754(object);
        } else {
            unsigned char *team = base + kind * 60;
            if (team[32] != 1) {
                func_8007F754(object);
            }
        }
        ROUND_INDEX++;
    }
    while (STAGE_INDEX + 1 != STAGE_COUNT) {
        ROUND_INDEX = 0;
        STAGE_INDEX++;
        while (ROUND_INDEX + 1 < D_800FC270[2572]) {
            unsigned char *base = D_800FC270;
            unsigned char *slot = base + ROUND_INDEX * 12;
            signed char kind = slot[2576];

            if (kind == 8) {
                func_8007F754(object);
            } else {
                unsigned char *team = base + kind * 60;
                if (team[32] != 1) {
                    func_8007F754(object);
                }
            }
            ROUND_INDEX++;
        }
    }
    func_800DA804(0, 0, buf, 0, 0);
}
