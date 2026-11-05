typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

typedef struct {
    unsigned char data[180];
    unsigned char *vtable;
    unsigned char pad[12];
    int sound;
    unsigned char rest[12];
} Part;

extern Part D_80101960[8];
extern int D_800F40F0;
extern int D_800F40F4;

void func_8001A248(void *sound);

void func_800C4008(void)
{
    unsigned char i;

    for (i = 0; i < 8; i++) {
        Part *p = &D_80101960[i];
        Method *m;

        if (p->sound != 0) {
            m = (Method *)(p->vtable + 72);
            m->fn((unsigned char *)p + m->offset);
            m = (Method *)(p->vtable + 24);
            m->fn((unsigned char *)p + m->offset);
            func_8001A248(&D_80101960[i].sound);
            p->sound = 0;
        }
    }
    if (D_800F40F0 != 0) {
        func_8001A248(&D_800F40F0);
        D_800F40F0 = 0;
    }
    if (D_800F40F4 != 0) {
        func_8001A248(&D_800F40F4);
        D_800F40F4 = 0;
    }
}
