#ifndef LEAF_NAME
#define LEAF_NAME unlinkRuntimeNode
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct RuntimeNode {
    u8 pad00[0xB8];
    struct RuntimeNode *previous;
    struct RuntimeNode *next;
    u32 flags;
    u8 padC4[8];
    u32 groups;
} RuntimeNode;

typedef struct RuntimeRecord {
    u8 pad00[0x70];
    u32 secondaryCount;
    u32 defaultCount;
    u32 primaryCount;
    u8 pad7C[8];
} RuntimeRecord;

extern RuntimeNode *D_8005AAAC;
extern RuntimeNode *D_8005AAB0;
extern RuntimeNode *D_8005AAB4;
extern RuntimeRecord D_8005AAF0[];

void LEAF_NAME(RuntimeNode *node)
{
    RuntimeNode *previous = node->previous;
    RuntimeNode *next = node->next;
    RuntimeRecord *record;
    u32 index;

    if (previous == 0) {
        return;
    }

    if (previous != node) {
        previous->next = next;
    } else {
        if (D_8005AAB0 == node) {
            D_8005AAB0 = next;
            previous = next;
        } else if (D_8005AAAC == node) {
            D_8005AAAC = next;
            previous = next;
        } else if (D_8005AAB4 == node) {
            D_8005AAB4 = next;
            previous = next;
        }
    }

    if (next != 0) {
        next->previous = previous;
    }

    node->next = 0;
    node->previous = 0;
    record = D_8005AAF0;
    for (index = 0; index < 3; index++, record++) {
        if (node->groups & (1U << index)) {
            if (node->flags & 0x80000078) {
                record->primaryCount--;
            } else if (node->flags & 0x00040000) {
                record->secondaryCount--;
            } else {
                record->defaultCount--;
            }
        }
    }
}
