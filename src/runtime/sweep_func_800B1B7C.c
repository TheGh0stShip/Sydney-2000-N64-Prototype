typedef void (*Method)(void *object);
extern void func_800AA658(void *list, void *slot);
extern unsigned char D_800F2758[];

void func_800B1B7C(unsigned char *object)
{
    unsigned char *child = *(unsigned char **)(object + 792);
    unsigned char *vt;
    if (child != 0) {
        vt = *(unsigned char **)(child + 180);
        (*(Method *)(vt + 28))(child + *(short *)(vt + 24));
        child = *(unsigned char **)(object + 792);
        vt = *(unsigned char **)(child + 180);
        (*(Method *)(vt + 76))(child + *(short *)(vt + 72));
        func_800AA658(D_800F2758, object + 792);
        *(int *)(object + 792) = 0;
    }
}
