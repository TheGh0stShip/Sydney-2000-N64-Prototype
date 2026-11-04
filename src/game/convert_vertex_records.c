#ifndef LEAF_NAME
#define LEAF_NAME convertVertexRecords
#endif

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct SourceVertex {
    float x;
    float y;
    float z;
    u8 pad0C[0x10];
    float secondValue;
    float firstValue;
} SourceVertex;

typedef struct OutputVertex {
    s16 x;
    s16 y;
    s16 z;
    s16 pad06;
    s16 firstValue;
    s16 secondValue;
    u8 pad0C[4];
} OutputVertex;

typedef struct VertexObject {
    u8 pad00[0x50];
    SourceVertex *source;
    OutputVertex *outputs[4];
    u32 count;
} VertexObject;

extern u32 D_8005A93C;

void LEAF_NAME(VertexObject *object)
{
    SourceVertex *source;
    OutputVertex *output;
    float firstValue;
    float secondValue;
    u32 index;

    if (object->count == 0) {
        return;
    }

    source = object->source;
    output = object->outputs[D_8005A93C];
    index = 0;
    do {
        output[index].x = (s16)source->x;
        output[index].y = (s16)source->y;
        output[index].z = (s16)source->z;

        firstValue = source->firstValue;
        secondValue = 1.0 - source->secondValue;
        if (firstValue > 15.0) {
            firstValue = 15.0f;
        }
        if (secondValue > 15.0) {
            secondValue = 15.0f;
        }
        output[index].firstValue = (s16)(firstValue * 2048.0f);
        output[index].secondValue = (s16)(secondValue * 2048.0f);

        source++;
        index++;
    } while (index < object->count);
}
