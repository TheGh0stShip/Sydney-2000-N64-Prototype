#ifndef LEAF_NAME
#define LEAF_NAME setGlobalValue
#endif

#ifndef GLOBAL_NAME
#define GLOBAL_NAME globalValue
#endif

extern int GLOBAL_NAME;

void LEAF_NAME(int value) {
    GLOBAL_NAME = value;
}
