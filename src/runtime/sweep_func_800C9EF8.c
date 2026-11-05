struct Sound {
    char pad[104];
    int volume;
};

struct Pip {
    char pad[196];
    int color;
};

struct Meter {
    char pad[204];
    struct Pip *pips[93];
    int onColor;
    int offColor;
    unsigned char level;
    unsigned char maxLevel;
};

extern struct Sound D_800F1AE0;
extern int func_8001D4B8(struct Sound *, int, int, int);
extern void func_8001D640(struct Sound *, int, int);

void func_800C9EF8(struct Meter *self, unsigned char level)
{
    unsigned char i;

    if (level > self->maxLevel) {
        level = self->maxLevel;
    }
    if (self->level == level) {
        return;
    }
    for (i = 0; i < level; i++) {
        self->pips[i]->color = self->onColor;
    }
    for (i = level; i < self->maxLevel; i++) {
        self->pips[i]->color = self->offColor;
    }
    if (self->level < level) {
        int handle = func_8001D4B8(&D_800F1AE0, 204, 0, 1);

        func_8001D640(&D_800F1AE0, handle, (int)((long long)D_800F1AE0.volume * 32767) >> 15);
    }
    self->level = level;
}
