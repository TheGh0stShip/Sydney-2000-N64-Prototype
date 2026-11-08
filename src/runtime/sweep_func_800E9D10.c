typedef struct {
    unsigned short flags;
    short timer;
    float x, y, z;
    float vx, vy, vz;
    float grav;
    float floor;
    float ang, dang;
    unsigned short frame;
    short last;
    unsigned short fstep;
    char pad[64 - 50];
} Part;

typedef struct Node {
    short pad0;
    unsigned short active;
    int count;
    Part *parts;
    struct Node *next;
} Node;

typedef struct {
    char pad[188];
    Node *list;
} Sys;

void func_800E9D10(Sys *s)
{
    Node *n;
    Part *p;
    int cnt;
    unsigned short flags;
    short t;
    float vx, vy, vz, y, fl;

    n = s->list;
    while (1) {
        if (n == 0) return;
        p = n->parts;
        cnt = n->count;
        if (n->active != 0) {
        for (; cnt != 0; cnt--, p++) {
            flags = p->flags;
            if (flags == 0) continue;
            t = p->timer;
            if (t <= 0) {
                flags = 0;
            } else {
                t--;
                p->timer = t;
            }
            if (!(flags & 0x80)) {
                vy = p->vy + p->grav;
                vx = p->vx;
                vz = p->vz;
                p->x += vx;
                p->z += vz;
                fl = p->floor;
                y = p->y + vy;
                if (flags & 0x1000) {
                    if (flags & 0x800) {
                        if (fl <= y) {
                        vy = -(vy * 0.5f);
                        vy += vy * 0.5f;
                        y = fl;
                    }
                    } else if (y <= fl) {
                        vy = -(vy * 0.5f);
                        vy += vy * 0.5f;
                        y = fl;
                    }
                    if (y == fl) {
                        if (flags & 0x400) vy -= vy * 0.5f;
                        if (flags & 0x8000) {
                            vx *= 0.5f;
                            vz *= 0.5f;
                        }
                    }
                } else if (flags & 0x2000) {
                    if (flags & 0x800) {
                        if (fl <= y) flags = 0;
                    } else if (y <= fl) flags = 0;
                } else if (flags & 0x4000) {
                    if (flags & 0x800) {
                        if (fl <= y) y = fl;
                    } else if (y <= fl) y = fl;
                }
                p->vx = vx;
                p->vz = vz;
                p->vy = vy;
                p->y = y;
            }
            if (flags & 0x200) p->ang += p->dang;
            if (flags & 0x100) {
                if (t <= p->last) p->frame += p->fstep;
            }
            if (flags == 0) n->active--;
            p->flags = flags;
        }
        }
        n = n->next;
    }
}
