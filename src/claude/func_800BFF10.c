/* Runtime-stage C reconstruction: construct the resident random-driven controller object. */
typedef struct {
    int type;             /* 0x00 */
    char pad04[0xB0];
    void *update;         /* 0xB4 */
    int b8;               /* 0xB8 */
    int bc;               /* 0xBC */
    int c0;               /* 0xC0 */
    int c4;               /* 0xC4 */
    short c8;             /* 0xC8 */
    short ca;             /* 0xCA */
    short cc;             /* 0xCC */
    unsigned char ce;     /* 0xCE */
    unsigned char cf;     /* 0xCF */
    unsigned char d0;     /* 0xD0 */
    unsigned char d1;     /* 0xD1 */
    char padD2[0xE0 - 0xD2];
    void *draw;           /* 0xE0 */
    int seed;             /* 0xE4 */
} Controller;

extern Controller D_800F3BC0;
extern int D_800F3884;
extern char D_80088210[];
extern char D_80088130[];
extern void func_800AC3D4(Controller *self);

void func_800BFF10(void) {
    int seed;
    func_800AC3D4(&D_800F3BC0);
    seed = D_800F3884;
    D_800F3BC0.update = D_80088210;
    D_800F3BC0.seed = 1234;
    D_800F3BC0.b8 = 0;
    D_800F3BC0.bc = 0;
    D_800F3BC0.c0 = 0;
    D_800F3BC0.c4 = 0;
    D_800F3BC0.c8 = 0;
    D_800F3BC0.ca = 0;
    D_800F3BC0.cc = 0;
    D_800F3BC0.cf = 0;
    D_800F3BC0.d0 = 0;
    D_800F3BC0.d1 = 0;
    D_800F3BC0.ce = 0;
    D_800F3BC0.type = 0x36;
    if (seed == 0) {
        seed = 1;
    }
    D_800F3BC0.seed = seed;
    D_800F3BC0.draw = D_80088130;
}
