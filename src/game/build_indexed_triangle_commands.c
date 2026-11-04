#ifndef LEAF_NAME
#define LEAF_NAME buildIndexedTriangleCommands
#endif

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 command;
    u32 value;
} Gfx;

typedef struct {
    u8 padding00[0x54];
    u8 *vertexBase;
    u32 unused58;
    Gfx *displayLists[3];
    u16 padding68;
    u16 indexCount;
    u16 *indices;
} IndexedTriangleObject;

extern u32 activeDisplayList __asm__("D_8005A93C");

void LEAF_NAME(IndexedTriangleObject *object)
{
    u16 *indices = object->indices;
    u32 count = object->indexCount;
    Gfx *displayList = object->displayLists[activeDisplayList];
    u32 pair;

    for (pair = 0; pair < count / 2; pair++) {
        u16 first = *indices++;
        u16 second = *indices++;
        u16 third = *indices++;
        u16 fourth = *indices++;
        u16 fifth = *indices++;
        u16 sixth = *indices++;

        displayList[0].command = 0x01001002;
        displayList[0].value = (u32)(object->vertexBase + first * 16);
        displayList[1].command = 0x01001004;
        displayList[1].value = (u32)(object->vertexBase + second * 16);
        displayList[2].command = 0x01001006;
        displayList[2].value = (u32)(object->vertexBase + third * 16);
        displayList[3].command = 0x01001008;
        displayList[3].value = (u32)(object->vertexBase + fourth * 16);
        displayList[4].command = 0x0100100A;
        displayList[4].value = (u32)(object->vertexBase + fifth * 16);
        displayList[5].command = 0x0100100C;
        displayList[5].value = (u32)(object->vertexBase + sixth * 16);
        displayList[6].command = 0x06040200;
        displayList[6].value = 0x000A0806;
        displayList += 7;
    }

    if (count & 1) {
        u32 first = *indices++;
        u32 second = indices[0];
        u32 third = indices[1];
        displayList->command = 0x05000000 | ((third << 1) & 0xFF) << 16 |
                               ((second << 1) & 0xFF) << 8 |
                               ((first << 1) & 0xFF);
        displayList->value = 0;
        displayList++;
    }

    displayList->command = 0xDF000000;
    displayList->value = 0;
}
