typedef struct { void *ptr; int size; int value; } Toggle;
typedef struct { char pad[4]; int flags; char pad8[0x1C - 8]; Toggle *tog; } Ent;
typedef struct { char pad[0x68]; int vol; } Snd;
typedef struct { char pad[0xD68]; int started; } Game;

extern Snd D_800F1AE0;
extern char D_800F5900[];
extern Game *D_800FC270;
extern int func_8001D4B8(Snd *s, int id, int a, int b);
extern void func_8001D640(Snd *s, int h, int vol);
extern void func_800B0F60(char *o);
extern void func_800B1550(char *o, int c);
extern void func_800D56A8(char *p);

void func_800C2E58(char *o, unsigned char *msg)
{
    Toggle *t;
    Game *g;

    if (msg[3] & 0x10) {
        if ((*(Ent **)(o + 0xDC))->flags & 0x80000) {
            int k;
            k = 32767;
            func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 89, 0, 1), (D_800F1AE0.vol * k) >> 15);
            return;
        }
        {
            int k;
            k = 32767;
            func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 130, 0, 1), (D_800F1AE0.vol * k) >> 15);
        }
        t = (*(Ent **)(o + 0xDC))->tog;
        switch (t->size) {
        case 0:
            *(int *)t->ptr ^= t->value;
            break;
        case 1:
            *(unsigned short *)t->ptr ^= (unsigned short)t->value;
            break;
        case 2:
            *(unsigned char *)t->ptr ^= (unsigned char)t->value;
            break;
        }
        func_800B0F60(o);
    } else {
        func_800B1550(o, msg[0]);
    }
    g = D_800FC270;
    if (g->started == 0) {
        g->started = 1;
        func_800D56A8(D_800F5900);
    }
}
