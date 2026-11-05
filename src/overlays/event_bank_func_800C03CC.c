#define D_80070AE0 (*(float *)0x80070AE0)
#define D_80070AE4 (*(float *)0x80070AE4)
#define D_80070AE8 (*(float *)0x80070AE8)

typedef struct VtEntry {
    short offset;
    short pad;
    void (*func)(void *, ...);
} VtEntry;

#define VCALL(o, slot) ((VtEntry *)*(void **)((char *)(o) + 180))[slot].func((char *)(o) + ((VtEntry *)*(void **)((char *)(o) + 180))[slot].offset)

extern void func_800AEC30(void *object, float *dir, float angle);
extern float func_800AD7D0(float *v);

void func_800C03CC(unsigned char *object, float *pos, float *dir)
{
    float *target;
    float scale;

    target = (float *)(object + 20);
    target[16] = pos[0];
    target[17] = pos[1];
    target[18] = pos[2];
    func_800AEC30(object + 272, dir, -0.089290075f);
    *(int *)(object + 264) = (int)(D_80070AE0 / func_800AD7D0(dir) * D_80070AE4);
    scale = D_80070AE4;
    *(int *)(object + 268) = (int)(D_80070AE8 / func_800AD7D0(dir) * scale);
    *(int *)(object + 260) = -7680;
    *(int *)(object + 212) = 1;
    *(unsigned int *)(object + 232) &= ~0x80;
    VCALL(object, 8);
}
