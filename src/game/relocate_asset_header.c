#ifndef LEAF_NAME
#define LEAF_NAME relocateAssetHeader
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 padding00[0x20];
    u16 type;
    u16 padding22;
    u32 childCount;
    u32 flags;
    u32 children;
    u32 padding30;
    u32 pointer34;
    u32 padding38;
    u32 pointer3C;
    u32 pointer40;
    u32 padding44;
    u32 pointer48;
    u32 padding4C;
    u32 padding50;
    u32 pointer54;
} AssetHeader;

typedef struct {
    u8 padding00[0x50];
    u32 firstPointers[4];
    u32 secondPointers[8];
    u8 pointerCount;
    u8 padding81[3];
} AssetChild;

typedef struct {
    u8 padding00[0x28];
    u32 flags;
} AssetOutput;

void LEAF_NAME(void *data, AssetOutput *output) {
    register u32 base __asm__("$9");
    register volatile AssetHeader *header __asm__("$7");
    register volatile AssetChild *child __asm__("$6");
    register u32 childIndex __asm__("$8");
    register u32 pointerIndex __asm__("$5");
    register u32 firstPointer __asm__("$2");
    register u32 secondPointer __asm__("$3");
    register u32 *pointerSlot __asm__("$2");
    register u32 firstChildPointer __asm__("$3");
    register u32 secondChildPointer __asm__("$4");

    base = (u32)data;
    __asm__("" : "=r"(base) : "0"(base));
    header = (volatile AssetHeader *)base;
    __asm__("" : "=r"(header) : "0"(header));

    firstPointer = header->pointer34;
    secondPointer = header->pointer3C;
    firstPointer = (u32)header + firstPointer;
    header->pointer34 = firstPointer;
    firstPointer = header->pointer40;
    secondPointer = (u32)header + secondPointer;
    header->pointer3C = secondPointer;
    secondPointer = header->pointer48;
    firstPointer = (u32)header + firstPointer;
    header->pointer40 = firstPointer;
    firstPointer = header->children;
    secondPointer = (u32)header + secondPointer;
    header->pointer48 = secondPointer;
    secondPointer = header->pointer54;
    firstPointer = (u32)header + firstPointer;
    secondPointer = (u32)header + secondPointer;
    header->children = firstPointer;
    header->pointer54 = secondPointer;

    output->flags = 0;
    if (header->flags & 1) {
        output->flags = 1;
    }
    if ((header->flags & 2) && header->type >= 2) {
        output->flags |= 2;
    }
    if (header->flags & 4) {
        output->flags |= 4;
    }

    firstPointer = header->childCount;
    secondPointer = header->children;
    __asm__("" : "=r"(firstPointer), "=r"(secondPointer)
            : "0"(firstPointer), "1"(secondPointer));
    childIndex = 0;
    if (firstPointer != 0) {
        child = (volatile AssetChild *)secondPointer;
        do {
            if (child->pointerCount != 0) {
                pointerIndex = 0;
                do {
                    pointerSlot = (u32 *)((u8 *)child + (pointerIndex << 2));
                    firstChildPointer = pointerSlot[0x50 / 4];
                    secondChildPointer = pointerSlot[0x60 / 4];
                    firstChildPointer += base;
                    secondChildPointer += base;
                    pointerSlot[0x50 / 4] = firstChildPointer;
                    pointerSlot[0x60 / 4] = secondChildPointer;
                    pointerIndex++;
                } while (pointerIndex < child->pointerCount);
            }
            child++;
            childIndex++;
        } while (childIndex < header->childCount);
    }
}
