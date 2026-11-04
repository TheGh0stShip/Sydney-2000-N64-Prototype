#ifndef LEAF_NAME
#define LEAF_NAME buildTextureDisplayLists
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 displayListOffset;
    u32 unused04;
    u32 unused08;
    u32 unused0C;
    u32 count;
} TextureDisplayListState;

void LEAF_NAME(TextureDisplayListState *state)
{
    u32 index;
    u8 *base = (u8 *)state + state->displayListOffset;

    for (index = 0; index < state->count; index++) {
        u32 *commands = (u32 *)(base + index * 0x8E0);
        u8 *texture = (u8 *)commands + 0xC0;

        commands[0] = 0xE3001001;
        commands[1] = 0x00008000;
        commands[2] = 0xFD100000;
        commands[3] = (u32)texture;
        commands[4] = 0xE8000000;
        commands[5] = 0;
        commands[6] = 0xF5000100;
        commands[7] = 0x07000000;
        commands[8] = 0xE6000000;
        commands[9] = 0;
        commands[10] = 0xF0000000;
        commands[11] = 0x0703C000;
        commands[12] = 0xE7000000;
        commands[13] = 0;
        commands[14] = 0xD7000002;
        commands[15] = 0xFFFFFFFF;
        commands[16] = 0xFD500000;
        commands[17] = (u32)(texture + 0x20);
        commands[18] = 0xF5500000;
        commands[19] = 0x07018060;
        commands[20] = 0xE6000000;
        commands[21] = 0;
        commands[22] = 0xF3000000;
        commands[23] = 0x073FF200;
        commands[24] = 0xE7000000;
        commands[25] = 0;
        commands[26] = 0xF5400800;
        commands[27] = 0x00018060;
        commands[28] = 0xF2000000;
        commands[29] = 0x000FC0FC;
        commands[30] = 0xDF000000;
        commands[31] = 0;
    }
}
