typedef struct { char pad[0xD4]; int colorA; int colorB; char pad2[0x10C - 0xDC]; unsigned char level; } Fader;
extern void func_80017778(void *dst, int rgba);

void func_800A13A0(Fader *f, float level) {
    f->level = (unsigned int)level;
    func_80017778(&f->colorA, f->level | (f->level << 8) | (f->level << 16) | 0xFF000000);
    func_80017778(&f->colorB, f->level | (f->level << 8) | (f->level << 16) | 0xFF000000);
}
