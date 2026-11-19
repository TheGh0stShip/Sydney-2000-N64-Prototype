#include "sydney_types.h"

/* Option-menu input: moves the cursor, cycles the selected slot's kind (skipping kinds already used), or steps its value within the kind's range. */
typedef struct Slot { s16 kind; s16 value; } Slot;
typedef struct Menu {
    u8 pad00[0xB9];
    u8 last;
    u8 padBA[0xE];
    u8 used;
    u8 padC9[0x34];
    s8 cursor;
    s8 mode;
    u8 padFF;
    s16 lo;
    s16 hi;
    Slot slots[1];
} Menu;

void func_800A4E30(Menu *);
void func_800A4F10(Menu *);

void func_800A4968(Menu *m, s8 delta) {
    u8 old;

    switch (m->mode) {
    case 0:
        m->cursor += delta;
        if (m->cursor > m->last) {
            m->cursor = 0;
        }
        if (m->cursor < 0) {
            m->cursor = m->last;
        }
        func_800A4E30(m);
        break;
    case 1:
        old = m->slots[m->cursor].kind;
        m->slots[m->cursor].kind += delta;
        if (m->slots[m->cursor].kind < 0) {
            m->slots[m->cursor].kind = 6;
        }
        if (m->slots[m->cursor].kind >= 7) {
            m->slots[m->cursor].kind = 0;
        }
        while ((m->used >> m->slots[m->cursor].kind) & 1) {
            m->slots[m->cursor].kind += delta;
            if (m->slots[m->cursor].kind < 0) {
                m->slots[m->cursor].kind = 6;
            }
            if (m->slots[m->cursor].kind >= 7) {
                m->slots[m->cursor].kind = 0;
            }
        }
        m->used &= ~(1 << old);
        m->used |= 1 << m->slots[m->cursor].kind;
        switch ((u8) m->slots[m->cursor].kind) {
        case 0:
            m->lo = -1;
            m->hi = -1;
            break;
        case 1:
            m->lo = 0;
            m->hi = 0x17;
            break;
        case 2:
            m->lo = 0x18;
            m->hi = 0x2A;
            break;
        case 3:
            m->lo = 0x2B;
            m->hi = 0x39;
            break;
        case 4:
            m->lo = 0x3A;
            m->hi = 0x4A;
            break;
        case 5:
            m->lo = 0x4B;
            m->hi = 0x56;
            break;
        case 6:
            m->lo = 0x57;
            m->hi = 0x69;
            break;
        }
        m->slots[m->cursor].value = m->lo;
        func_800A4F10(m);
        break;
    case 2:
        if (m->slots[m->cursor].kind != 0) {
            m->slots[m->cursor].value += delta;
            if (m->slots[m->cursor].value > m->hi) {
                m->slots[m->cursor].value = m->lo;
            }
            if (m->slots[m->cursor].value < m->lo) {
                m->slots[m->cursor].value = m->hi;
            }
            func_800A4F10(m);
        }
        break;
    }
}
