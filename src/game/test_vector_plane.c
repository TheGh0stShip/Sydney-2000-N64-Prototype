#ifndef LEAF_NAME
#define LEAF_NAME testVectorPlane
#endif

#ifndef PLANES_NAME
#define PLANES_NAME vectorPlanes
#endif

typedef unsigned int u32;

typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

typedef struct Plane {
    Vector3 normal;
    float distance;
} Plane;

extern Plane PLANES_NAME[];

u32 LEAF_NAME(Vector3 *vector, float radius, u32 index) {
    Plane *planes;
    Plane *plane;
    float projection;
    u32 result;

    planes = PLANES_NAME;
    plane = &planes[index];
    projection = vector->x * plane->normal.x
               + vector->y * plane->normal.y
               + vector->z * plane->normal.z;
    result = 0;
    if (planes[index].distance <= projection + radius) {
        result = 1;
    }
    if (planes[index].distance <= projection - radius) {
        result |= 2;
    }
    return result;
}
