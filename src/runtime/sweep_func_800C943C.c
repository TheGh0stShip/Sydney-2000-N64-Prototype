extern void func_800ADE84(void *object, int arg);
extern void func_800AC308(void *object);
extern void func_800AC3A4(void *object, int arg);
extern unsigned char D_80088CE0[];

typedef struct {
    short offset;
    short pad;
    void (*fn)(void *, int);
} Method;

typedef struct {
    unsigned char data[180];
    unsigned char *vtable;
    unsigned char rest[28];
} Part;

typedef struct {
    unsigned char data[224];
} Slot;

void func_800C943C(unsigned char *object, int arg)
{
    Part *parts;
    Part *p;
    Slot *slots;
    Slot *s;

    *(void **)(object + 180) = D_80088CE0;
    func_800AC308(object + 1960);
    func_800ADE84(object + 1960, 2);
    slots = (Slot *)(object + 616);
    if (slots != 0) {
        s = slots + 6;
        if (slots != s) {
            Slot *first = slots;
            do {
                s--;
                func_800ADE84(s, 2);
            } while (first != s);
        }
    }
    parts = (Part *)(object + 188);
    if (parts != 0) {
        p = parts + 2;
        if (parts != p) {
            Part *first = parts;
            do {
                Method *m;
                p--;
                m = (Method *)(p->vtable + 8);
                m->fn((unsigned char *)p + m->offset, 2);
            } while (first != p);
        }
    }
    func_800AC3A4(object, arg);
}
