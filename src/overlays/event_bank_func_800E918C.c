typedef struct {
    float m[16];
    float pos[3];
} EventXform;

typedef struct {
    char pad0[0x14];
    EventXform xf;
    char pad60[0xAC - 0x60];
    int state;
    char padB0[0x170 - 0xB0];
    float target[3];
    char pad17C[0x278 - 0x17C];
    float scale;
    char pad27C[0x49C - 0x27C];
    float home[3];
} EventActor;

extern void func_800B8C70(EventActor *, float);
extern void func_800B9FA4(EventActor *, int, int, float, int, int);
extern void func_800B9E9C(EventActor *, int, int, float, int);
extern void func_800AD434(void *, float, int);

void func_800E918C(EventActor *a, unsigned char mode)
{
    EventXform *xf;
    float one;
    float *p;

    a->scale = *(float *)0x80078A90;
    func_800B8C70(a, a->scale);
    a->state = 35;
    if (mode == 0) {
        func_800B9FA4(a, 78, -1, a->scale, 0, 1);
    } else if (mode == 1) {
        func_800B9FA4(a, 79, -1, a->scale, 0, 1);
    } else if (mode == 2) {
        func_800B9FA4(a, 80, -1, a->scale, 0, 1);
    }
    func_800B9E9C(a, 78, -1, a->scale, 0);
    xf = &a->xf;
    one = *(float *)0x80078A94;
    xf->m[9] = 0.0f;
    xf->m[8] = 0.0f;
    xf->m[6] = 0.0f;
    xf->m[4] = 0.0f;
    xf->m[2] = 0.0f;
    xf->m[1] = 0.0f;
    xf->pos[2] = 0.0f;
    xf->pos[1] = 0.0f;
    xf->pos[0] = 0.0f;
    xf->m[10] = one;
    xf->m[5] = one;
    xf->m[0] = one;
    func_800AD434(xf, 3.1415923f, 3);
    a->home[1] = *(float *)0x80078A98;
    p = a->home;
    xf->pos[0] = p[0];
    xf->pos[1] = p[1];
    xf->pos[2] = p[2];
    p = a->target;
    p[0] = xf->pos[0];
    p[1] = xf->pos[1];
    p[2] = xf->pos[2];
}
