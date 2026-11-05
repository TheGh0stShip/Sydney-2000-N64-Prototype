struct Sound {
    char pad[104];
    int volume;
};

struct Cue {
    char pad[1908];
    unsigned char state;
    char pad2[3];
    int arg0;
    int arg1;
    unsigned char flag0;
    unsigned char flag1;
};

extern struct Sound D_800F1AE0;
extern int func_8001D4B8(struct Sound *, int, int, int);
extern void func_8001D640(struct Sound *, int, int);

void func_800D0C20(struct Cue *self, int a, int b, unsigned char c, unsigned char d)
{
    int handle;

    self->arg0 = a;
    self->arg1 = b;
    self->flag0 = c;
    self->state = 5;
    self->flag1 = d;
    handle = func_8001D4B8(&D_800F1AE0, 195, 0, 0);
    func_8001D640(&D_800F1AE0, handle, (int)((long long)D_800F1AE0.volume * 32767) >> 15);
}
