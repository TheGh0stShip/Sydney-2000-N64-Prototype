typedef struct { float x, y, z; } Vector3;
typedef struct {
    unsigned short pad0;
    unsigned short start;     /* 0x2 */
    unsigned short count;     /* 0x4 */
    unsigned short scale;     /* 0x6 */
    char pad8[0x28 - 8];
} Track;
typedef struct {
    char pad0[0x14];
    Vector3 *points;          /* 0x14 */
    char pad18[4];
    Track *tracks;            /* 0x1C */
} Model;
typedef struct {
    char pad0[0xF4];
    Model *model;             /* 0xF4 */
} Obj;
int func_800B9830(Obj *o, int idx, Vector3 *pos, int *ratio, unsigned short *len)
{
    Model *m = o->model;
    if (pos) {
        unsigned short k = m->tracks[idx].start + m->tracks[idx].count - 1;
        pos->x = m->points[k].x;
        pos->y = m->points[k].y;
        pos->z = m->points[k].z;
    }
    if (ratio) {
        unsigned int d = m->tracks[idx].scale;
        if (d & 0x8000) {
            d &= 0x7FFF;
        } else {
            d <<= 8;
        }
        *ratio = (float)(unsigned int)(m->tracks[idx].count << 8) / (float)d * 7680.0f;
    }
    if (len) {
        *len = m->tracks[idx].count;
    }
    return 0;
}
