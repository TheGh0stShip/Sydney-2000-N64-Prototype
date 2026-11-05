typedef struct {
    short delta;
    short index;
    void (*func)(void *self, int mode);
} VEntry;

extern unsigned char D_80086598[];
extern void func_800ADDA4(void *object, int mode);
extern void func_800CE380(void *object, int mode);
extern void func_800CD8A0(void *object, int mode);
extern void func_80004380(void *object);

#define DESTROY(p) \
    (*(VEntry **)((p) + 180))[1].func((p) + (*(VEntry **)((p) + 180))[1].delta, 2)

#define DESTROY_ARRAY(base, end, size) \
    do { \
        unsigned char *first_ = (base); \
        if (first_ != 0) { \
            unsigned char *p_ = (end); \
            if (first_ != p_) { \
                unsigned char *stop_ = first_; \
                do { \
                    p_ -= (size); \
                    DESTROY(p_); \
                } while (stop_ != p_); \
            } \
        } \
    } while (0)

void func_800AF528(unsigned char *object, int flags)
{
    unsigned char *part;

    func_800ADDA4(object + 5048, 2);
    DESTROY_ARRAY(object + 4412, object + 5048, 212);
    func_800ADDA4(object + 4200, 2);
    DESTROY_ARRAY(object + 3564, object + 4200, 212);
    DESTROY_ARRAY(object + 2928, object + 3564, 212);
    {
        unsigned char *member = object + 2704;

        *(void **)(member + 180) = D_80086598;
        func_800ADDA4(member, 2);
    }
    func_800CE380(object + 2492, 2);
    func_800CD8A0(object + 1584, 2);
    part = object + 1324;
    *(void **)(part + 180) = D_80086598;
    func_800ADDA4(part, 2);
    DESTROY_ARRAY(object + 664, object + 1324, 220);
    DESTROY_ARRAY(object + 4, object + 664, 220);
    if (flags & 1) {
        func_80004380(object);
    }
}
