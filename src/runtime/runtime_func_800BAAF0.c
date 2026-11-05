typedef struct {
    unsigned short a0, start, length, rate;
    char pad[0x20];
} Clip;

typedef struct {
    char pad[0x14];
    float (*points)[3];
    char pad18[4];
    Clip *clips;
} Anim;

int func_800BAAF0(int index, float *pos, int *rate, unsigned short *length, Anim *anim)
{
    if (pos != 0) {
        unsigned short last = anim->clips[index].start + anim->clips[index].length - 1;
        pos[0] = anim->points[last][0];
        pos[1] = anim->points[last][1];
        pos[2] = anim->points[last][2];
    }
    if (rate != 0) {
        unsigned int r = anim->clips[index].rate;
        if (r & 0x8000) r &= 0x7FFF;
        else r <<= 8;
        *rate = (float)(unsigned int)(anim->clips[index].length << 8) / (float)r * 7680.0f;
    }
    if (length != 0) *length = anim->clips[index].length;
    return 0;
}
