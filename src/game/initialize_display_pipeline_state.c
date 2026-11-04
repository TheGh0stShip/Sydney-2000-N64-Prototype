#ifndef LEAF_NAME
#define LEAF_NAME initializeDisplayPipelineState
#endif

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 command;
    u32 value;
} DisplayCommand;

extern u16 displayStateValue;
extern u32 displayStateFirst;
extern u32 displayStateSecond;
extern u32 screenWidth;
extern u32 screenHeight;
extern u32 displayWidth;
extern u32 displayHeight;
extern DisplayCommand *displayCommandPointer;

void LEAF_NAME(void)
{
    DisplayCommand *command;

    displayStateValue = 0;
    displayStateFirst = 0;
    displayStateSecond = 0;
    displayWidth = screenWidth;
    displayHeight = screenHeight;

    command = displayCommandPointer;
    displayCommandPointer = command + 1;
    command->command = 0xE7000000;
    command->value = 0;

    command = displayCommandPointer;
    displayCommandPointer = command + 1;
    command->command = 0xE3000A01;
    command->value = 0;

    command = displayCommandPointer;
    displayCommandPointer = command + 1;
    command->command = 0xD7000002;
    command->value = 0x80008000;

    command = displayCommandPointer;
    displayCommandPointer = command + 1;
    command->command = 0xE2001E01;
    command->value = 0;

    command = displayCommandPointer;
    displayCommandPointer = command + 1;
    command->command = 0xE3000C00;
    command->value = 0;

    command = displayCommandPointer;
    displayCommandPointer = command + 1;
    command->command = 0xE3001201;
    command->value = 0x2000;

    command = displayCommandPointer;
    displayCommandPointer = command + 1;
    command->command = 0xE3001402;
    command->value = 0x0C00;

    command = displayCommandPointer;
    displayCommandPointer = command + 1;
    command->command = 0xE3000D01;
    command->value = 0;

    command = displayCommandPointer;
    displayCommandPointer = command + 1;
    command->command = 0xE3000F00;
    command->value = 0;

    command = displayCommandPointer;
    displayCommandPointer = command + 1;
    command->command = 0xE3001001;
    command->value = 0;
}
