#ifndef LEAF_NAME
#define LEAF_NAME filterGroupedByteSequences
#endif

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 count;
    u8 *values;
    u8 padding08[24];
} ByteSequence;

typedef struct {
    u32 finalIndex;
    ByteSequence *sequences;
    u32 pathCount;
    u32 padding0C;
    u16 *path;
    u32 padding14;
} SequenceGroup;

typedef struct {
    u16 groupCount;
    u8 padding02[30];
    SequenceGroup *groups;
} GroupedSequences;

typedef struct {
    u8 padding00[24];
    s16 limit;
} SequenceFilter;

void LEAF_NAME(GroupedSequences *container, SequenceFilter *filter)
{
    u32 pass;
    u32 continuePasses;

    continuePasses = 1;
    for (pass = 0; pass < 2 && continuePasses != 0; pass++) {
        u32 groupIndex;
        SequenceGroup *group;

        group = container->groups;
        for (groupIndex = 0; groupIndex < container->groupCount;
             groupIndex++, group++) {
            u32 pathIndex;

            for (pathIndex = 0; pathIndex < group->pathCount; pathIndex++) {
                u32 sequenceIndex;
                u32 endIndex;

                sequenceIndex = group->path[pathIndex];
                if (pathIndex < group->pathCount - 1) {
                    endIndex = group->path[pathIndex + 1];
                } else {
                    endIndex = group->finalIndex;
                }

                for (; sequenceIndex < endIndex; sequenceIndex++) {
                    ByteSequence *sequence = &group->sequences[sequenceIndex];

                    if (pass == 0) {
                        if (sequence->values[0] >= filter->limit) {
                            continuePasses = 0;
                            break;
                        }
                    } else if (sequence->count != 0) {
                        u32 valueIndex;

                        for (valueIndex = 0; valueIndex < sequence->count;
                             valueIndex++) {
                            if (sequence->values[valueIndex] >= filter->limit) {
                                u32 shiftIndex;

                                for (shiftIndex = valueIndex;
                                     shiftIndex < sequence->count;
                                     shiftIndex++) {
                                    sequence->values[shiftIndex] =
                                        sequence->values[shiftIndex + 1];
                                }
                                sequence->count--;
                                valueIndex--;
                            }
                        }
                    }
                }
            }
        }
    }
}
