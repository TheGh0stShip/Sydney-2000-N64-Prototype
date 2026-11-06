/* event_bank: per-slot fade/slide update for 32 actors (merges 0xba0d0..0xba53c). */
typedef struct VEntry {
    short offset;
    short pad;
    void (*fn)(void *);
} VEntry;

typedef struct VTable {
    char pad[72];
    VEntry entry;
} VTable;

typedef struct Actor {
    char pad0[20];
    char anim[64];          /* 20 */
    float pos[3];           /* 84 */
    char pad60[180 - 96];
    VTable *vt;             /* 180 */
    char padB8[212 - 184];
    char sub[288 - 212];    /* 212 */
    float savedPos[3];      /* 288 */
    int mode;               /* 300 */
    int pad130;
    int state;              /* 308 */
    int timer;              /* 312 */
    float t;                /* 316 */
} Actor;

typedef struct World {
    char pad[18564];
    Actor *actors[32];      /* 18564 */
    char pad2[18712 - 18564 - 128];
    int phase;              /* 18712 */
    char pad3[18721 - 18716];
    unsigned char lock;     /* 18721 */
} World;

typedef struct Sound {
    char pad[104];
    int volume;
} Sound;

extern Sound D_800F1AE0;
extern void func_800AEAE8(void *, Actor *);
extern void func_800AD4E0(void *, float, int);
extern void func_800AD9E8(Actor *);
extern int func_8001D4B8(Sound *, int, int, int);
extern void func_8001D640(Sound *, int, int);

static __inline__ void vec_set(float *v, float x, float y, float z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

static __inline__ void vec_copy(float *d, float *s)
{
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

static __inline__ void vec_add(float *d, float *a, float *b)
{
    d[0] = a[0] + b[0];
    d[1] = a[1] + b[1];
    d[2] = a[2] + b[2];
}

static __inline__ void vec_scale(float *v, float s)
{
    v[0] *= s;
    v[1] *= s;
    v[2] *= s;
}

void func_800BA0D0(World *w)
{
    unsigned char done = 0;
    unsigned char i = 0;
    float vec[3];
    float *pv;
    Actor *a;
    int maxVol;
    float y = 2.4575250148773193f;
    float z = -2.4575250148773193f;

    for (;;) {
        unsigned char n = i;

        if (n >= 32) {
            break;
        }
        {
            float *p = vec;

            vec[0] = 0.0f;
            p[1] = y;
            p[2] = z;
        }
        if (w->actors[i]->state != 0 && w->actors[i]->mode == 1) {
            vec_copy(w->actors[i]->pos, w->actors[i]->savedPos);
            func_800AEAE8(w->actors[i]->sub, w->actors[i]);
            vec_copy(w->actors[i]->savedPos, w->actors[i]->pos);
        }
        switch (w->actors[i]->state) {
        case 1:
            w->actors[i]->t += -0.10471975803375244f;
            if (w->actors[i]->t < 0.0f) {
                w->actors[i]->t = 0.0f;
                w->actors[i]->state = 2;
            }
            func_800AD4E0(w->actors[i]->anim, -0.10471975803375244f, 3);
            {
                float k = (1.5707961320877075f - w->actors[i]->t) / 1.5707961320877075f;

                vec[0] *= k;
                pv = vec;
                pv[1] *= k;
                pv[2] *= k;
            }
            if (w->actors[i]->mode == 1) {
                vec_add(w->actors[i]->pos, w->actors[i]->pos, vec);
            } else {
                vec_add(w->actors[i]->pos, w->actors[i]->savedPos, vec);
            }
            break;
        case 3:
            w->actors[i]->t += 0.20943951606750488f;
            if (1.5707961320877075f < w->actors[i]->t) {
                w->actors[i]->t = 1.5707961320877075f;
                w->actors[i]->state = 0;
                a = w->actors[i];
                a->vt->entry.fn((char *)a + a->vt->entry.offset);
            }
            func_800AD4E0(w->actors[i]->anim, 0.20943951606750488f, 3);
            {
                float k = (1.5707961320877075f - w->actors[i]->t) / 1.5707961320877075f;

                vec[0] *= k;
                pv = vec;
                pv[1] *= k;
                pv[2] *= k;
            }
            if (w->actors[i]->mode == 1) {
                vec_add(w->actors[i]->pos, w->actors[i]->pos, vec);
            } else {
                vec_add(w->actors[i]->pos, w->actors[i]->savedPos, vec);
            }
            break;
        case 2:
            w->actors[i]->timer -= 256;
            if (w->actors[i]->timer < 0) {
                Sound *snd = &D_800F1AE0;

                w->actors[i]->state = 3;
                maxVol = 32767;
                func_8001D640(snd, func_8001D4B8(snd, 128, 0, 1),
                              (snd->volume * maxVol) >> 15);
            }
            if (w->actors[i]->mode == 1) {
                vec_add(w->actors[i]->pos, w->actors[i]->pos, vec);
            }
            break;
        case 0:
            done++;
            break;
        }
        func_800AD9E8(w->actors[i]);
        i++;
    }
    if (done == 32 && w->lock == 0) {
        w->phase = 3;
    }
}
