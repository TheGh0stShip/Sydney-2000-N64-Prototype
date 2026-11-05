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
    unsigned char header[188];
    Part parts[4];
} Owner;

void func_8001A248(void *sound);
void func_800ADC1C(void *object);

void func_800C04DC(Owner *owner)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (owner->parts[i].sound != 0) {
            Part *p = &owner->parts[i];
            Method *m = (Method *)(owner->parts[i].vtable + 72);

            m->fn((unsigned char *)p + m->offset);
            if (owner->parts[i].sound != 0) {
                func_8001A248(&p->sound);
                owner->parts[i].sound = 0;
            }
        }
    }
    if (*(int *)((unsigned char *)owner + 1232) != 0) {
        func_800ADC1C((unsigned char *)owner + 1036);
    }
}
