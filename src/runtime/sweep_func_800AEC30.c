/* Initialise a positional event record (kind 2) with an argument. */
typedef struct Vec3 { float x, y, z; } Vec3;

typedef struct Event {
    int kind;
    int pad04;
    int state;
    int pad0C;
    Vec3 dir;
    int arg;
    int pad20[2];
    int time;
    Vec3 pos;
    int pad38[3];
    int extra;
    int link;
} Event;

typedef struct Clock { int pad; int frame; } Clock;
extern Clock D_800F2740;

static __inline__ void vec3_zero(Vec3 *v)
{
    v->x = 0;
    v->y = 0;
    v->z = 0;
}

static __inline__ void vec3_copy(Vec3 *dst, Vec3 *src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

static __inline__ void event_clear(Event *ev)
{
    ev->kind = 0;
    ev->link = 0;
    ev->arg = 0;
    ev->time = 0;
    ev->extra = 0;
    vec3_zero(&ev->pos);
    vec3_zero(&ev->dir);
}

void func_800AEC30(Event *ev, Vec3 *pos, int arg)
{
    event_clear(ev);
    ev->kind = 2;
    vec3_copy(&ev->pos, pos);
    ev->arg = arg;
    ev->time = D_800F2740.frame;
    ev->state = 0;
}
