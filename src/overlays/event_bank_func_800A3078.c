/* Event-bank mode step: react to pad edge bits, then run the per-state switch. */
typedef struct {
    unsigned char pad0[0x1AA];
    unsigned char kind;
} ModeObj;

typedef struct {
    unsigned char pad0[0x2F0];
    unsigned char a[0x868 - 0x2F0];
    unsigned char b[0xDE0 - 0x868];
    unsigned char c[0x1358 - 0xDE0];
    unsigned char d[0x2F80 - 0x1358];
    int w2F80;
    unsigned char pad2F84[0x2FB4 - 0x2F84];
    ModeObj *obj;
    unsigned char pad2FB8[0x7AEC - 0x2FB8];
    int w7AEC;
    unsigned char snd[0x7CA8 - 0x7AF0];
    int w7CA8;
    unsigned char pad7CAC[2];
    unsigned char state;
    unsigned char sub;
    unsigned char b7CB0;
    unsigned char pad7CB1[0x7CC0 - 0x7CB1];
    int w7CC0;
    int w7CC4;
    int w7CC8;
    unsigned char pad7CCC[4];
    int w7CD0;
} ModeOwner;

typedef struct {
    unsigned char pad0[0x11];
    unsigned char id;
} ModeArg;

extern unsigned char D_800F2AD0[];
extern char D_800F3BC0[];
extern char D_800F26E0[];
extern int D_800F2744;
extern volatile int D_800F2728;
extern void func_800BC07C(unsigned char *pad, int id);
extern void func_8009C0D8(int a, int b);
extern void func_800C013C(char *bank);
extern void func_800AB2A4(char *a, int b, int c, ModeOwner *p, int e, int f);
extern void func_800D29E0(void *p);
extern void func_800AC25C(ModeOwner *p, int a, int b, int c);
extern void func_800A9BE8(void *p, int n);
extern float func_8007BB9C(ModeObj *obj);
extern void func_80074C58(ModeOwner *p, float f);
extern void func_80072E88(ModeOwner *p, int arg);

void func_80072078(ModeOwner *p, ModeArg *arg, int arg2)
{
    unsigned char *pad = D_800F2AD0;
    unsigned char bits;

    func_800BC07C(pad, arg->id);
    bits = pad[3];
    if (bits & 0x10) {
        if (p->w7CD0 == 0) {
            p->w7AEC = 15;
            func_8009C0D8(2, D_800F2AD0[0] >> 5);
        }
    } else if (bits & 0x2) {
        if (p->w7CD0 != 0) {
            goto cancel;
        }
        p->w7AEC = 15;
        func_8009C0D8(0, D_800F2AD0[0] >> 5);
    } else if (bits & 0x8) {
        func_800C013C(D_800F3BC0);
        if (p->w7CD0 != 0) {
cancel:
            {
                int *w = &p->w7AEC;
                *w = 0;
                func_800AB2A4(D_800F26E0, D_800F2744, 7, p, 0, 9);
            }
        } else if (p->state == 14) {
            p->w7CC0 = 0x700;
        } else if (p->sub == 5) {
            p->state = 17;
            D_800F2728 = 0;
        } else if (p->obj->kind == 1) {
            switch (p->state) {
            case 1:
            case 2:
                func_800D29E0(p->a);
                func_800D29E0(p->b);
                func_800D29E0(p->c);
                func_800D29E0(p->d);
                func_800AC25C(p, 95, 17, 0);
                func_800A9BE8(p->snd, 4);
                p->w7CC0 = -7680;
                break;
            case 10:
            case 11:
                p->state = 12;
                break;
            case 14:
                p->w7CC0 = 0x700;
                break;
            case 12:
            case 13:
                p->w7CC4 = 256;
                p->w7CC0 = 256;
                break;
            }
        } else if (p->sub == 2) {
            func_800D29E0(p->a);
            p->w7CC0 = 0;
            p->state = 13;
            p->w7CC8 = 0;
            p->w2F80 = 0;
        } else {
            p->b7CB0 = p->sub;
            p->w7CA8 = 0;
            p->state = 17;
            func_80074C58(p, func_8007BB9C(p->obj));
        }
    }
done:
    func_80072E88(p, arg2);
}
