typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct G { u8 pad[0xA04]; s32 on; } G;
extern u32 D_800F2714;
extern G *D_800FC270;
extern u8 D_800F3BC0[];
extern void func_800C0110(u8 *a, s32 b, s32 c, s32 d);

#define B(o) (*(u8 *)(p + (o)))
#define W(o) (*(s32 *)(p + (o)))
typedef struct Obj { u8 pad[0x4EF0]; u8 *tbl[8]; } Obj;


void func_800E1790(u8 *p)
{
    s32 k;
    s32 s;
    s32 t;
    s32 v;
    u8 *e;

    k = ((Obj *)p)->tbl[B(0x60C)][733];
    e = p + k * 16;
    if (*(s16 *)(e + 25098) != 1) {
        s = 217;
        if (*(s32 *)(e + 25088) <= 0x9000 && *(s32 *)(e + 25092) < 1537) {
            t = 292;
            s = 225;
        } else {
            t = 291;
        }
        v = k + s;
        if (D_800FC270->on != 0 && W(25320) == 1) {
            func_800C0110(D_800F3BC0, v, 0, 0);
        }
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        if ((D_800F2714 >> 28) < 5 && D_800FC270->on != 0 && W(25320) == 1) {
            func_800C0110(D_800F3BC0, t, 0, 0);
        }
    }
}
