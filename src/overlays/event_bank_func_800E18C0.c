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

static inline u32 rnd(u32 n)
{
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    return ((D_800F2714 >> 15) * n) >> 16;
}

void func_800E18C0(u8 *p)
{
    s32 k;
    s32 v;
    u8 *e;
    u16 h;

    k = ((Obj *)p)->tbl[B(0x60C)][733];
    e = p + k * 16;
    if (*(s16 *)(e + 25098) != 1) {
        h = *(u16 *)(e + 25100);
        v = k;
        if (rnd(0xFFFF) & 1) {
            if (h == 0) {
            } else if (h == 1) {
                v += 16;
            } else if (h >= 3) {
                v += 8;
            } else {
                v = 208;
            }
        } else {
            if (h != 0) {
                if (h == 1) {
                    v += 40;
                } else if (h >= 3) {
                    v += 32;
                } else {
                    v = 282;
                }
            } else {
                v += 24;
            }
        }
        if (D_800FC270->on != 0 && W(25320) == 1) {
            func_800C0110(D_800F3BC0, v, 0, 0);
        }
    }
}
