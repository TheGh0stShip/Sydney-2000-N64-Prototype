/* event_bank whole function ROM 0xB52DC..0xB54A8, linked at 0x8007610C (VRAM delta 0x7FFC0E30). */

#define I32(p, o) (*(int *)((char *)(p) + (o)))
#define U8(p, o) (*(unsigned char *)((char *)(p) + (o)))

extern char *D_800FC270;
extern char D_800F3BC0[];

extern void func_80076FB8(char *);
extern void func_8009BF6C(char *, int);
extern void func_8009AEC0(int, char *);
extern void func_800C0110(char *, int, int, int);

void func_800B52DC(char *self)
{
    char *g = D_800FC270;
    int mode = I32(g, 2564);
    int a;
    int b;
    int c;
    int ev;

    if (mode == 0)
        return;
    a = -1;
    b = a;
    c = a;
    if (U8(self, 23416) == 0 && U8(self, 23422) != 0 && U8(self, 23418) == 0) {
        ev = I32(g, 2560);
        if (ev == 5) {
            c = 24;
        } else if (ev != 4) {
            if (ev == 0)
                c = 165;
            else if (ev == 1)
                c = 167;
            else if (ev == 2)
                c = 169;
        } else {
            if (mode == 2) {
                a = 449;
                b = 99;
                c = 451;
            } else if (mode == 3) {
                c = 452;
            } else if (mode == 5) {
                a = 448;
                b = 99;
                c = 450;
            }
        }
    } else {
        func_80076FB8(self);
        func_8009BF6C(self + 12020, I32(self, 21292));
        func_8009AEC0(2, self + 14820);
    }
    if (a != -1 && (unsigned int)(U8(self, 23423) - 3) >= 2)
        func_800C0110(D_800F3BC0, a, 0, 0);
    if (b != -1 && (unsigned int)(U8(self, 23423) - 3) >= 2)
        func_800C0110(D_800F3BC0, b, 0, 0);
    if (c != -1 && (unsigned int)(U8(self, 23423) - 3) >= 2)
        func_800C0110(D_800F3BC0, c, 0, 0x1C200);
}
