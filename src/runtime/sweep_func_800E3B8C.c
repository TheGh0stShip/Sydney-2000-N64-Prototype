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

unsigned char func_800E3B8C(void *self, int k, unsigned int idx)
{
    switch (k) {
    case 0: return D_800FC270->s0[idx];
    case 1: return D_800FC270->s1[idx];
    case 2: return D_800FC270->e0[idx >> 2].b[idx & 3];
    case 3: return D_800FC270->e1[idx >> 2].b[idx & 3];
    case 4: return D_800FC270->e2[idx >> 2].b[idx & 3];
    case 5: return D_800FC270->e3[idx >> 2].b[idx & 3];
    case 6: return D_800FC270->e4[idx >> 2].b[idx & 3];
    case 7: return D_800FC270->s2[idx];
    case 8: return D_800FC270->e5[idx >> 2].b[idx & 3];
    case 10: return D_800FC270->s3[idx];
    }
    return 0;
}
