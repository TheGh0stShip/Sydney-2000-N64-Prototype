extern void func_800CE594(void *self);
extern void func_800CD840(void *object);
extern void func_8001A248(void *handle);

typedef struct Holder {
    char pad[1544];
    void *a[3];
    void *b[3];
    void *c;
    void *d;
    void *e;
    void *f;
    char sub[1];
} Holder;

#define RELEASE(h) if ((h) != 0) { func_8001A248(&(h)); } (h) = 0

void func_80097A30(Holder *self)
{
    unsigned char i;

    func_800CE594(self);
    func_800CD840(self->sub);
    for (i = 0; i < 3; i++) {
        RELEASE(self->a[i]);
        RELEASE(self->b[i]);
    }
    RELEASE(self->c);
    RELEASE(self->d);
    RELEASE(self->e);
    RELEASE(self->f);
}
