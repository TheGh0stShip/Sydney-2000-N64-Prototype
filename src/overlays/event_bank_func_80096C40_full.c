typedef unsigned char u8;

typedef struct {
    char pad0[0x68];
    int vol;
} Snd;

typedef struct {
    char pad0[0x2E8];
    int i2E8;
} P;

typedef struct {
    char pad0[0xC];
    int iC;
    unsigned int type;
} Msg;

typedef struct {
    char pad0[0x2B8];
    char x2B8[0x2F48 - 0x2B8];
    int i2F48;
    char pad2F4C[0x2F50 - 0x2F4C];
    int i2F50;
    char pad2F54[0x2F68 - 0x2F54];
    P *p2F68;
    char x2F6C[0x7DE4 - 0x2F6C];
    char x7DE4[0x7FE8 - 0x7DE4];
    char x7FE8[0x8052 - 0x7FE8];
    u8 state;
    char pad8053;
    u8 mode;
    char pad8055[0x806C - 0x8055];
    int i806C;
    char pad8070[0x8078 - 0x8070];
    int i8078;
    char pad807C[0x8098 - 0x807C];
    int i8098;
    int i809C;
} S;

extern Snd D_800F1AE0;
extern char D_800F26E0[];
extern int D_800F2744;
extern char D_80076E78[];
extern char D_80076EA0[];
extern char D_80076EC8[];

void func_8001D5D8(Snd *, int, int, int, int, int);
int func_8001D4B8(Snd *, int, int, int);
void func_8001D640(Snd *, int, int);
void func_80074F08(S *);
void func_80076864(S *);
void func_800768EC(S *, int, int, int);
void func_800A1F24(void *, void *, int *, int *);
void func_800A9BE8(void *, int);
void func_800AB2A4(void *, int, int, int, void *, int);
void func_800D29E0(void *);
void func_800D33A0(void *, char *, int, int);

static inline void sndcmd(int h, int v, int time, int a) {
    func_8001D5D8(&D_800F1AE0, h, v, time, a, 0);
}

static inline void show15(S *s, int base, Msg *m) {
    func_800AB2A4(D_800F26E0, base, 15, s->i2F50, (void *)m->iC, 0);
}

static inline void sndfade(int h, int pct, int time) {
    func_8001D5D8(&D_800F1AE0, h, (D_800F1AE0.vol * pct) >> 15, time, 0, 0);
}

void func_80071650(S *s, Msg *m) {
    int h;
    unsigned int t;
    unsigned int t2;
    int a;
    int b;

    if (s->state == 18) {
        return;
    }
    t = m->type;
    switch (t) {
    case 5:
        func_800D29E0(s->x2B8);
        switch (s->mode) {
        case 0:
        case 1:
        case 5:
            sndcmd(s->i8098, 0, 270, 1);
            h = func_8001D4B8(&D_800F1AE0, 96, 0, -1);
            func_8001D640(&D_800F1AE0, h, 0);
            sndfade(h, 9830, 120);
            s->i809C = h;
            break;
        case 2:
        case 3:
        case 4:
            break;
        }
        switch (s->mode) {
        case 2:
            func_800D29E0(s->x2B8);
            func_800A9BE8(s->x7DE4, 18);
            break;
        case 0:
        case 1:
        case 3:
        case 4:
            func_800A9BE8(s->x7DE4, 4);
            break;
        case 5:
            break;
        }
        s->state = 5;
        break;
    case 22:
        if (s->mode == 2) {
            s->i806C = 0x12C00;
            s->i8078 = 1;
            s->i2F48 = 1;
            func_800768EC(s, 31, 0, 0);
            func_800D33A0(s->x2B8, D_80076E78, 1, -1);
            func_800A9BE8(s->x7DE4, 19);
        }
        s->state = t;
        break;
    }
    t2 = m->type;
    switch (t2) {
    case 23:
        if (s->mode == 2) {
            s->i806C = 0x16800;
            s->i8078 = 1;
            s->i2F48 = 1;
            func_800768EC(s, 33, 0, 0);
            func_800D33A0(s->x2B8, D_80076EA0, 1, -1);
            func_800A9BE8(s->x7DE4, 20);
        }
        s->state = t2;
        break;
    case 7:
        if (s->mode == 2) {
            s->i8078 = 1;
            s->i2F48 = 1;
            s->i806C = 0xE100;
            func_800A9BE8(s->x7DE4, 21);
            func_800768EC(s, 32, 0, 0);
            func_800D33A0(s->x2B8, D_80076EC8, 1, -1);
        }
        break;
    case 9:
        switch (s->mode) {
        case 0:
        case 2:
        case 3:
        case 4:
            s->i806C = 0;
            if (s->p2F68->i2E8 != 0) {
                func_80074F08(s);
                func_800A9BE8(s->x7DE4, 5);
            } else {
                func_80076864(s);
                func_800A9BE8(s->x7DE4, 9);
            }
            break;
        case 5:
            s->i806C = 0;
            if (s->p2F68->i2E8 != 0) {
                func_80074F08(s);
                func_800A9BE8(s->x7DE4, 13);
            } else {
                func_80076864(s);
                func_800A9BE8(s->x7DE4, 12);
            }
            break;
        case 1:
            s->i806C = 0;
            if (s->p2F68->i2E8 != 0) {
                func_800A9BE8(s->x7DE4, 13);
            } else {
                func_800A9BE8(s->x7DE4, 12);
            }
            break;
        }
        func_800A1F24(s->x2F6C, s->x7FE8, &a, &b);
        if (s->p2F68->i2E8 != 0) {
            func_800AB2A4(D_800F26E0, D_800F2744, 12, s->i2F50, s->x7FE8, 0);
            if (s->mode != 4) {
                sndfade(s->i809C, 19660, 60);
            }
        }
        s->state = 9;
        break;
    case 12:
        switch (s->mode) {
        case 2:
            func_800A9BE8(s->x7DE4, 6);
            break;
        case 0:
        case 1:
        case 3:
        case 4:
            if (s->p2F68->i2E8 != 0) {
                func_800A9BE8(s->x7DE4, 6);
            }
            {
                P *p = s->p2F68;
                if (p->i2E8 != 0) {
                    show15(s, D_800F2744 + 0x1E00, m);
                }
            }
            s->state = 12;
            break;
        case 5:
            if (s->p2F68->i2E8 != 0) {
                func_800A9BE8(s->x7DE4, 14);
            }
            {
                P *p = s->p2F68;
                if (p->i2E8 != 0) {
                    show15(s, D_800F2744, m);
                }
            }
            s->state = 12;
            break;
        }
        break;
    }
}
