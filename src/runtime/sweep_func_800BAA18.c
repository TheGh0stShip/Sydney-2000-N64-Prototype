/* Fetch one keyframe of a track (first or last frame of the clip), reading
 * the frame index from cartridge space when the data is not resident, and
 * convert the referenced pose into the caller's matrix. */
typedef struct Clip {
    char pad[2];
    unsigned short start;
    unsigned short count;
    char pad2[40 - 6];
} Clip;

typedef struct Anim {
    char pad[4];
    char *poses;
    unsigned int frames;
    char pad2[24 - 12];
    short stride;
    char pad3[28 - 26];
    Clip *clips;
} Anim;

typedef struct Pose {
    int w[4];
} Pose;

extern void func_80011250(void *src, void *dst, int n);
extern void func_800AD1BC(Pose *p, void *out);
extern void func_800B9B5C(void *src, Pose *p);

void func_800BAA18(unsigned short clip, int first, void *out, Anim *a)
{
    Pose pose;
    unsigned short tmp;
    unsigned short *idx;
    int n;

    n = a->clips[clip].start;
    if (!first) {
        n += a->clips[clip].count - 1;
    }
    if (a->frames & 1) {
        idx = &tmp;
        func_80011250((char *)(a->frames & ~1) + n * a->stride * 2, idx, 2);
    } else {
        idx = (unsigned short *)(a->frames + n * a->stride * 2);
    }
    func_800B9B5C(a->poses + *idx * 8, &pose);
    func_800AD1BC(&pose, out);
}
