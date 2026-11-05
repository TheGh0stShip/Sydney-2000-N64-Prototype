extern void func_800ADDA4(void *object, int arg);
extern void func_800AC3A4(void *object, int arg);
extern unsigned char D_80088828[];
extern unsigned char D_80086598[];

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

void func_800C7B2C(unsigned char *object, int arg)
{
    Part *parts;
    Part *p;
    unsigned char *sub;

    *(void **)(object + 180) = D_80088828;
    sub = object + 1512;
    *(void **)(sub + 180) = D_80086598;
    func_800ADDA4(sub, 2);
    sub = object + 1292;
    *(void **)(sub + 180) = D_80086598;
    func_800ADDA4(sub, 2);
    parts = (Part *)(object + 184);
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
