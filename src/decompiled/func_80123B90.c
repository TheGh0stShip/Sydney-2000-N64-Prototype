#include "sydney_types.h"

/* Looks up an entry by id; resets the matching sub-object (id 0x1F also resets the 0xD8 block). */
typedef struct Entry {
    u8 unk_00[0xDC];
} Entry;

typedef struct Obj {
    u8 unk_00[0xD8];
    u8 unk_D8[0x650 - 0xD8];
    Entry entries[(0xEE8 - 0x650) / 0xDC];
    u8 pad[0xEE8 - 0x650 - ((0xEE8 - 0x650) / 0xDC) * 0xDC];
    u16 ids[15];
    u8 count;
} Obj;

void func_800D29E0(void *p);
void func_800B2158(Entry *e, s32 arg);

void func_80123B90(Obj *obj, u16 id) {
    u8 i;

    if (id == 0x1F) {
        func_800D29E0(obj->unk_D8);
    }
    for (i = 0; i < obj->count; i++) {
        if (obj->ids[i] == id) {
            func_800B2158(&obj->entries[i], 0);
            break;
        }
    }
}
