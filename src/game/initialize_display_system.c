#ifndef LEAF_NAME
#define LEAF_NAME initializeDisplaySystem
#endif
#ifndef RESET_NAME
#define RESET_NAME resetDisplaySystem
#endif
#ifndef PREPARE_NAME
#define PREPARE_NAME prepareDisplaySystem
#endif
#ifndef BUILD_NAME
#define BUILD_NAME buildDisplaySystem
#endif
#ifndef RECORDS_NAME
#define RECORDS_NAME displaySystemRecords
#endif
#ifndef TEMPLATE_NAME
#define TEMPLATE_NAME displaySystemTemplate
#endif
#ifndef STATES_NAME
#define STATES_NAME displaySystemStates
#endif
#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeDisplayRecords
#endif

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 first;
    u32 second;
    u16 index;
    u16 value;
} DisplaySystemRecord;

typedef struct {
    u8 bytes[216];
} DisplaySystemState;

extern DisplaySystemRecord RECORDS_NAME[4];
extern DisplaySystemState TEMPLATE_NAME;
extern DisplaySystemState STATES_NAME[8];
extern void RESET_NAME(u32 value);
extern void PREPARE_NAME(void);
extern void BUILD_NAME(void);
extern void INITIALIZE_NAME(void);

u32 LEAF_NAME(void)
{
    u8 index;

    RESET_NAME(0);
    PREPARE_NAME();
    for (index = 0; index < 4; index++) {
        RECORDS_NAME[index].first = 0;
        RECORDS_NAME[index].second = 0;
        RECORDS_NAME[index].index = 0xFFFF;
        RECORDS_NAME[index].value = 0;
    }
    BUILD_NAME();
    for (index = 0; index < 8; index++) {
        STATES_NAME[index] = TEMPLATE_NAME;
    }
    INITIALIZE_NAME();
    return 1;
}
