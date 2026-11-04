#ifndef LEAF_NAME
#define LEAF_NAME configureDisplayPipeline
#endif

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 *displayListHead;
extern u16 displayPipelineFlags;

void LEAF_NAME(void) {
    u32 *command;

    command = displayListHead;
    displayListHead = command + 2;
    command[0] = 0xD7000000;
    command[1] = 0x80008000;

    command = displayListHead;
    displayListHead = command + 2;
    command[0] = 0xFCFFFFFF;
    command[1] = 0xFFFE793C;

    if (displayPipelineFlags & 1) {
        command = displayListHead;
        displayListHead = command + 2;
        command[0] = 0xE200001C;
        command[1] = 0x0F0A4000;
    }

    if (displayPipelineFlags & 2) {
        command = displayListHead;
        displayListHead = command + 2;
        command[0] = 0xE2001E01;
        command[1] = 0;
    }
}
