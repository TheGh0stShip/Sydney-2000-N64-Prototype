#ifndef LEAF_NAME
#define LEAF_NAME emitResourceDisplayLists
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct DisplayCommand {
    u32 word0;
    u32 word1;
} DisplayCommand;

typedef struct ResourceRecord {
    u8 pad00[0xD0];
    void *firstDisplayList;
    void *secondDisplayList;
    u8 padD8[8];
} ResourceRecord;

extern ResourceRecord D_80049A28[300];

void LEAF_NAME(DisplayCommand **head, u32 skipRecordDisplayList)
{
    ResourceRecord *record;
    u32 index;

    record = D_80049A28;
    index = 0;
    do {
        if (record->firstDisplayList != 0 || record->secondDisplayList != 0) {
            if (skipRecordDisplayList == 0) {
                (*head)->word0 = 0xDE000000;
                (*head)->word1 = (u32)record + 0x10;
                (*head)++;
            }
            if (record->firstDisplayList != 0) {
                (*head)->word0 = 0xD9FDFFFF;
                (*head)->word1 = 0;
                (*head)++;
                (*head)->word0 = 0xDE000000;
                (*head)->word1 = (u32)record->firstDisplayList;
                (*head)++;
            }
            if (record->secondDisplayList != 0) {
                (*head)->word0 = 0xD9FFFFFF;
                (*head)->word1 = 0x20000;
                (*head)++;
                (*head)->word0 = 0xDE000000;
                (*head)->word1 = (u32)record->secondDisplayList;
                (*head)++;
            }
        }
        record++;
        index++;
    } while (index < 300);
}
