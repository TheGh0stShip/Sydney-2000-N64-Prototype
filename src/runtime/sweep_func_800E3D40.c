typedef struct { unsigned char b[4]; float f[4]; } Ent;
typedef struct {
    char p0[1528];
    unsigned char s0[12];
    unsigned char s1[12];
    Ent e0[8];
    Ent e1[8];
    Ent e2[8];
    Ent e3[8];
    Ent e4[8];
    unsigned char s2[12];
    Ent e5[5];
    unsigned char s3[4];
} Game;

extern Game *D_800FC270;

void func_800E3D40(void *self, int k, unsigned int idx, unsigned char v, float f)
{
    Ent *ep = 0;
    unsigned char *bp = 0;

    if (k == 9 || k == 11) return;
    switch (k) {
    case 0: bp = D_800FC270->s0; break;
    case 1: bp = D_800FC270->s1; break;
    case 2: ep = D_800FC270->e0; break;
    case 3: ep = D_800FC270->e1; break;
    case 4: ep = D_800FC270->e2; break;
    case 5: ep = D_800FC270->e3; break;
    case 6: ep = D_800FC270->e4; break;
    case 7: bp = D_800FC270->s2; break;
    case 8: ep = D_800FC270->e5; break;
    case 10: bp = D_800FC270->s3; break;
    }
    if (bp) bp[idx] = v;
    if (ep) {
        ep[idx >> 2].b[idx & 3] = v;
        ep[idx >> 2].f[idx & 3] = f;
    }
}
