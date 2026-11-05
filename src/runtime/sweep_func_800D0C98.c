typedef struct VtEntry {
    short delta;
    short index;
    void (*fn)(void *);
} VtEntry;

struct Item {
    char pad[180];
    VtEntry *vtbl;
};

struct Body {
    char pad[64];
    float x;
    float y;
    float z;
};

struct Screen {
    char pad[96];
    struct Body body;
    char pad2[212 - 96 - 76];
    struct Item icon;
    char pad3[1908 - 212 - 184];
    unsigned char state;
    char pad4[1924 - 1909];
    char text0[2364 - 1924];
    char text1[8644 - 2364];
    char timer0[212];
    char timer1[212];
    char timer2[212];
};

extern int D_80102870;
extern unsigned char D_800F4960[];
extern unsigned char D_800F4990[];
extern void func_800CE468(struct Item *, unsigned char, unsigned char, short, short, int);
extern void func_800ADC38(void *);
extern void func_800B31EC(int);
extern void func_800B360C(void *, void *);

void func_800D0C98(struct Screen *self, unsigned char icon, int mode, int restore)
{
    int *saved = &restore;
    struct Body *body;
    struct Item *item = &self->icon;

    func_800CE468(item, 0, icon, -65, 1, 2);
    self->icon.vtbl[8].fn((char *)item + self->icon.vtbl[8].delta);
    func_800ADC38(self->timer0);
    func_800ADC38(self->timer2);
    func_800ADC38(self->timer1);
    D_80102870 = mode;
    func_800B31EC(0);
    func_800B360C(self->text0, D_800F4960);
    D_80102870 = *saved;
    func_800B360C(self->text1, D_800F4990);
    body = &self->body;
    body->x = 442.0f;
    body->y = 210.0f;
    body->z = 0;
    self->state = 1;
}
