typedef unsigned char u8;
typedef struct S { char pad[23423]; u8 unk5B7F; } S;
typedef struct Obj {
    char pad[4];
    S *s;
    char pad8[736 - 8];
    int unk2E0;
    char pad2E4[840 - 740];
    char unk348[1208 - 840];
    u8 unk4B8;
    char pad4B9[3];
    int unk4BC;
    char unk4C0[1248 - 1216];
    int unk4E0;
} Obj;
extern unsigned int D_800F13F0;
extern void func_8007719C(S *, int *, int *, u8 *);
extern void func_800AC718(void *, void *);
void func_8007AE1C(Obj *o)
{
    int a, b;
    u8 c;
    S *s = o->s;
    func_8007719C(s, &a, &b, &c);
    switch (c) {
    case 1:
    case 2:
        o->unk4BC = a;
        break;
    case 3:
    case 4:
        if (o->unk4B8 == 0) {
            if (s->unk5B7F == 2) {
                o->unk4BC = 0;
            } else {
                o->unk4BC = a;
            }
        } else {
            o->unk4BC = b;
        }
        break;
    }
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    o->unk2E0 = (int)((float)(D_800F13F0 >> 19) * 0.000244140625f * 7680.0f) + 768;
    func_800AC718(o->unk348, o->unk4C0);
    o->unk4E0 = 0;
}
