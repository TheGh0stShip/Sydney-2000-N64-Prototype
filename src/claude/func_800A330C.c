/* Runtime-stage C reconstruction: rescale an object's gain triplet from the resident mixer settings. */
typedef struct {
    unsigned char pad[0xD5A];
    unsigned char gainY;  /* 0xD5A */
    unsigned char gainX;  /* 0xD5B */
    unsigned char gainZ;  /* 0xD5C */
} MixSettings;

typedef struct {
    char pad0[0x1C];
    int x;      /* 0x1C */
    int y;      /* 0x20 */
    int z;      /* 0x24 */
    char pad28[0x60 - 0x28];
    int busy;   /* 0x60 */
    int scale;  /* 0x64 */
    int outX;   /* 0x68 */
    int outY;   /* 0x6C */
    int outZ;   /* 0x70 */
} GainObject;

extern MixSettings *D_800FC270;

void func_800A330C(volatile GainObject *obj) {
    MixSettings *s;
    if (obj->busy) {
        obj->busy = 0;
        return;
    }
    s = D_800FC270;
    obj->busy = 1;
    obj->scale = s->gainX << 11;
    obj->outX = (obj->x * s->gainX) >> 4;
    obj->outY = (obj->y * s->gainY) >> 4;
    obj->outZ = (obj->z * s->gainZ) >> 4;
    obj->busy = 0;
}
