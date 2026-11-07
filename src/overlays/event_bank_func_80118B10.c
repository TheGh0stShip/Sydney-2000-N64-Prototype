typedef int s32;
typedef unsigned char u8;
extern void func_800A6160(u8 *, s32, s32);
extern void func_800E56FC(u8 *, s32, s32);
extern void func_800AC37C(u8 *, u8 *);
extern void func_800E79E0(u8 *, u8);
extern void func_8007E978(u8 *);
extern void func_8007E520(u8 *, s32);
extern void func_80017860(s32);
extern void func_80017820(s32, s32, s32, s32);
void func_8007EA80(u8 *o, s32 k, s32 c, s32 d, s32 e)
{
    u8 *p;
    s32 n;
    func_800A6160(o, k, 1);
    if (k == 22) {
        func_800E56FC(o + 196, e, 2);
    } else {
        func_800E56FC(o + 196, e, 1);
    }
    n = k - 20;
    func_800AC37C(o + 196, o);
    p = o + 736;
    func_800AC37C(p, o);
    *(s32 *)(p + 216) = e;
    func_800E79E0(p, n);
    func_8007E978(o);
    func_8007E520(o, c);
    func_80017860(1);
    func_80017820(33, 56, 86, 1);
}
