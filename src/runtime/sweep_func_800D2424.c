typedef struct {
    unsigned short width;
    char pad[10];
    int tex;
} Glyph;

typedef struct {
    char pad[0x40];
    Glyph glyph[1];
} GlyphSet;

typedef struct {
    char pad[8];
    GlyphSet *glyphs;
} Font;

typedef struct {
    char pad[0x40];
    float x;
    float y;
    int z;
} Sprite;

extern Font *D_800FCB44;

static __inline__ void sprite_pos(Sprite *s, float x, float y)
{
    s->x = x;
    s->y = y;
    s->z = 0;
}

void func_800D2424(unsigned char *o, unsigned char side, signed char n)
{
    Glyph *hi;
    Glyph *lo;
    int w;
    short a;
    short b;

    if (side == 0) {
        *(int *)(o + 0x41C) = *(int *)(o + 0xAD4);
    } else {
        *(int *)(o + 0x41C) = *(int *)(o + 0xAD0);
    }
    if (n > 0) {
        signed char tens = n / 10;
        GlyphSet *base = D_800FCB44->glyphs;
        hi = &base->glyph[tens];
        lo = &base->glyph[(signed char)(n - tens * 10)];
    } else {
        lo = &D_800FCB44->glyphs->glyph[64];
        hi = lo;
    }
    *(int *)(o + 0x4F0) = hi->tex;
    *(int *)(o + 0x5C4) = lo->tex;
    w = (hi->width + lo->width + 1) >> 1;
    a = 23 - w;
    b = w - (lo->width - 23);
    sprite_pos((Sprite *)(o + 0x48C), a, 2.0f);
    sprite_pos((Sprite *)(o + 0x560), b, 2.0f);
}
