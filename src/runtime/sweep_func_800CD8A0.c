extern void func_800ADDA4(void *object, int arg);
extern void func_800AC334(void *object);
extern void func_800CD65C(void *object);
extern unsigned char D_800899F8[];

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

void func_800CD8A0(unsigned char *object, int arg)
{
    Part *parts;
    Part *p;

    *(void **)(object + 180) = D_800899F8;
    func_800AC334(object + 212);
    func_800CD65C(object);
    parts = (Part *)(object + 484);
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
    func_800ADDA4(object + 212, 2);
    func_800ADDA4(object, arg);
}
