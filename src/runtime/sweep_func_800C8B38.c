typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

typedef struct {
    unsigned char pad0[20];
    unsigned char matrix[68];
    float scale;
    unsigned char pad1[88];
    unsigned char *vtable;
    unsigned char pad2[8];
    int flags;
    int sprite;
    unsigned char pad3[12];
    short state;
    unsigned char pad4[10];
} Beam;

typedef struct {
    unsigned char header[616];
    Beam beams[6];
} Gym;

int func_8000EB20(char *name);
void func_80013208(int *handle, float a, float b, int id, int mode);
void func_800ADC54(void *obj, int arg);
void func_800AD4E0(void *mtx, float angle, int axis);

void func_800C8B38(Gym *object)
{
    unsigned char i;
    int handle = 0;

    i = 0;
    while (1) {
        Beam *beam;
        Method *m;
        int id;

        if (i >= 6) {
            break;
        }
        beam = &object->beams[i];
        handle = 0;
        id = func_8000EB20("VGYM_BEAM");
        func_80013208(&handle, 1.6383498907089233f, 16.383499145507812f, id & 0xFFFF, 2);
        beam->sprite = handle;
        func_800ADC54(beam, 1);
        beam->flags |= 0x12;
        m = (Method *)(beam->vtable + 64);
        m->fn((unsigned char *)beam + m->offset);
        beam->scale = -32.767f;
        func_800AD4E0(beam->matrix, 1.5707961320877075f, 3);
        object->beams[i].state = 0;
        i++;
    }
}
