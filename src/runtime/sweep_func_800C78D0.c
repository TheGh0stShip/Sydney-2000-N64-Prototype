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

typedef struct {
    unsigned char header[184];
    Part parts[5];
} Owner;

void func_8001A248(void *sound);
void func_800B35F0(void *object);
void func_800AC334(void *object);

void func_800C78D0(unsigned char *object)
{
    unsigned char i;
    unsigned char *sub;

    for (i = 0; i < 5; i++) {
        Part *p;
        Method *m;

        p = &((Part *)(object + 184))[i];
        if (((Owner *)object)->parts[i].sound != 0) {
            func_8001A248(&p->sound);
        }
        m = (Method *)(p->vtable + 24);
        m->fn((unsigned char *)p + m->offset);
        m = (Method *)(p->vtable + 72);
        m->fn((unsigned char *)p + m->offset);
    }
    sub = object + 1292;
    func_800B35F0(sub);
    func_800AC334(sub);
    sub = object + 1512;
    func_800B35F0(sub);
    func_800AC334(sub);
}
