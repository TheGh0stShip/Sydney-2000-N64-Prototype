#ifndef LEAF_NAME
#define LEAF_NAME createNestedRenderObject
#endif

#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateObject
#endif

#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeRenderObject
#endif

#ifndef CONFIGURE_NAME
#define CONFIGURE_NAME configureRenderObject
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 prefix[20];
    u32 flags;
    u8 middle[4];
    u32 mode;
    u8 remainder[100];
} RenderObject;

typedef struct {
    u8 prefix[52];
    float scale;
    RenderObject *renderObject;
} ObjectOwner;

extern volatile const float nestedObjectSmallScale;
extern volatile const float nestedObjectLargeScale;
extern const float nestedObjectVector[3];
extern void *ALLOCATE_NAME(u32 size);
extern void INITIALIZE_NAME(RenderObject *object);
extern void CONFIGURE_NAME(RenderObject *object, const float *vector, u32 first, u32 second);

void LEAF_NAME(ObjectOwner *owner, u8 type) {
    RenderObject *object;

    owner->renderObject = 0;
    if (type == 2) {
        owner->scale = nestedObjectSmallScale;
    } else if (type == 1 || type == 3) {
        owner->scale = nestedObjectLargeScale;
    }

    object = ALLOCATE_NAME(sizeof(RenderObject));
    INITIALIZE_NAME(object);
    owner->renderObject = object;
    CONFIGURE_NAME(object, nestedObjectVector, 0, 0);
    owner->renderObject->flags |= 0x28;
    owner->renderObject->mode = 32;
}
