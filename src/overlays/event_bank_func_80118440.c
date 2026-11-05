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
    char pad2DC[0x2F8 - 0x2DC];
} Panel;

typedef struct Menu {
    char pad000[0xC4];
    char header[0x2E0 - 0xC4];
    char body[0xCCC - 0x2E0];
    unsigned int panelCount;
    char padCD0[0xCD4 - 0xCD0];
    Panel *panels;
} Menu;

extern void *D_8007EBD0;
extern void *D_8007EBD4;
extern VEntry D_80080A48[];
extern char D_800F2758[];

extern void func_800AA658(void *pool, void *slot);
extern void func_800AC308(void *p);
extern void func_800ADE84(void *p, int flags);
extern void func_800E79A8(void *p);
extern void func_800AC334(void *p);
extern void func_800E5788(void *p);
extern void func_800A6334(Menu *menu);

static inline void panel_destroy(Panel *panel) {
    panel->vtable = D_80080A48;
    if (panel->parts != 0) {
        Part *p = &panel->parts[2];
        if (panel->parts != p) {
            Part *begin = panel->parts;
            do {
                p--;
                p->vtable[1].fn((char *)p + p->vtable[1].delta, 2);
            } while (begin != p);
        }
    }
    func_800ADE84(panel, 2);
}

void func_80118440(Menu *menu) {
    unsigned int i;

    if (D_8007EBD4 != 0) {
        func_800AA658(D_800F2758, &D_8007EBD4);
    }
    if (menu->panels != 0) {
        i = 0;
        for (;;) {
            VEntry *vt;

            if (i >= menu->panelCount) {
                break;
            }

            func_800AC308(&menu->panels[i]);
            vt = menu->panels[i].vtable;
            ((void (*)(void *))vt[3].fn)((char *)&menu->panels[i] + vt[3].delta);
            panel_destroy(&menu->panels[i]);
            i++;
        }
        func_800AA658(D_800F2758, &menu->panels);
    }
    if (D_8007EBD0 != 0) {
        func_800AA658(D_800F2758, &D_8007EBD0);
    }
    func_800E79A8(menu->body);
    func_800AC334(menu->body);
    func_800E5788(menu->header);
    func_800AC334(menu->header);
    func_800A6334(menu);
}
