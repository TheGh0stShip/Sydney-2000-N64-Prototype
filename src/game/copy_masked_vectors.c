#ifndef LEAF_NAME
#define LEAF_NAME copyMaskedVectors
#endif

typedef unsigned int u32;

typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

typedef struct VectorRecord {
    Vector3 value;
    u32 padding[6];
} VectorRecord;

typedef struct VectorOwner {
    u32 padding[20];
    VectorRecord *records;
} VectorOwner;

int LEAF_NAME(VectorOwner **owner, u32 mask, Vector3 *values) {
    register u32 index __asm__("$7");
    register u32 bit __asm__("$8");
    register VectorRecord *loadedRecord __asm__("$2");
    register VectorRecord *record __asm__("$3");
    register float *source __asm__("$6");
    register float *sourceZ __asm__("$4");
    VectorRecord *recordHome;

    loadedRecord = (*owner)->records;
    record = loadedRecord;
    recordHome = record;
    __asm__("" : : "m"(recordHome));
    bit = 1;
    source = (float *)values;
    sourceZ = source + 2;
    for (index = 0; index < 4; index++) {
        if (mask & (bit << index)) {
            record->value.x = source[0];
            record->value.y = sourceZ[-1];
            record->value.z = sourceZ[0];
            source += 3;
            sourceZ += 3;
        }
        record++;
    }
    return 0;
}
