
typedef float f32;
typedef int s32;
typedef struct
{
  f32 x;
  f32 y;
  f32 z;
} Vec;
typedef struct
{
  f32 pad;
  Vec p0;
  Vec p1;
  Vec p2;
  Vec p3;
} Seg;
typedef struct
{
  s32 pad[3];
  Seg **segs;
} Path;
void func_800AF0E4(Path *path, f32 t, s32 idx, Vec *out)
{
  f32 u = 1.0f - t;
  f32 uu = u * u;
  f32 tt = t * t;
  f32 m = (((t * 4.0f) + t) + t) * u;
  f32 a = (tt + tt) + tt;
  f32 b = (uu + uu) + uu;
  f32 c = b - m;
  f32 d = m - a;
  Seg *s = path->segs[idx];
  out->x = (((-(b * s->p0.x)) + (c * s->p1.x)) + (d * s->p2.x)) + (a * s->p3.x);
  out->y = (((-(b * s->p0.y)) + (c * s->p1.y)) + (d * s->p2.y)) + (a * s->p3.y);
  out->z = (((-(b * s->p0.z)) + (c * s->p1.z)) + (d * s->p2.z)) + (a * s->p3.z);
}
