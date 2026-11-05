typedef struct { short *data; int pad; int a; int b; } Track;
typedef struct { int value; int b; } Slot;
typedef struct {
    char pad0[188];
    char *game;
    char pad1[19102 - 192];
    unsigned char ready;
} Scene;

typedef union { short codes[1]; struct { int count; int enabled[1]; } s; } Table;
extern Table *D_800FF484;
extern int D_800FF544;
extern short D_800FF548[1];
extern Track D_800FE22C;
extern short D_800FE24A;
extern Slot D_800FCD8C;
extern char D_800F5900[];
extern int func_800D98FC(int);
extern void func_800B31EC(int);
extern void func_800D53A0(void *, int);

void func_800DFB48(Scene *self, int index)
{
    unsigned int i;

    D_800FF544 = index;
    if (D_800FF484->s.enabled[index] != 0) {
        for (i = 0; i < 1; i++) {
            D_800FF548[i] = D_800FF484->codes[i + index];
        }
    } else {
        for (i = 0; i < 1; i++) {
            D_800FF548[i] = 3;
        }
    }
    D_800FE22C.data = D_800FF548;
    D_800FE22C.a = 0;
    D_800FE22C.b = 0;
    D_800FCD8C.value = func_800D98FC(89);
    D_800FCD8C.b = 0;
    D_800FE24A = 2;
    func_800B31EC(3);
    func_800D53A0(D_800F5900, 16);
    self->ready = 1;
    *(int *)(self->game + 29364) = -1;
}
