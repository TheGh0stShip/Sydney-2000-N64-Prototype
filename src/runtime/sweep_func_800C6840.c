typedef struct {
    short off;
    short pad;
    void (*fn)();
} VEnt;

typedef struct {
    char p0[16];
    VEnt draw;
    VEnt reset;
    char p1[64 - 32];
    VEnt update;
} VTbl;

typedef struct {
    char p0[176];
    unsigned char ready;
    char p1[180 - 177];
    VTbl *vt;
    char p2[196 - 184];
    char box[212 - 196];
} Panel;

extern Panel D_80101960[];
extern float D_80101944;
extern float D_80101948;
extern float D_8010194C;
extern float D_80101950;
extern float D_80101954;

void func_8001A1D8(void *box, float x0, float y0, float x1, float y1);

void func_800C6840(void *unused, unsigned char cols, unsigned char idx, unsigned char col, int arg4, int vert)
{
    Panel *o = &D_80101960[idx];
    if (vert) {
        D_80101954 = 545.0f / cols;
        D_80101944 = col * D_80101954 + -150.0f;
        D_80101948 = -2.0f;
        D_8010194C = D_80101944 + D_80101954;
        D_80101950 = 9.0f;
        func_8001A1D8(o->box, D_80101944, D_80101948, D_8010194C, D_80101950);
    } else {
        D_80101954 = 55.0f / cols;
        D_80101944 = -8.0f;
        D_8010194C = 98.0f;
        D_80101948 = col * D_80101954 + 0.0f;
        D_80101950 = D_80101948 + D_80101954 - 0.0f;
        func_8001A1D8(o->box, D_80101944, D_80101948, D_8010194C, D_80101950);
    }
    o->vt->reset.fn((char *)o + o->vt->reset.off);
    o->ready = 1;
    o->vt->draw.fn((char *)o + o->vt->draw.off, arg4);
    o->vt->update.fn((char *)o + o->vt->update.off);
}
