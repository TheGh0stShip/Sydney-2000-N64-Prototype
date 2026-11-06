/* Event-bank message handler: start/stop the crowd loop and drive the intro state. */
typedef struct {
    unsigned char pad0[0x2F0];
    unsigned char anim[0x2F80 - 0x2F0];
    int w2F80;
    unsigned char pad2F84[0x7AF0 - 0x2F84];
    unsigned char snd[0x7CAE - 0x7AF0];
    unsigned char state;
    unsigned char sub;
    unsigned char b7CB0;
    unsigned char pad7CB1[0x7CC0 - 0x7CB1];
    int w7CC0;
    unsigned char pad7CC4[4];
    int w7CC8;
    unsigned char pad7CCC[0x7CDE - 0x7CCC];
    unsigned char b7CDE;
    unsigned char pad7CDF[0x7CF8 - 0x7CDF];
    int loop;
} MsgOwner;

typedef struct {
    unsigned char pad0[0xC];
    unsigned int which;
    unsigned int kind;
} MsgArg;

typedef struct {
    unsigned char pad0[0x68];
    int volume;
} SndBank;

extern SndBank D_800F1AE0;
extern char D_8007737C[];
extern char D_800773A4[];
extern char D_800773CC[];
extern int func_8001D4B8(SndBank *b, int id, int a, int c);
extern void func_8001D640(SndBank *b, int h, int a);
extern void func_8001D5D8(SndBank *b, int h, int vol, int t, int a, int c);
extern void func_800A9BE8(void *p, int n);
extern void func_800AC25C(MsgOwner *p, int a, int b, int c);
extern void func_800D33A0(void *p, char *name, int a, int b);
extern void func_80076C64(MsgOwner *p, int a, int b, int c);

extern void *D_80071060[];

void func_800A2A68(MsgOwner *p, MsgArg *arg)
{
    int h;
    int m;

    if (p->state == 14) {
        return;
    }
    switch (arg->kind) {
    case 19:
        func_800A9BE8(p->snd, 4);
        func_800AC25C(p, 95, 17, 0);
        p->b7CDE = 0;
        return;
    case 0:
        if (p->loop != -1) {
            return;
        }
        if (p->sub == 4) {
            return;
        }
        m = 32767;
        h = func_8001D4B8(&D_800F1AE0, 110, 0, -1);
        func_8001D640(&D_800F1AE0, h, 0);
        func_8001D5D8(&D_800F1AE0, h, (D_800F1AE0.volume * m) >> 15, 60, 0, 0);
        p->loop = h;
        return;
    case 5:
        {
            static void *const unused_tbl[] = { &&L2, &&L0, &&L5 };
            unsigned int i = p->sub;
            if (i >= 6) goto done5;
            goto *D_80071060[i];
        }
L2:
        p->w7CC0 = 0x1C200;
        p->w7CC8 = 1;
        p->w2F80 = 1;
        func_800D33A0(p->anim, D_8007737C, 1, -1);
        func_80076C64(p, 27, 0, 0);
L0:
        func_800A9BE8(p->snd, 4);
        goto done5;
L5:
        func_800A9BE8(p->snd, 7);
done5:
        p->state = 5;
        return;
    case 22:
        if (p->sub == 5) {
            func_800A9BE8(p->snd, 8);
        } else {
            func_800A9BE8(p->snd, 11);
        }
        if (p->b7CB0 != 4) {
            SndBank *b = &D_800F1AE0;
            int l = p->loop;
            func_8001D5D8(b, l, 0, 30, 1, 0);
        }
        if (p->sub != 2) {
            return;
        }
        if (arg->which < 2) {
            p->w7CC0 = 0x18600;
            p->w7CC8 = 1;
            p->w2F80 = 1;
        }
        if (arg->which == 0) {
            func_800D33A0(p->anim, D_800773A4, 1, -1);
            func_80076C64(p, 28, 0, 0);
        } else if (arg->which == 1) {
            func_800D33A0(p->anim, D_800773CC, 1, -1);
            func_80076C64(p, 29, 0, 0);
        }
        return;
    }
}
