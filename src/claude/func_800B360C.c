/* Runtime-stage C reconstruction: initialise an actor from its spawn definition. */
typedef struct {
    short x;              /* 0x00 */
    short y;              /* 0x02 */
    char pad04[4];
    int model;            /* 0x08 */
    int anim;             /* 0x0C */
    char pad10[2];
    unsigned short sound; /* 0x12 */
    int param;            /* 0x14 */
} SpawnDef;

typedef struct {
    char pad0[0x40];
    float x;              /* 0x40 */
    float y;              /* 0x44 */
    int state;            /* 0x48 */
} Motion;

typedef struct {
    char pad0[0x60];
    Motion motion;        /* 0x60 */
    char padAC[0xD4 - 0xAC];
    unsigned short flags; /* 0xD4 */
    char padD6[2];
    short handle;         /* 0xD8 */
} Actor;

extern void func_800ADC54(Actor *actor, int model);
extern void func_800B34F4(Actor *actor);
extern int func_800D98FC(unsigned short sound);
extern short func_800B1D60(Actor *actor, int anim, int sound, int param);

void func_800B360C(Actor *actor, SpawnDef *def) {
    int x = def->x;
    int y = def->y;
    Motion *m = &actor->motion;
    m->state = 0;
    m->x = x;
    m->y = y;
    func_800ADC54(actor, def->model);
    func_800B34F4(actor);
    actor->flags |= 4;
    actor->handle = func_800B1D60(actor, def->anim, func_800D98FC(def->sound), def->param);
}
