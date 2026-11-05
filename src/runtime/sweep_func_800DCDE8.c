extern void func_800AC3A4(void *object, int arg);
extern unsigned char D_8008AE90[];

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

void func_800DCDE8(unsigned char *object, int arg)
{
    Part *parts;
    Part *p;

    *(void **)(object + 180) = D_8008AE90;
    parts = (Part *)(object + 488);
    if (parts != 0) {
        p = parts + 5;
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
