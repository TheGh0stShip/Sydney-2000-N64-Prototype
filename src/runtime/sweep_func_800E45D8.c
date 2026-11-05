/* Destructor: reinstall this class's vtable, destroy the trailing member,
 * then the two embedded object arrays in reverse order (virtual slot 1,
 * flag 2), and chain to the base-class destructor. */
typedef struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self, int flags);
} VEntry;

typedef struct Panel {
    char pad[180];
    VEntry *vtbl;
    char rest[1764 - 184];
} Panel;

typedef struct Item {
    char pad[180];
    VEntry *vtbl;
    char rest[212 - 184];
} Item;

typedef struct Obj {
    char pad0[180];
    void *vtbl;
    char pad1[4032 - 184];
    Panel panels[4];
    Item items[36];
    char member[1];
} Obj;

extern char D_8008B788[];
extern void func_800ADE84(void *member, int flags);
extern void func_800AC3A4(Obj *o, int flags);

void func_800E45D8(Obj *o, int flags)
{
    Item *item;
    Panel *panel;

    o->vtbl = D_8008B788;
    func_800ADE84(o->member, 2);
    if (o->items != 0) {
        item = o->items + 36;
        while (o->items != item) {
            item--;
            item->vtbl[1].fn((char *)item + item->vtbl[1].delta, 2);
        }
    }
    if (o->panels != 0) {
        panel = o->panels + 4;
        while (o->panels != panel) {
            panel--;
            panel->vtbl[1].fn((char *)panel + panel->vtbl[1].delta, 2);
        }
    }
    func_800AC3A4(o, flags);
}
