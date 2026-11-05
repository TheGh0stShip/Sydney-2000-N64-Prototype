typedef struct Buttons {
    unsigned char held;
    unsigned char changed;
    unsigned char released;
    unsigned char pressed;
    unsigned char pad4;
    unsigned char prev;
} Buttons;

void func_800BC07C(Buttons *b, unsigned char v) {
    b->held = v;
    b->changed = b->prev ^ b->held;
    b->pressed = b->held & b->changed;
    b->released = b->prev & b->changed;
    b->prev = b->held;
}
