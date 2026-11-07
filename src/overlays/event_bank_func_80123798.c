typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
extern void func_80006B24(u8 *);
void func_80083188(s32 x, u8 *d, f32 s, u32 a, u32 b)
{
    f32 r;
    f32 g;
    f32 c;
    r = (f32)((a >> 16) & 0xFF) - (f32)((b >> 16) & 0xFF);
    g = (f32)((a >> 8) & 0xFF) - (f32)((b >> 8) & 0xFF);
    c = (f32)(a & 0xFF) - (f32)(b & 0xFF);
    if (r < 0.0f) r = -r;
    if (g < 0.0f) g = -g;
    if (c < 0.0f) c = -c;
    d[1] = (u32)(r * s);
    d[2] = (u32)(g * s);
    d[3] = (u32)(c * s);
    func_80006B24(d);
}
