#include "sydney_types.h"

/* Finds a new node for a walker: tries the current node, then its neighbours in a preferred rotation, then any node within radius. */
typedef struct { s8 start; u8 step; } DirOrder;
typedef struct { s16 x, unk_02, z, radius; } Circle;
typedef struct Node { u8 unk_000[4]; Circle c; u8 neighbour[8]; u8 unk_014[0x198 - 0x14]; u8 shape[1]; } Node;
typedef struct { u8 unk_00[6]; u16 count; } Header;
typedef struct Graph { Header *hdr; Node *nodes[1]; } Graph;
typedef struct Walker { f32 x, y, z; u8 unk_0C[0xC]; u16 node; u16 unk_1A; s32 order; } Walker;
extern u8 D_800FF424[];
extern DirOrder D_800FF448[];
s16 func_800E7180(Graph *g, Walker *w, void *shape, void *tmp);
void func_800E755C(Graph *g, Walker *w);
void func_800E6AF8(Graph *g, Walker *w) {
    Node *cur = g->nodes[w->node];
    u8 *nb;
    s8 start, d;
    u8 step;
    u16 i;
    f32 px, pz;
    if (func_800E7180(g, w, cur->shape, D_800FF424) != 0)
        return;
    start = D_800FF448[w->order].start;
    step = D_800FF448[w->order].step;
    nb = cur->neighbour;
    d = start;
    do {
        s32 n = nb[d];
        if (n != 0xFF && func_800E7180(g, w, g->nodes[n]->shape, D_800FF424) == 1) {
            w->node = n;
            return;
        }
        d += step;
        if (d < 0)
            d = 7;
        else if (d >= 8)
            d = 0;
    } while (d != start);
    px = w->x;
    pz = w->z;
    i = 0;
    while (1) {
        Node *nd;
        f32 dx, dz, r;
        Circle *c;
        if (i >= g->hdr->count) break;
        nd = g->nodes[i];
        c = &nd->c;
        dx = c->x - px;
        r = c->radius;
        if (dx < 0.0f) dx = -dx;
        if (!(dx <= r)) { i++; continue; }
        dz = c->z - pz;
        if (dz < 0.0f) dz = -dz;
        if (!(dz <= r)) { i++; continue; }
        if (dx * dx + dz * dz <= r * r && func_800E7180(g, w, nd->shape, D_800FF424)) {
            w->node = i;
            func_800E755C(g, w);
        }
        i++;
    }
}
