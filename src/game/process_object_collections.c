#ifndef LEAF_NAME
#define LEAF_NAME processObjectCollections
#endif

#ifndef PROCESS_NAME
#define PROCESS_NAME processObject
#endif

typedef struct Object Object;

struct Object {
    unsigned char padding[188];
    Object *next;
};

extern void PROCESS_NAME(Object *object);

void LEAF_NAME(void) {
    Object **cursor;
    Object *object;

    object = *(Object **)0x8005AAC4;
    if (object != 0) {
        cursor = (Object **)0x8005AAC8;
        do {
            PROCESS_NAME(object);
            object = *cursor++;
        } while (object != 0);
    }

    object = *(Object **)0x8005AAB0;
    while (object != 0) {
        PROCESS_NAME(object);
        object = object->next;
    }

    object = *(Object **)0x8005AAB4;
    while (object != 0) {
        PROCESS_NAME(object);
        object = object->next;
    }
}
