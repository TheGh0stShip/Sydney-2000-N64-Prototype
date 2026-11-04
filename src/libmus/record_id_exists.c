#ifndef LEAF_NAME
#define LEAF_NAME recordIdExists
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME records
#endif

#ifndef COUNT_NAME
#define COUNT_NAME recordCount
#endif

typedef struct {
    char padding[0x11E8];
    unsigned short identifier;
    char trailing[0x16];
} Record;

extern Record *RECORDS_NAME;
extern unsigned short COUNT_NAME;

int LEAF_NAME(unsigned short identifier) {
    int index;

    if (identifier == 0xFFFF) {
        return 0;
    }
    for (index = 0; index < COUNT_NAME; index++) {
        if (RECORDS_NAME[index].identifier == identifier) {
            return 1;
        }
    }
    return 0;
}
