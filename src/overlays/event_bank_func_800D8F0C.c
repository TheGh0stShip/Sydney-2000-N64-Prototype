typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct {
    s8 kind;
    u8 pad1;
    s16 h2;
    float f4;
    s8 b8;
    u8 pad9;
    u8 bA;
    u8 padB;
} Slot;

extern u8 *D_800FC270;
extern void func_8009BFE8(s32, Slot *, s32, float);

#define B(o) (*(u8 *)(obj + (o)))
#define LIST(i) (*(Slot **)(obj + ((i) << 2) + 0x608C))

void func_8007439C(u8 *obj, u8 idx, float v)
{
    Slot *e;
    Slot *s;
    Slot *cur;
    u8 i;

    if (B(0x615) == 5) {
        return;
    }
    e = (Slot *)(D_800FC270 + 0xA10) + (B(0x60E) * B(0x613) + idx);
    s = e;
    e->f4 = v;
    if (v != -1.0f) {
        s16 h;
        if (v < 15.4f) {
            if (7.45f < v) {
                h = (15.4f - v) * 188.679245f;
            } else {
                h = 1500;
            }
        } else {
            h = 0;
        }
        s->h2 = h;
    } else {
        e->h2 = -1;
    }
    i = 0;
    while (1) {
        if (i >= B(0x613)) break;
        cur = LIST(i);
        if (cur == 0) {
            LIST(i) = s;
            break;
        }
        if (s->f4 != -1.0f) {
            if (s->f4 < cur->f4 || cur->f4 == -1.0f) {
                LIST(i) = s;
                s = cur;
            } else if (s->f4 == cur->f4) {
                s16 h;
                s->f4 = s->f4 + 0.0017f;
                if (s->f4 < 15.4f) {
                    if (7.45f < s->f4) {
                        h = (15.4f - s->f4) * 188.679245f;
                    } else {
                        h = 1500;
                    }
                } else {
                    h = 0;
                }
                s->h2 = h;
            }
        }
        i++;
    }
    for (i = 0; i < B(0x613); i++) {
        if (LIST(i) != 0) {
            LIST(i)->b8 = i;
        }
    }
    if (e->f4 != -1.0f) {
        func_8009BFE8(0, e, B(0x615), e->f4);
    }
}
