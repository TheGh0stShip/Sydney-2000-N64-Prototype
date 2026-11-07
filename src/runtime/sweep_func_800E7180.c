typedef struct { float x, y, z; } Vec3;
typedef struct { short x, y; } V2;
typedef struct { float x, y; short sz; short sx; int pad; } P;

int func_800E7180(void *self, Vec3 *pt, V2 *verts, unsigned char *idx)
{
    P p[2];
    P *cur;
    V2 *v;
    unsigned char n, i;
    int cnt = 0;

    v = &verts[idx[1]];
    n = idx[0] + 1;
    cur = &p[0];
    cur->x = v->x;
    cur->y = v->y;
    if (cur->x != pt->x) {
            if (pt->x < cur->x) cur->sx = 1;
            else cur->sx = -1;
        } else cur->sx = 0;
    if (cur->y != pt->z) {
            if (pt->z < cur->y) cur->sz = 1;
            else cur->sz = -1;
        } else cur->sz = 0;
    i = 2;
    while (1) {
        if (!(i < n)) break;
        if (cur == &p[0]) cur = &p[1];
        else cur = &p[0];
        v = &verts[idx[i]];
        cur->x = v->x;
        cur->y = v->y;
        if (cur->x != pt->x) {
            if (pt->x < cur->x) cur->sx = 1;
            else cur->sx = -1;
        } else cur->sx = 0;
        if (cur->y != pt->z) {
            if (pt->z < cur->y) cur->sz = 1;
            else cur->sz = -1;
        } else cur->sz = 0;
        if (p[0].sz != p[1].sz) {
            if (p[0].sx != p[1].sx) {
                float t = (p[0].x - p[1].x) / (p[0].y - p[1].y) * (pt->z - p[1].y) + p[1].x;
                if (pt->x < t) cnt++;
                else if (t == pt->x) return 1;
            } else {
                if (p[0].sx == 1) cnt++;
                else if (p[0].sx == 0) return 1;
            }
        } else {
            if (p[0].sz == 0) return 1;
        }
        i++;
    }
    return cnt & 1;
}
