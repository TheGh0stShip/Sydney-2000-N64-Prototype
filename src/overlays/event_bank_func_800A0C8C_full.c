typedef struct EventEntry {
    unsigned char kind;
    unsigned char arg;
    short timer;
    char pad4[8];
} EventEntry;

typedef struct EventBank {
    char pad0[2572];
    unsigned char count;
    char pad2573[3];
    EventEntry entries[1];
} EventBank;

extern EventBank *D_800FC270;
extern void func_8009A828(char *buf, int a, int b);
extern float func_80072F18(void *o, char *buf);
extern void func_800732AC(void *o, float f);

void func_800A0C8C(unsigned char *self)
{
    char buf[24];
    EventBank *bank = D_800FC270;
    EventEntry *e = &bank->entries[self[24038]];
    int t = (signed char)e->kind;
    unsigned char c = e->kind;
    int v;
    float f;

    if (t != 8) {
        {
            unsigned char *p = (unsigned char *)bank;
            p += t * 60;
            v = p[0x20];
        }
    } else {
        v = 3;
    }
    if (v != 1) {
        func_8009A828(buf, e->arg, (signed char)c);
        f = func_80072F18(self, buf);
    } else {
        f = *(float *)0x80071318;
    }
    func_800732AC(self, f);
    self[24124] = 2;
}
