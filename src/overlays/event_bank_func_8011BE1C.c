typedef struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *self, int flags);
} VEntry;

typedef struct Widget280 {
    char pad00[0xB4];
    VEntry *vtable;
    char padB8[0x118 - 0xB8];
} Widget280;

typedef struct Widget284 {
    char pad00[0xB4];
    VEntry *vtable;
    char padB8[0x11C - 0xB8];
} Widget284;

typedef struct Widget268 {
    char pad00[0xB4];
    VEntry *vtable;
    char padB8[0x10C - 0xB8];
} Widget268;

typedef struct Label {
    char pad00[0xB4];
    VEntry *vtable;
    char padB8[0x120 - 0xB8];
} Label;

typedef struct Screen {
    char pad000[0xB4];
    VEntry *vtable;
    Widget284 icons[2];
    Widget280 buttons[2];
    Widget268 sliders[2];
    Label title;
    Widget280 tabs[2];
} Screen;

extern VEntry D_80080A50[];
extern VEntry D_80080C20[];

extern void func_800ADE84(void *obj, int flags);
extern void func_800AC3A4(Screen *screen, int flags);

#define DESTROY_ARRAY(arr, n, T)                                            \
    if ((arr) != 0) {                                                       \
        T *p = &(arr)[n];                                                   \
        if ((arr) != p) {                                                   \
            T *begin = (arr);                                               \
            do {                                                            \
                p--;                                                        \
                p->vtable[1].fn((char *)p + p->vtable[1].delta, 2);         \
            } while (begin != p);                                           \
        }                                                                   \
    }

void func_8011BE1C(Screen *screen, int flags) {
    screen->vtable = D_80080A50;
    DESTROY_ARRAY(screen->tabs, 2, Widget280)
    {
        Label *title = &screen->title;
        title->vtable = D_80080C20;
        func_800ADE84(title, 2);
    }
    DESTROY_ARRAY(screen->sliders, 2, Widget268)
    DESTROY_ARRAY(screen->buttons, 2, Widget280)
    DESTROY_ARRAY(screen->icons, 2, Widget284)
    func_800AC3A4(screen, flags);
}
