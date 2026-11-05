extern unsigned char D_800F2758[];
extern void func_800AA658(void *, void *);

struct Owner {
    char pad[18956];
    void *slots[12];
};

void func_800E4234(struct Owner *self)
{
    unsigned int i = 0;

    do {
        if (self->slots[i] != 0) {
            func_800AA658(D_800F2758, &self->slots[i]);
            self->slots[i] = 0;
        }
        i++;
    } while (i < 12);
}
