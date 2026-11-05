typedef void (*Method)(void *object, int arg);
extern void func_800B3870(void *dst, void *src, int size);

void func_800A851C(unsigned char *owner, int index, int arg, void *src)
{
    unsigned char *child = *(unsigned char **)((index << 2) + owner + 268);
    unsigned char *vt = *(unsigned char **)(child + 180);
    child[176] = 1;
    (*(Method *)(vt + 20))(child + *(short *)(vt + 16), arg);
    func_800B3870(child + 96, src, 76);
}
