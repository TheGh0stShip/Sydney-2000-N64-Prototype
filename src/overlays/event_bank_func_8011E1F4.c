typedef struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *self, int flags);
} VEntry;

typedef struct Part {
    char pad00[0xB4];
    VEntry *vtable;
    char padB8[0x104 - 0xB8];
} Part;

typedef struct Panel {
    char pad00[0xB4];
    VEntry *vtable;
    char padB8[0xD4 - 0xB8];
    Part parts[2];
} Panel;

extern VEntry D_80080A48[];

extern void func_800ADE84(Panel *panel, int flags);

void func_8011E1F4(Panel *panel, int flags) {
    Part *begin;
    Part *p;

    panel->vtable = D_80080A48;
    if (panel->parts != 0) {
        p = &panel->parts[2];
        if (panel->parts != p) {
            begin = panel->parts;
            do {
                p--;
                p->vtable[1].fn((char *)p + p->vtable[1].delta, 2);
            } while (begin != p);
        }
    }
    func_800ADE84(panel, flags);
}
