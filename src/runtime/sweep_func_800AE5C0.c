typedef struct { float x, y, z; } Vec;
typedef struct {
    int type;        /* 0x00 */
    int busy;        /* 0x04 */
    int landed;      /* 0x08 */
    char padc[0x1C - 0xC];
    float gravity;   /* 0x1C */
    float bounce;    /* 0x20 */
    float floor;     /* 0x24 */
    char pad28[0x2C - 0x28];
    Vec vel;         /* 0x2C */
} Body;
int func_800AE5C0(Body *b, Vec *pos)
{
    Vec *v;
    float vy;
    if (b->busy != 0 || b->landed != 0) {
        return 0;
    }
    if (b->type >= 1 && b->type <= 3) {
        if (b->type >= 2 && b->type <= 3) {
            b->vel.y = b->vel.y + b->gravity;
        }
        v = &b->vel;
        pos->x = pos->x + v->x;
        pos->y = pos->y + v->y;
        pos->z = pos->z + v->z;
        if (b->type == 3) {
            if (pos->y <= b->floor) {
                pos->y = b->floor;
                b->vel.y = -(b->vel.y * b->bounce);
                b->vel.x = b->vel.x * (b->bounce * 0.5f);
                b->vel.z = b->vel.z * (b->bounce * 0.5f);
            }
            vy = b->vel.y;
            if (vy < 0.0f ? -vy <= 0.163835f : vy <= 0.163835f) {
                if (pos->y <= b->floor) {
                    b->landed = 1;
                }
            }
        }
    }
    return 0;
}
