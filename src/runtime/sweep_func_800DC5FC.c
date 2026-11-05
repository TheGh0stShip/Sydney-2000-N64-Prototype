typedef struct {
    short offset;
    short pad;
    void (*func)(void *self);
} VtEntry;

typedef struct {
    char pad[72];
    VtEntry stop;
} Vtable;

typedef struct {
    char pad0[180];
    Vtable *vtable;
    int pad1[3];
    int handle;
    char pad2[12];
} Emitter;

typedef struct {
    char pad[488];
    Emitter emitters[5];
} EmitterBank;

extern void func_8001A248(int *handle);

void func_800DC5FC(EmitterBank *bank)
{
    unsigned char i;
    Emitter *emitter;

    for (i = 0; i < 5; i++) {
        if (bank->emitters[i].handle != 0) {
            emitter = &bank->emitters[i];
            func_8001A248(&emitter->handle);
            bank->emitters[i].vtable->stop.func((char *)emitter + bank->emitters[i].vtable->stop.offset);
            bank->emitters[i].handle = 0;
        }
    }
}
