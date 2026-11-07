typedef unsigned char u8;
typedef struct Obj {
    char pad[236];
    float unkEC;
    int unkF0;
    char padF4[632 - 244];
    float unk278;
    char pad27C[735 - 636];
    u8 unk2DF;
    char pad2E0[768 - 736];
    float unk300;
    char pad304[820 - 772];
    float unk334;
    char pad338[1260 - 824];
    float unk4EC;
} Obj;
extern void func_800B8C70(Obj *, float);
void func_8007DB20(Obj *o, float a, float b)
{
    float s = o->unk300;
    float t = s * o->unk334;
    t *= 0.7f;
    if (t > 0.0f) {
        t *= b - a;
        t += a + 0.7f;
    }
    o->unk278 = t;
    func_800B8C70(o, t);
    if (o->unk2DF) {
        o->unk4EC = -o->unk278 * 1.4089809656143188f;
    } else {
        o->unk4EC = o->unk278 * 1.4417479038238525f;
    }
    if (s > 0.4f) {
        s = 0.4f;
    } else if (s < 0.05f) {
        s = 0.05f;
    }
    s -= 0.05f;
    s *= 2.857142857f;
    o->unkF0 = 0;
    o->unkEC = s;
}
