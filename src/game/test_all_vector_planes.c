#ifndef LEAF_NAME
#define LEAF_NAME testAllVectorPlanes
#endif

#ifndef TEST_NAME
#define TEST_NAME testVectorPlane
#endif

typedef signed int s32;
typedef unsigned int u32;

extern s32 TEST_NAME(float *vector, float tolerance, s32 index);

s32 LEAF_NAME(float *vector, float tolerance) {
    u32 index;
    s32 result;

    result = 1;
    for (index = 0; index < 4; index++) {
        if (TEST_NAME(vector, tolerance, index) == 0) {
            result = 0;
            break;
        }
    }
    return result;
}
