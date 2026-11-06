typedef float f32;
typedef struct { f32 x, y, z; } Vec3f;
typedef struct { char pad[0xc0]; int flags; } Sub;
typedef struct {
    char pad0[0x44d0];
    signed char *tbl;                 /* 0x44d0 */
    char pad1[0x45f4 - 0x44d4];
    unsigned char cur;         /* 0x45f4 */
    char pad2[0x47c8 - 0x45f5];
    Sub sub;                   /* 0x47c8 */
    char pad3[0x4900 - 0x47c8 - sizeof(Sub)];
    int last;                  /* 0x4900 */
} State;

void func_800BE6A8(State *st)
{
    Vec3f *v;
    f32 a, b;
    int i = st->cur;

    if (i == st->last) {
        Sub *s = &st->sub;
        s->flags |= 4;
        return;
    }
    i = (st->tbl + i)[2];
    switch (i) {
    case 1:
        a = *(f32 *)0x80070A28;
        break;
    case 2:
        a = *(f32 *)0x80070A2C;
        break;
    case 3:
        a = *(f32 *)0x80070A30;
        b = *(f32 *)0x80070A34;
        break;
    default:
        return;
    }
    v = (Vec3f *)((char *)st + 0x481c);
    *(volatile f32 *)&v->x = a;
    v->z = b;
    v->y = *(f32 *)0x80070A38;
}
