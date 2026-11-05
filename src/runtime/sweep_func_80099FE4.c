typedef struct VtEntry {
    short offset;
    short pad;
    void (*func)(void *, ...);
} VtEntry;

#define VCALL(o, slot) ((VtEntry *)*(void **)((char *)(o) + 180))[slot].func((char *)(o) + ((VtEntry *)*(void **)((char *)(o) + 180))[slot].offset)

typedef struct Row {
    char *a;
    void *anim;
    char *c;
    char *d;
    char *e;
    char *f;
    char *g;
} Row;

extern void func_800B35F0(void *object);
extern void func_800AC334(void *object);
extern void func_800ADC1C(void *object);
extern void func_800CC310(void *object);
extern void func_800B2158(void *object, int value);

void func_80099FE4(unsigned char *self)
{
    unsigned char i;
    unsigned char *sub;
    Row *row;

    if (self[4492] & 0x1E) {
        func_800B35F0(self + 2344);
        func_800AC334(self + 2344);
        func_800B35F0(self + 2124);
        func_800AC334(self + 2124);
        func_800B35F0(self + 1904);
        func_800AC334(self + 1904);
        func_800ADC1C(self + 140);
        func_800ADC1C(self + 352);
        func_800ADC1C(self + 564);
        sub = self + 2564;
        sub[1927] &= 0xFB;
        func_800CC310(sub);
        func_800ADC1C(self + 776);
        func_800ADC1C(self + 988);
        func_800ADC1C(self + 1200);
        func_800ADC1C(self + 1412);
    }
    if (self[4492] & 1) {
        i = 0;
next:
        if (i < self[4493]) {
            row = (Row *)(self + 1680) + i;
            VCALL(row->g, 9);
            VCALL(row->a, 9);
            func_800B2158(row->anim, 0);
            VCALL(row->d, 9);
            VCALL(row->e, 9);
            VCALL(row->c, 9);
            VCALL(row->f, 9);
            i++;
            goto next;
        }
    }
    self[4492] = 0;
    self[4495] = 0;
}
