typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    char pad0[12];
    int active;
    Vec3 pos;
    Vec3 vel;
    Vec3 acc;
    char pad1[24];
    float scale;
    char pad2[4];
    float alpha;
    char pad3[12];
} Particle;

typedef struct {
    int life;
    int state;
} ParticleLife;

typedef struct {
    char data[36];
} ParticleVtx;

typedef struct {
    char pad0[212];
    int vtxIndex;
    int vtxCount;
    unsigned int nParticles;
    Particle *particles;
    ParticleLife *lives;
    unsigned int flags;
    ParticleVtx *vtx0;
    ParticleVtx *vtx1;
    ParticleVtx *vtx2;
    char pad1[4];
    unsigned int nVtx;
    int user;
} Emitter;

extern char D_800F2758[];
extern void func_800AA804(void *, void *, unsigned int, const char *);

static __inline__ void vec_zero(Vec3 *v)
{
    v->x = 0;
    v->y = 0;
    v->z = 0;
}

void func_800E5830(Emitter *e, unsigned int n, unsigned int nVtx, int user)
{
    unsigned int i;
    unsigned int total;

    total = (n + 2) * nVtx;
    e->nParticles = n;
    e->particles = 0;
    e->lives = 0;
    func_800AA804(D_800F2758, &e->particles, n * sizeof(Particle), "PART_FX");
    func_800AA804(D_800F2758, &e->lives, n * sizeof(ParticleLife), "PART_LF");
    i = 0;
    while (1) {
        if (!(i < n)) {
            break;
        }
        e->particles[i].active = 0;
        e->lives[i].state = 0;
        e->particles[i].alpha = 255.0f;
        e->lives[i].life = -7680;
        e->particles[i].scale = 1.0f;
        vec_zero(&e->particles[i].pos);
        vec_zero(&e->particles[i].vel);
        vec_zero(&e->particles[i].acc);
        i++;
    }
    e->vtx2 = 0;
    e->vtx1 = 0;
    e->vtx0 = 0;
    e->user = user;
    e->nVtx = nVtx;
    if (nVtx != 0) {
        func_800AA804(D_800F2758, &e->vtx0, (unsigned short)total * sizeof(ParticleVtx), "PARTVTX");
        e->vtxIndex = 0;
        e->vtxCount = 0;
        e->vtx1 = e->vtx0 + nVtx;
        e->vtx2 = e->vtx1 + nVtx;
        e->flags |= 0x80;
    }
}
