extern void func_800ADDA4(void *object, int arg);
extern void func_800AC3A4(void *object, int arg);
extern unsigned char D_80088298[];

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

void func_800C062C(unsigned char *object, int arg)
{
    Part *parts;
    Part *p;

    *(void **)(object + 180) = D_80088298;
    func_800ADDA4(object + 1036, 2);
    parts = (Part *)(object + 188);
    if (parts != 0) {
        p = parts + 4;
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
