#ifndef LEAF_NAME
#define LEAF_NAME updatePackedDisplayRecords
#endif

#ifndef PREPARE_NAME
#define PREPARE_NAME prepareDisplayRecords
#endif

#ifndef INDICES_NAME
#define INDICES_NAME displayRecordIndices
#endif

#ifndef POINTERS_NAME
#define POINTERS_NAME displayRecordObjects
#endif

#ifndef TEMPLATES_NAME
#define TEMPLATES_NAME displayRecordTemplates
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME displayRecords
#endif

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 word;
    u16 halfword;
} __attribute__((packed, aligned(2))) PackedDisplayRecord;

typedef struct {
    u8 unused[8];
    s16 index;
    u8 remainder[2];
} DisplayRecordIndex;

extern DisplayRecordIndex INDICES_NAME[4];
extern u8 *POINTERS_NAME[4];
extern PackedDisplayRecord TEMPLATES_NAME[4];
extern PackedDisplayRecord RECORDS_NAME[];
extern void PREPARE_NAME(void);

void LEAF_NAME(void) {
    u32 index;

    PREPARE_NAME();
    for (index = 0; index < 4; index++) {
        PackedDisplayRecord *record = &RECORDS_NAME[INDICES_NAME[index].index];

        *record = TEMPLATES_NAME[index];
        ((u8 *)record)[2] = POINTERS_NAME[index][2];
        ((u8 *)record)[3] = POINTERS_NAME[index][3];
    }
}
