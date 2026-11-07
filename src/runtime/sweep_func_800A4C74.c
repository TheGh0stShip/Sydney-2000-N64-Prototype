typedef struct { char pad[0x68]; int vol; } Snd;
typedef struct { short val; short pad; } Ent;
typedef struct {
    char pad0[0xB9];
    unsigned char max;
    char padba[0xFD - 0xBA];
    signed char cur;
    signed char cnt;
    char padff;
    short lo;
    short hi;
    Ent ent[8];
} Menu;

extern Snd D_800F1AE0;
extern void func_800A54B0(Menu *m);
extern void func_800A4968(Menu *m, int a);
extern void func_800A5DDC(Menu *m, int a);
extern void func_800A4E30(Menu *m);
extern int func_8001D4B8(Snd *s, int id, int a, int b);
extern void func_8001D640(Snd *s, int h, int vol);

void func_800A4C74(Menu *m, signed char d)
{
    int h;

    if (m->cur == m->max) {
        if (d > 0) {
            func_800A54B0(m);
        } else {
            func_800A4968(m, 1);
        }
        return;
    }
    if (m->cnt == 1 && m->ent[m->cur].val == 0) {
        int k = 32767;
        h = func_8001D4B8(&D_800F1AE0, 89, 0, 1);
        func_8001D640(&D_800F1AE0, h, (D_800F1AE0.vol * k) >> 15);
        return;
    }
    m->cnt += d;
    if (m->cnt <= 0) {
        m->cnt = 1;
    }
    if (m->cnt == 1) {
        func_800A5DDC(m, 0);
        switch ((unsigned char)m->ent[m->cur].val) {
        case 0: m->lo = -1; m->hi = -1; break;
        case 1: m->lo = 0; m->hi = 23; break;
        case 2: m->lo = 24; m->hi = 42; break;
        case 3: m->lo = 43; m->hi = 57; break;
        case 4: m->lo = 58; m->hi = 74; break;
        case 5: m->lo = 75; m->hi = 86; break;
        case 6: m->lo = 87; m->hi = 105; break;
        }
    }
    if (m->cnt >= 3) {
        m->cnt = 0;
        func_800A4968(m, 1);
        func_800A5DDC(m, 1);
    }
    func_800A4E30(m);
}
