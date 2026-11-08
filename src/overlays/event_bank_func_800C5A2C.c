typedef struct Cam {
    char pad0[17152];
    char sub[84];        /* 17152 */
    float y;             /* 17236 */
    float x;             /* 17240 */
    char pad1[18136 - 17244];
    unsigned char flags; /* 18136 */
    char pad2[3];
    float px;            /* 18140 */
    float py;            /* 18144 */
    float vx;            /* 18148 */
    float vy;            /* 18152 */
    float ay;            /* 18156 */
    float ax;            /* 18160 */
    float speed;         /* 18164 */
    float k;             /* 18168 */
} Cam;

void func_800AD9E8(void *p);

void func_800C5A2C(Cam *o)
{
    float d;

    switch (o->flags & 3) {
    case 0:
        o->vx = 0.0f;
        break;
    case 1:
        o->vx = o->speed;
        break;
    case 2:
        o->vx = -o->speed;
        break;
    }
    o->vx += o->ax;
    d = o->vx - o->px;
    o->px += d * o->k;
    o->x += o->px;
    if (o->x > 72.0874f) {
        o->x = 72.0874f;
        o->ax = 0.0f;
        o->flags &= ~1;
    }
    if (o->x < 6.553402f) {
        o->x = 6.553402f;
        o->ax = 0.0f;
        o->flags &= ~2;
    }
    switch (o->flags & 0xC) {
    case 0:
        o->vy = 0.0f;
        break;
    case 4:
        o->vy = -o->speed;
        break;
    case 8:
        o->vy = o->speed;
        break;
    }
    o->vy += o->ay;
    d = o->vy - o->py;
    o->py += d * o->k;
    o->y += o->py;
    if (o->y > 32.767f) {
        o->y = 32.767f;
        o->ay = 0.0f;
        o->flags &= ~8;
    }
    if (o->y < -32.767f) {
        o->y = -32.767f;
        o->ay = 0.0f;
        o->flags &= ~4;
    }
    func_800AD9E8(o->sub);
}
