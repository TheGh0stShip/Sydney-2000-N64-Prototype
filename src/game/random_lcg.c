#ifndef LEAF_NAME
#define LEAF_NAME randomLcg
#endif
#ifndef SEED_NAME
#define SEED_NAME randomSeed
#endif

extern unsigned int SEED_NAME;

int LEAF_NAME(void) {
    SEED_NAME = SEED_NAME * 20077U + 12345U;
    return (SEED_NAME >> 16) & 0x7FFF;
}
