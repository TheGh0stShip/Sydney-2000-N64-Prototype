typedef struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *self, int flags);
} VEntry;

typedef struct Sprite {
    char pad00[0xB4];
    VEntry *vtable;
    char padB8[0xD4 - 0xB8];
} Sprite;

typedef struct Board {
    char pad000[0xB4];
    VEntry *vtable;
    char pad0B8[0x1B8 - 0xB8];
    Sprite cells[16];
    Sprite markers[2];
} Board;

extern VEntry D_80080BD8[];

extern void func_8008204C(Board *board);
extern void func_80082044(Board *board);
extern void func_800BA1B4(Board *board, int flags);

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

void func_8011F9DC(Board *board, int flags) {
    board->vtable = D_80080BD8;
    func_8008204C(board);
    func_80082044(board);
    DESTROY_ARRAY(board->markers, 2, Sprite)
    DESTROY_ARRAY(board->cells, 16, Sprite)
    func_800BA1B4(board, flags);
}
