typedef struct {
    unsigned int index;
    char pad4[12];
    float scale[3];
    float pos[3];
    char pad28[12];
    float angle;
    float len;
    char pad3C[4];
    int type;
    char pad44[12];
    float speed;
    float arc0;
    float arc1;
} Node800F0038;

static __inline__ void vec_div_800F0038(float *p, float d)
{
    p[0] /= d;
    p[1] /= d;
    p[2] /= d;
}

void func_800F0038(char *obj)
{
    unsigned int i;

    i = 0;
    while (1) {
        if (i >= *(unsigned int *)(obj + 496)) {
            break;
        }
        (*(Node800F0038 **)(obj + 424))[i].index = i;
        (*(Node800F0038 **)(obj + 424))[i].pos[0] *= 32.767f;
        (*(Node800F0038 **)(obj + 424))[i].pos[1] *= 32.767f;
        (*(Node800F0038 **)(obj + 424))[i].pos[2] *= 32.767f;
        vec_div_800F0038((*(Node800F0038 **)(obj + 424))[i].pos, 30.0f);
        (*(Node800F0038 **)(obj + 424))[i].scale[0] *= 32.767f;
        (*(Node800F0038 **)(obj + 424))[i].scale[1] *= 32.767f;
        (*(Node800F0038 **)(obj + 424))[i].scale[2] *= 32.767f;
        (*(Node800F0038 **)(obj + 424))[i].angle =
            (*(Node800F0038 **)(obj + 424))[i].angle * 0.017453291f / 30.0f;
        (*(Node800F0038 **)(obj + 424))[i].len *= 32.767f;
        (*(Node800F0038 **)(obj + 424))[i].speed *= 32.767f;
        if ((*(Node800F0038 **)(obj + 424))[i].type == 5) {
            (*(Node800F0038 **)(obj + 424))[i].arc0 *= 0.017453291f;
            (*(Node800F0038 **)(obj + 424))[i].arc1 *= 0.017453291f;
        }
        i++;
    }
}
