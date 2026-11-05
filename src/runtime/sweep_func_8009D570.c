/* Tear down a screen: release all loaded resources, run the layer's
 * virtual cleanup, then reset its state. */
typedef struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self);
} VEntry;

typedef struct Layer {
    char pad0[176];
    unsigned char active;
    char pad1[3];
    VEntry *vtbl;
} Layer;

extern void func_800CD840(void *p);
extern void func_8001A248(void *res);
extern void func_800ADC1C(Layer *layer);
extern void func_800D29E0(Layer *layer);

#define RES(off) (*(int *)(screen + (off)))
#define FREE_RES(off) if (RES(off) != 0) func_8001A248(screen + (off))

void func_8009D570(char *screen)
{
    Layer *layer;

    func_800CD840(screen + 2340);
    FREE_RES(200);
    FREE_RES(1896);
    FREE_RES(412);
    FREE_RES(624);
    FREE_RES(2108);
    FREE_RES(836);
    FREE_RES(1048);
    FREE_RES(1260);
    FREE_RES(1472);
    layer = (Layer *)(screen + 19088);
    layer->vtbl[3].fn((char *)layer + layer->vtbl[3].delta);
    layer->active = 0;
    func_800ADC1C(layer);
    func_800D29E0(layer);
}
