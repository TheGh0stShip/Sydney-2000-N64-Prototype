#ifndef LEAF_NAME
#define LEAF_NAME emitRuntimeDisplayCommands
#endif

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct CommandPair {
    u32 word0;
    u32 word1;
} CommandPair;

typedef struct CoordinateInput {
    u16 pad00[6];
    u16 first;
    u16 second;
    u16 third;
    u16 fourth;
} CoordinateInput;

extern CommandPair *D_800663DC;
extern u16 D_8005F910[];
extern u32 D_8005AC98;

void LEAF_NAME(u32 index, CoordinateInput *input)
{
    u16 *values = &D_8005F910[index * 8];
    CommandPair *command;
    CommandPair *base;

    values[2] = 0x1FF;
    values[3] = 0;
    values[6] = 0x1FF;
    values[7] = 0;
    values[0] = input->third * 2;
    values[1] = input->fourth * 2;
    values[4] = (input->first * 2 + input->third) * 2;
    values[5] = (input->second * 2 + input->fourth) * 2;

    command = D_800663DC++;
    command->word0 = 0xDB060000;
    command->word1 = 0;

    base = D_800663DC;
    base->word1 = (u32)values;
    D_800663DC = base + 1;
    base->word0 = 0xDC080008;

    command = D_800663DC++;
    command->word0 = 0xDE000000;
    command->word1 = 0x00066180;

    if (D_8005AC98 != 0) {
        command = D_800663DC++;
        command->word0 = 0xDE000000;
        command->word1 = 0x00066048;
        D_8005AC98 = 0;
    }

    command = D_800663DC++;
    command->word0 = 0xDE000000;
    command->word1 = 0x00066138;
}
