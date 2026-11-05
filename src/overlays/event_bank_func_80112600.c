typedef struct Actor {
    char pad000[0x5C];
    float speed;
    char pad060[0x178 - 0x60];
    float animSpeed;
    char pad17C[0x278 - 0x17C];
    int animSet;
    char pad27C[0x2E1 - 0x27C];
    unsigned char stepCount;
    unsigned char pad2E2;
    unsigned char pattern;
    unsigned char phase;
    char pad2E5[0x32C - 0x2E5];
    float baseSpeed;
} Actor;

extern unsigned short D_8007DD4C[];
extern unsigned short D_8007DD54[];
extern unsigned char D_8007DD60[][4];

extern void func_800B9E9C(Actor *actor, int anim, int next, int set, int flags);

void func_80112600(Actor *actor) {
    unsigned char step = D_8007DD60[actor->pattern][actor->phase];

    actor->stepCount++;
    func_800B9E9C(actor, D_8007DD54[step], D_8007DD4C[step], actor->animSet, 0);
    actor->speed = actor->baseSpeed;
    actor->animSpeed = actor->baseSpeed;
    if (++actor->phase == 4) {
        actor->phase = 0;
    }
}
