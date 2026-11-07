typedef struct { char pad[2072]; float scale; char pad2[32]; int handle; } Obj;
extern void func_800191E0(int *, unsigned int);
void func_8009D474(Obj *o, float amount, int fade, float level)
{
    int handle;
    float scaled;
    scaled = 586.0f;
    handle = o->handle;
    scaled = amount * scaled;
    if (fade) {
        unsigned int v = level * 255.0f;
        int *h = &handle;
        unsigned int c = ~v & 0xFF;
        func_800191E0(h, c | (c << 8) | 0xFF0000);
        func_800191E0(h, c | (c << 8) | 0x80FF0000);
    } else {
        func_800191E0(&handle, 0xFFFFFF);
        func_800191E0(&handle, 0x80FFFFFF);
    }
    o->scale = scaled;
}
