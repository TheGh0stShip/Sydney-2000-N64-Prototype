typedef struct { char pad[1266]; unsigned char on; } Cfg;
typedef struct { char pad[0xBC]; char *bank; char padc0[0x4A9E - 0xC0]; unsigned char done; char pad4a9f; int stage; } Scene;
typedef struct { short id; } Cue;

extern Cfg *D_800FC270;
extern void func_800B3178(Cue *c, int n);
extern void func_800E9744(char *b);
extern void func_800DF988(Scene *s, int a);
extern void func_800E4458(Scene *s, int a);
extern void func_800E287C(Scene *s, int a);
extern void func_800DFFF4(Scene *s, int a);
extern void func_800DFD98(Scene *s, int a);
extern void func_800E9A2C(char *b, int f, int n);
extern void func_800E43D0(Scene *s, int a);
extern void func_800E434C(Scene *s, int a);
extern void func_800E0B20(Scene *s, int a);
extern void func_800E1F40(Scene *s, int a);
extern void func_800E349C(Scene *s, int a);
extern void func_800E4538(Scene *s);

void func_800DEAA0(Scene *s, int ev, int arg)
{
    Cue c;

    c.id = 263;
    func_800B3178(&c, 1);
    switch (ev) {
    case 12:
        func_800E9744(s->bank);
        func_800DF988(s, arg);
        break;
    case 13:
        func_800E4458(s, arg);
        break;
    case 14:
        func_800E9744(s->bank);
        if (arg == 10) {
            func_800E287C(s, 1);
        } else {
            D_800FC270->on = 0;
            func_800DFFF4(s, 1);
        }
        break;
    case 17:
        func_800DFD98(s, arg);
        if (s->bank != 0) {
            func_800E9A2C(s->bank, 1024, 1);
        }
        break;
    case 15:
        func_800E43D0(s, arg);
        break;
    case 16:
        func_800E9744(s->bank);
        func_800E434C(s, arg);
        break;
    case 18:
        func_800E0B20(s, arg);
        break;
    case 19:
        func_800E1F40(s, arg);
        break;
    case 20:
        func_800E349C(s, arg);
        break;
    case 21:
        if (arg == 13) {
            func_800E4538(s);
        } else if (s->stage == 19) {
            func_800E287C(s, 0);
        } else {
            func_800DFFF4(s, 0);
        }
        break;
    }
    if (arg == 57) {
        s->done = 0;
        func_800E4538(s);
    }
}
