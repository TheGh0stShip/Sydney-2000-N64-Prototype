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

typedef struct Dialog {
    char pad000[0xB4];
    VEntry *vtable;
    Widget284 icons[2];
    Widget268 sliders[2];
    Widget280 buttons[2];
} Dialog;

extern VEntry D_80080A10[];

extern void func_800AC3A4(Dialog *dialog, int flags);

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

void func_8011BD18(Dialog *dialog, int flags) {
    dialog->vtable = D_80080A10;
    DESTROY_ARRAY(dialog->buttons, 2, Widget280)
    DESTROY_ARRAY(dialog->sliders, 2, Widget268)
    DESTROY_ARRAY(dialog->icons, 2, Widget284)
    func_800AC3A4(dialog, flags);
}
