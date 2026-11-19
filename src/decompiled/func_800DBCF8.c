#include "sydney_types.h"

/* Builds (once) a framed box around a rectangle: a filled background, top and bottom bars and two side bars, then shows all five parts. */
typedef struct Rect {
    u8 pad00[0xC];
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Rect;

struct Part;

typedef struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(struct Part *self);
} VEntry;

typedef struct Part {
    u8 pad00[0xB4];
    VEntry *vtbl;
    u8 padB8[8];
    s32 flags;
    void *sprite;
    u8 padC8;
    u8 unk_C9;
    u8 padCA[0xA];
} Part;

typedef struct Box {
    u8 pad000[0x1E8];
    Part parts[5];
} Box;

typedef struct View {
    u8 pad[0xD8];
    s32 layer;
} View;

extern View *D_800F63F0;

void func_800191E0(void **spr, u32 color);
void func_8001A1D8(void **spr, f32 x0, f32 y0, f32 x1, f32 y1);
void func_8001A210(void **spr, f32 a, f32 b, f32 sx, f32 sy, s32 f);
void func_8001A330(void **spr, s32 a);
void func_800ADC54(Part *p, s32 mask);

#define MAKE_RECT(p, x0, y0, x1, y1, color) \
    spr = NULL; \
    func_8001A330(&spr, 0xFFFF); \
    func_8001A1D8(&spr, x0, y0, x1, y1); \
    func_8001A210(&spr, 0.0f, 0.0f, 1.0f, 1.0f, 0); \
    func_800191E0(&spr, color); \
    (p)->unk_C9 = 0; \
    (p)->flags |= 0x20000; \
    func_800ADC54(p, 1 << D_800F63F0->layer); \
    (p)->sprite = spr

void func_800DBCF8(Box *box, Rect *r) {
    void *spr;
    Part *p;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    u8 i;

    spr = NULL;
    if (box->parts[0].sprite != NULL) {
        return;
    }
    p = &box->parts[0];
    x0 = r->x;
    x1 = x0 + r->w;
    y0 = r->y;
    y1 = y0 + r->h;
    MAKE_RECT(p, x0, y0, x1, y1, 0x60606060);
    y1 = y0;
    y0 = y0 - 1.0f;
    p = &box->parts[1];
    MAKE_RECT(p, x0, y0, x1, y1, 0xFF000000);
    p = &box->parts[2];
    y0 = r->y;
    y0 += r->h;
    y1 = y0 + 1.0f;
    MAKE_RECT(p, x0, y0, x1, y1, 0xFF000000);
    x1 = r->x;
    x0 = x1 - 2.0f;
    y0 = (f32) r->y - 1.0f;
    y1 = y0 + r->h + 1.0f + 1.0f;
    p = &box->parts[3];
    MAKE_RECT(p, x0, y0, x1, y1, 0xFF000000);
    x0 = r->x;
    x0 += r->w;
    y0 = (f32) r->y - 1.0f;
    x1 = x0 + 2.0f;
    y1 = y0 + r->h + 1.0f + 1.0f;
    p = &box->parts[4];
    MAKE_RECT(p, x0, y0, x1, y1, 0xFF000000);
    i = 0;
    while (1) {
        if (i >= 5) {
            break;
        }
        p = &box->parts[i];
        i++;
        p->flags |= 2;
        p->vtbl[8].fn((Part *) ((u8 *) p + p->vtbl[8].delta));
    }
}
