typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef float f32;

typedef struct S12 { s8 type; u8 pad[11]; } S12;
typedef struct S60 { u8 pad[32]; u8 kind; u8 pad2[27]; } S60;
typedef struct G {
    S60 ent[42];
    u8 pad[2572 - 42 * 60];
    u8 count;
    u8 pad3[3];
    S12 arr[1];
} G;
extern G *D_800FC270;

extern void func_80074874(u8 *p, s32 a);
extern f32 func_8007BB9C(s32 a);
extern void func_80074C58(u8 *p, f32 a);

#define W(o) (*(s32 *)(p + (o)))
#define SB(o) (*(s8 *)(p + (o)))

void func_800A7C98(u8 *p)
{
    while (1) {
        s32 t;
        u8 v;
        if (!(SB(31917) < D_800FC270->count)) break;
        t = D_800FC270->arr[SB(31917)].type;
        if (t != 8) {
            v = D_800FC270->ent[t].kind;
        } else {
            v = 3;
        }
        if (v == 3) {
            func_80074874(p, 1);
            func_80074C58(p, func_8007BB9C(W(12212)));
        }
        SB(31917)++;
    }
    SB(31917)--;
}
