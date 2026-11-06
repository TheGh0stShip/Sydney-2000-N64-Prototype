typedef unsigned char u8;

typedef struct {
    int type;
    int time;
    int pad8;
    int idx;
    unsigned int val;
} Event;

typedef struct {
    void *p;
    int a;
    int b;
    int c;
    short d;
    short e;
} Slot;

extern u8 D_800F2AD0[];
extern char D_800F26E0[];
extern int D_800F2744;

extern void func_800B4794(int);
extern void func_80072368(char *);
extern void func_80072C44(char *);
extern void func_800AAC84(char *, char *, char *, int);
extern void func_800BBB94(int);
extern void func_800732AC(char *, float);
extern void func_800BC07C(u8 *, int);
extern void func_8009C0D8(int, int);
extern void func_80073D10(char *);
extern void func_80072A5C(char *);
extern void func_800751F4(char *);
extern void func_8007511C(char *);
extern void func_80074FF8(char *);
extern void func_80073438(char *);
extern void func_800716F0(char *, int);
extern void func_800AA658(void *, void *);
extern void func_800DB124(int);
extern void func_800137FC(void);
extern void func_800AB2A4(char *, int, int, int, char *, int);
extern void func_800A9B78(char *, char *, int, int, int);

#define B(o) (*(u8 *)(a + (o)))
#define W(o) (*(int *)(a + (o)))
#define P(o) (*(char **)(a + (o)))

void func_8009D120(char *a, Event *ev) {
    int dt = (ev->time - W(0x10)) >> 8;
    int s;
    char *obj;
    Slot *slot;
    void *p;
    u8 c;

    switch (ev->type) {
    case 3:
        func_800B4794(1);
        func_80072368(a);
        func_80072C44(a);
        func_800B4794(0);
        break;
    case 23:
        if (ev->val == 0) {
            break;
        }
        obj = P(0x5CA0);
        if (obj[0x1AA] == 1) {
            s = ev->val + ev->idx * 0x1E00;
            W(0x5E14) = s;
            if (B(0x5DE9) == 3) {
                if (!W(0x5E2C)) {
                    if (s < W(0x5E0C) || W(0x5E0C) == -7680) {
                        W(0x5E0C) = s;
                        func_800AAC84(obj, a + 0x5DF0, a + 0x5DF8, 4800);
                    }
                } else {
                    W(0x5E2C) = 0;
                }
            } else {
                if (B(0x5DE9) == 2) {
                    func_800BBB94(*(int *)(obj + 0x284));
                }
                func_800732AC(a, (float)s / 30.0f * (1.0f / 256.0f));
            }
        }
        B(0x5DE7) = 17;
        break;
    case 1:
        func_800BC07C(D_800F2AD0, ((u8 *)&ev->val)[1]);
        if (W(0x5E24) == 0) {
            c = D_800F2AD0[3];
            if (c & 0x10) {
                func_8009C0D8(2, D_800F2AD0[0] >> 5);
            } else if (c & 2) {
                func_8009C0D8(0, D_800F2AD0[0] >> 5);
            } else if (c & 8) {
                func_80073D10(a);
            }
        } else if (D_800F2AD0[3] & 0xA) {
            B(0x5DE6) = 0;
            W(0x5CAC) = 0;
            B(0x5DE5) = B(0x5DE4);
            func_80072A5C(a);
        }
        func_800716F0(a, dt);
        break;
    case 7:
        if (ev->val == 56) {
            B(0x5DE6) = 0;
            B(0x5DE5) = 0;
            func_800751F4(a);
            func_8007511C(a);
        } else if (ev->val == 55 || ev->val == 7) {
            func_80074FF8(a);
            func_80073438(a);
            func_80072A5C(a);
        }
        break;
    case 5:
        switch ((unsigned int)W(0xAC)) {
        case 0:
            break;
        case 1:
            func_800716F0(a, dt);
            break;
        case 2:
            if (W(8) != 0) {
                break;
            }
            slot = (Slot *)(a + 0x5C78);
            p = slot->p;
            if (p) {
                slot->p = 0;
                if (slot->a) {
                    func_800AA658(p, &slot->a);
                }
                if (slot->b) {
                    func_800AA658(p, &slot->b);
                }
                slot->d = 0;
                slot->e = 0;
                slot->c = 0;
                slot->p = 0;
            }
            func_800DB124(1);
            func_800137FC();
            { int t = D_800F2744; int u = W(4); func_800AB2A4(D_800F26E0, t, 20, u, a, W(0x5CAC)); }
            break;
        }
        break;
    case 11:
        switch (ev->val) {
        case 1:
        case 2:
        case 4:
        case 5:
            func_800A9B78(a + 0x5CB0, P(0x5CA0), 1, 1, 2);
            break;
        }
        break;
    }
    W(0x10) = ev->time;
}
