#ifndef LEAF_NAME
#define LEAF_NAME processTypedObject
#endif
#ifndef CHECK_NAME
#define CHECK_NAME objectIsExcluded
#endif
#ifndef UPDATE_NAME
#define UPDATE_NAME updateObject
#endif
#ifndef APPLY_NAME
#define APPLY_NAME applyObjectState
#endif
#ifndef MODE_NAME
#define MODE_NAME objectProcessingMode
#endif

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 flags;
    u8 padding04[0x1C];
    union {
        u32 word;
        struct {
            u16 first;
            u16 value;
        } halves;
    } control;
    u8 padding24[0x46];
    u16 value;
    u8 padding6C[0x0A];
    u16 state;
} TypedObjectState;

typedef struct {
    u32 type;
    u8 padding04[0xBC];
    u32 flags;
    TypedObjectState *state;
} TypedObject;

extern u32 MODE_NAME;
extern u32 CHECK_NAME(TypedObject *object);
extern void UPDATE_NAME(TypedObjectState *state);
extern void APPLY_NAME(TypedObjectState *state, u32 value);

void LEAF_NAME(TypedObject *object)
{
    TypedObjectState *state;
    u32 savedMode;
    u32 nestedMode;
    u16 savedValue;

    if (object == 0 || object->state == 0 || (object->flags & 0x20000) != 0) {
        return;
    }
    if (CHECK_NAME(object) != 0) {
        return;
    }

    savedMode = MODE_NAME;
    switch (object->type) {
    case 80:
        state = object->state;
        if (state->control.word != 0) {
            nestedMode = MODE_NAME;
            savedValue = state->value;
            state->value = state->control.halves.value;
            MODE_NAME = 0;
            UPDATE_NAME(state);
            APPLY_NAME(state, 1);
            MODE_NAME = 1;
            UPDATE_NAME(state);
            APPLY_NAME(state, 1);
            state->value = savedValue;
            MODE_NAME = nestedMode;
            state->control.word = 0;
        }
        break;
    case 8:
    case 60:
    case 71: case 72: case 73: case 74: case 75: case 76:
    case 79:
    case 81: case 82: case 83: case 84: case 85: case 86:
    case 88: case 89:
    case 105:
        state = object->state;
        if ((state->flags & 2) != 0) {
            MODE_NAME = 0;
            APPLY_NAME(state, 0);
            MODE_NAME = 1;
            APPLY_NAME(state, 0);
            state->state = 3;
        }
        break;
    }
    MODE_NAME = savedMode;
}
