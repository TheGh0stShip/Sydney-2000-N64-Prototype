typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct G
{
  u8 pad[1284];
  f32 h0;
  u8 pad1[1328 - 1288];
  f32 h1;
} G;
extern G *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(char *a, s32 b, s32 c, s32 d);
inline static void say(u8 *p, s32 n)
{
  if (p[31919] == 3 || p[31919] == 4)
    return;
  func_800C0110(D_800F3BC0, n, 0, 0);
}

void func_800A6E1C(u8 *p, f32 x)
{
  f32 t;
  f32 hi;
  f32 lo;
  if (p[31919] == 5)
  {
    return;
  }
  t = D_800FC270->h0;
  hi = t + 0.1f;
  lo = t - 0.1f;
  if (hi < x)
  {
    p[31956] = 1;
    say(p, 486);
  }
  else
    if ((x <= hi) && (t < x))
  {
    p[31956] = 2;
    say(p, 483);
  }
  else
    if (((x <= D_800FC270->h0) && (lo < x)) && (D_800FC270->h1 < x))
  {
    p[31956] = 3;
    say(p, 483);
  }
  else
    if (((x <= D_800FC270->h0) && (lo < x)) && (x < D_800FC270->h1))
  {
    p[31956] = 4;
    say(p, 483);
  }
  else
    if ((x <= lo) && (D_800FC270->h1 < x))
  {
    p[31956] = 5;
    say(p, 484);
  }
  else
    if (x < 13.0f)
  {
    say(p, 485);
  }
  else
    if ((13.0f <= x) && (x < 14.5f))
  {
    say(p, 481);
  }
  else
    if ((14.0f <= x) && (x < 15.5f))
  {
    say(p, 477);
  }
  else
    if ((15.5f <= x) && (x < 16.5f))
  {
    say(p, 478);
  }
  else
    if ((16.5f <= x) && (x < 17.5f))
  {
    say(p, 479);
  }
  else
    if ((17.5f <= x) && (x < 18.5f))
  {
    say(p, 480);
  }
  else
  {
    say(p, 482);
  }
}
