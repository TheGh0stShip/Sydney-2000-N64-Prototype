/* Destructor of the top-level scene object: reinstall each class vtable on
 * the way down, destroy every embedded member and object array in reverse
 * declaration order, then chain to the base-class destructor. */
typedef struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self, int flags);
} VEntry;

typedef struct Base {
    char pad[180];
    void *vtbl;
} Base;

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

typedef struct Lane {
    char pad[180];
    VEntry *vtbl;
    char rest[232 - 184];
} Lane;

typedef struct Menu {
    char pad[180];
    void *vtbl;
    char rest[220 - 184];
} Menu;

typedef struct Board {
    char pad0[180];
    void *vtbl;
    char pad1[4032 - 184];
    Panel panels[4];
    Item items[36];
    char member[388];
} Board;

typedef struct Meter {
    char pad0[180];
    void *vtbl;
    char pad1[192 - 184];
    Base gauge;
    char pad2[380 - 192 - 184];
    char member[1];
} Meter;

typedef struct Ticker {
    char pad0[180];
    void *vtbl;
    char pad1[260 - 184];
    char member[1];
} Ticker;

typedef struct Scene {
    char pad0[180];
    void *vtbl;
    char pad1[260 - 184];
    char banner[648 - 260];
    Base title;
    char pad2[840 - 648 - 184];
    Meter meter;
    char pad3[3412 - 840 - sizeof(Meter)];
    Board board;
    Base status;
    char pad4[22708 - 22520 - 184];
    Ticker ticker;
    char pad5[23368 - 22708 - sizeof(Ticker)];
    char camera[24632 - 23368];
    Lane lanes[13];
    char pad6[27656 - 27648];
    char hud[27876 - 27656];
    Menu menus[3];
    char pad7[28540 - 27876 - 3 * 220];
    Base cursor;
} Scene;

extern char D_8008C078[];
extern char D_8008C0B8[];
extern char D_80086598[];
extern char D_80086B30[];
extern char D_8008BC48[];
extern char D_8008B788[];
extern char D_8008B118[];
extern char D_8008B1D0[];
extern char D_80085DB8[];
extern void func_800BA1B4(void *obj, int flags);
extern void func_800ADDA4(void *obj, int flags);
extern void func_800ADE84(void *obj, int flags);
extern void func_800C062C(void *obj, int flags);
extern void func_800AE4D8(void *obj, int flags);
extern void func_800AC3A4(void *obj, int flags);

static __inline__ void Cursor_dtor(Base *p, int flags)
{
    p->vtbl = D_8008C0B8;
    func_800BA1B4(p, flags);
}

static __inline__ void Menu_dtor(Menu *p, int flags)
{
    p->vtbl = D_80086598;
    func_800ADDA4(p, flags);
}

static __inline__ void Ticker_dtor(Ticker *p, int flags)
{
    p->vtbl = D_80086B30;
    func_800AE4D8(p->member, 2);
    func_800AC3A4(p, flags);
}

static __inline__ void Status_dtor(Base *p, int flags)
{
    p->vtbl = D_8008BC48;
    func_800AC3A4(p, flags);
}

static __inline__ void Board_dtor(Board *b, int flags)
{
    Item *item;
    Panel *panel;

    b->vtbl = D_8008B788;
    func_800ADE84(b->member, 2);
    if (b->items != 0) {
        item = b->items + 36;
        while (b->items != item) {
            item--;
            item->vtbl[1].fn((char *)item + item->vtbl[1].delta, 2);
        }
    }
    if (b->panels != 0) {
        panel = b->panels + 4;
        while (b->panels != panel) {
            panel--;
            panel->vtbl[1].fn((char *)panel + panel->vtbl[1].delta, 2);
        }
    }
    func_800AC3A4(b, flags);
}

static __inline__ void Gauge_dtor(Base *p, int flags)
{
    p->vtbl = D_8008B1D0;
    func_800AC3A4(p, flags);
}

static __inline__ void Meter_dtor(Meter *m, int flags)
{
    m->vtbl = D_8008B118;
    func_800ADE84(m->member, 2);
    Gauge_dtor(&m->gauge, 2);
    func_800AC3A4(m, flags);
}

static __inline__ void Title_dtor(Base *p, int flags)
{
    p->vtbl = D_80085DB8;
    func_800AC3A4(p, flags);
}

void func_800E84D0(Scene *o, int flags)
{
    Lane *lane;

    o->vtbl = D_8008C078;
    Cursor_dtor(&o->cursor, 2);
    Menu_dtor(&o->menus[2], 2);
    Menu_dtor(&o->menus[1], 2);
    Menu_dtor(&o->menus[0], 2);
    func_800ADE84(o->hud, 2);
    if (o->lanes != 0) {
        lane = o->lanes + 13;
        while (o->lanes != lane) {
            lane--;
            lane->vtbl[1].fn((char *)lane + lane->vtbl[1].delta, 2);
        }
    }
    func_800C062C(o->camera, 2);
    Ticker_dtor(&o->ticker, 2);
    Status_dtor(&o->status, 2);
    Board_dtor(&o->board, 2);
    Meter_dtor(&o->meter, 2);
    Title_dtor(&o->title, 2);
    func_800AE4D8(o->banner, 2);
    func_800AC3A4(o, flags);
}
