#ifndef LEAF_NAME
#define LEAF_NAME resetRuntimeCollections
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct RuntimeNode {
    u8 pad00[0xB8];
    struct RuntimeNode *previous;
    struct RuntimeNode *next;
} RuntimeNode;

typedef struct RuntimeRecord {
    u8 pad00[0x74];
    u32 first;
    u32 second;
    u8 pad7C[8];
} RuntimeRecord;

extern RuntimeNode *D_8005AAAC;
extern RuntimeNode *D_8005AAB0;
extern RuntimeNode *D_8005AAB4;
extern u16 D_8005A930;
extern RuntimeRecord D_8005AAF0[];
extern u32 D_8005B7E0;
extern u32 D_8005B7E4;
extern u32 D_8005B7EC;
extern u32 D_8005B7F0;

extern void func_80018904(void);
extern void func_80018910(void);
extern void func_8001891C(void);

int LEAF_NAME(void)
{
    RuntimeNode *node;
    RuntimeNode *next;
    RuntimeNode **head;
    u8 index;

    head = &D_8005AAAC;
    while ((node = *head) != 0) {
        next = node->next;
        node->next = 0;
        node->previous = 0;
        *head = next;
    }
    head = &D_8005AAB0;
    while ((node = *head) != 0) {
        next = node->next;
        node->next = 0;
        node->previous = 0;
        *head = next;
    }
    head = &D_8005AAB4;
    while ((node = *head) != 0) {
        next = node->next;
        node->next = 0;
        node->previous = 0;
        *head = next;
    }

    D_8005A930 = 0;
    for (index = 0; index < 3; index++) {
        D_8005AAF0[index].first = 0;
        D_8005AAF0[index].second = 0;
    }

    func_80018904();
    func_80018910();
    func_8001891C();
    D_8005B7E0 = 0;
    D_8005B7E4 = 0;
    D_8005B7EC = 0;
    D_8005B7F0 = 0;
    return 0;
}
