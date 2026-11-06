/* Event-bank: update three attached child transforms from their parent's matrices. */
typedef struct Vec3 { float x, y, z; } Vec3;

typedef struct ChildVt {
    char pad[0x28];
    short offset;
    void (*getMatrix)(void *obj, int mode, void *out);
} ChildVt;

extern char D_80073FD0[];
extern void func_800AD6D0(Vec3 *in, Vec3 *out);
extern void func_800AC5CC(void *a, void *b, void *c, int d);
extern void func_800AD9E8(void *a);

void func_80073078(char *self)
{
    struct { float m[16]; Vec3 pos; } f;
    double buf[10];
    Vec3 v;
    float k = *(float *)0x80070C80;
    int n = 0;
    unsigned char i;
    Vec3 *vp;
    float *mp;
    double *bp;

    for (;;) {
        char *obj;
        ChildVt *vt;
        char *node;
        float s, x, y, z;

        i = n;
        if (i >= 3)
            break;
        vt = *(ChildVt **)(self + i * 404 + 1904);
        obj = self + 1724 + i * 404;
        vt->getMatrix(obj + vt->offset, 15, f.m);
        mp = f.m;
        vp = &v;
        bp = buf;
        x = f.m[0];
        y = mp[1];
        z = mp[2];
        v.x = x;
        v.y = y;
        v.z = z;
        func_800AD6D0(vp, vp);
        s = *(float *)(self + 5024);
        v.x *= s;
        v.y *= s;
        v.z *= s;
        f.pos.x = v.x + f.pos.x;
        f.pos.y = v.y + f.pos.y;
        f.pos.z = v.z + f.pos.z;
        v.x = mp[8];
        v.y = mp[9];
        v.z = mp[10];
        func_800AD6D0(vp, vp);
        v.x *= k;
        v.y *= k;
        v.z *= k;
        n++;
        f.pos.x = v.x + f.pos.x;
        f.pos.y = v.y + f.pos.y;
        f.pos.z = v.z + f.pos.z;
        func_800AC5CC(mp, obj + 20, bp, 1);
        node = self + 1088 + i * 212;
        func_800AC5CC(D_80073FD0, bp, node + 20, 1);
        func_800AD9E8(node);
    }
}
