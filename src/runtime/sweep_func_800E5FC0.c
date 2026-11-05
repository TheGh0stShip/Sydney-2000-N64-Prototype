typedef struct {
    int a;
    int b;
    int c;
    int d;
    float scale;
    int e;
    int color;
    int f;
    int g;
} Vertex;
typedef struct {
    char pad0[196];
    void *mesh;
    char pad1[212 - 200];
    short *indices;
} Water;
typedef struct {
    unsigned char kind;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    int mode;
    char pad0[20 - 8];
    float vec[3];
    char pad1[40 - 32];
    int enabled;
} Light;

extern char D_800F2758[];
extern Light D_801034D0;
extern void func_800125DC(int, unsigned short *, void **, short);
extern void func_80017C4C(void *, int, Vertex **);
extern void func_80017C3C(void *);
extern int func_8000EB20(char *);
extern void func_80017CF4(void *, int, unsigned short);
extern void func_80017930(unsigned short, int, int, int, int);
extern void func_800AA804(void *, short **, int, char *);
extern void func_80017C20(void *, int, unsigned short, short *);
extern void func_800AD6D0(float *, float *);
extern void func_8000673C(Light *);

void func_800E5FC0(Water *self, unsigned short vertexCount, unsigned short triCount)
{
    unsigned short count;
    Vertex *v;
    unsigned int i;
    unsigned short tex;
    unsigned int n;

    count = vertexCount;
    func_800125DC(1, &count, &self->mesh, triCount);
    func_80017C4C(self->mesh, 0, &v);
    for (i = 0; i < count; i++) {
        v->d = 0;
        v->scale = 1.0f;
        v->e = 0;
        v->f = 0;
        v->g = 0;
        v->a = 0;
        v->b = 0;
        v->c = 0;
        v->color = 0xFF00FF;
        v++;
    }
    func_80017C3C(self->mesh);
    tex = func_8000EB20("RIVER_WATER");
    func_80017CF4(self->mesh, 0, tex);
    func_80017930(tex, -1, 0xFF000000, -1, 10);
    n = triCount * 3;
    func_800AA804(D_800F2758, &self->indices, n * 2, "KAYAKFAC");
    for (i = 0; i < (unsigned int)(triCount * 3); i++) {
        self->indices[i] = 0;
    }
    func_80017C20(self->mesh, 0, triCount, self->indices);
    D_801034D0.kind = 0;
    D_801034D0.mode = 4;
    D_801034D0.r = 128;
    D_801034D0.g = 128;
    D_801034D0.b = 255;
    D_801034D0.enabled = 1;
    D_801034D0.vec[0] = 32.767f;
    D_801034D0.vec[1] = 32.767f;
    D_801034D0.vec[2] = -32.767f;
    func_800AD6D0(D_801034D0.vec, D_801034D0.vec);
    func_8000673C(&D_801034D0);
}
