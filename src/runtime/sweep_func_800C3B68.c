/* Produce a terminated text pointer for the current entry: short strings are
 * terminated in place, long ones are copied (20 chars, scrolled) into the
 * object's local buffer. */
typedef struct Text {
    short *chars;
    int scroll;
    int len;
} Text;

typedef struct TextOwner {
    char pad[28];
    Text *text;
} TextOwner;

typedef struct Ref {
    short *p;
} Ref;

typedef struct Obj {
    char pad[220];
    TextOwner *owner;
    char pad2[812 - 224];
    short buf[21];
} Obj;

extern void func_800DB0F4(short *dst, short *src, int n);

Ref *func_800C3B68(Obj *o, Ref *out)
{
    Text *t;
    short *p;
    unsigned char off;

    t = o->owner->text;
    off = 0;
    if (t->scroll >= 20) {
        off = ((unsigned char *)t)[7] - 19;
    }
    if (t->len >= 20) {
        p = o->buf;
        func_800DB0F4(p, t->chars + off, 20);
        p[20] = 0;
        out->p = p;
    } else {
        p = t->chars;
        p[t->len] = 0;
        out->p = p;
    }
    return out;
}
