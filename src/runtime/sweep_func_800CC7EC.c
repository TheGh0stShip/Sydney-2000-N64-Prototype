typedef struct { char pad[0xC]; float v; } Axis;
typedef struct { char pad[0x68]; int vol; } Snd;
typedef struct {
    char pad0[0xD4];
    char ctl[0xE0 - 0xD4];
    float outx;
    float outy;
    float kx;
    float ky;
    char padf0[0x1C4 - 0xF0];
    unsigned char off;
    char pad1c5[3];
    float vel;
    float acc;
    float pos;
    int handle;
} Throttle;

extern Snd D_800F1AE0;
extern Axis *func_8001A154(char *c);
extern Axis *func_8001A148(char *c);
extern int func_8001D4B8(Snd *s, int id, int a, int b);
extern void func_8001D640(Snd *s, int h, int vol);
extern void func_8001A188(char *c, float v, float w);
extern void func_8001A1B0(char *c, float v, float w);

void func_800CC7EC(Throttle *t)
{
    Axis *ax;
    Axis *ay;
    unsigned int n;
    int vol;
    int h;

    if (t->off) {
        return;
    }
    ax = func_8001A154(t->ctl);
    ay = func_8001A148(t->ctl);
    t->pos += t->vel;
    t->vel += t->acc;
    if (t->pos > 1000.0f) {
        t->vel = -t->vel;
        t->pos = 1000.0f;
    }
    if (t->pos < 0.0f) {
        t->vel = 0.0f;
        t->pos = 0.0f;
    }
    t->outx = t->pos * t->kx;
    t->outy = t->pos * t->ky;
    n = (t->pos + t->pos) / 100.0f;
    vol = (n * 32767) / 100;
    h = func_8001D4B8(&D_800F1AE0, 203, 0, -1);
    func_8001D640(&D_800F1AE0, h, (vol * D_800F1AE0.vol) >> 15);
    t->handle = h;
    func_8001A188(t->ctl, t->outx, ax->v);
    func_8001A1B0(t->ctl, t->outy, ay->v);
}
