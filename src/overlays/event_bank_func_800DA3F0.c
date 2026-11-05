extern int D_800F2714;
extern char *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *a, int b, int c, int d);

typedef struct {
    char pad[20188];
    char *recs[4];
} RecTable;

void func_800DA3F0(char *obj)
{
    char *rec;
    unsigned char k;
    char *ent;
    int sound;

    rec = ((RecTable *)obj)->recs[*(unsigned char *)(obj + 1548)];
    k = *(unsigned char *)(rec + 733);
    ent = obj + k * 20;
    if (*(short *)(ent + 24766) == 1)
        return;
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    sound = 233;
    if ((unsigned int)D_800F2714 >> 28 < 4)
        sound = 159;
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    if ((unsigned int)D_800F2714 >> 28 >= 2) {
        if (*(int *)(ent + 24760) < 4609)
            sound += 1;
        else
            sound -= 8;
        sound += k;
    }
    if (*(int *)(D_800FC270 + 2564) != 0 && *(int *)(obj + 24968) == 1) {
        func_800C0110(D_800F3BC0, sound, 0, 0);
    }
}
