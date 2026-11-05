extern char D_80071478[];
extern char D_8008C578[];
extern char D_80071568[];
extern char D_8008C140[];
extern char D_80086598[];
extern char D_8008A490[];
extern void func_800AC3A4(void *object, int flags);
extern void func_800ADDA4(void *object, int flags);
extern void func_800CE380(void *object, int flags);
extern void func_800A9C2C(void *object, int flags);
extern void func_800D8170(void *object, int flags);
extern void func_800ADE84(void *object, int flags);
extern void func_800CCE84(void *object, int flags);
extern void func_8007E190(void *object, int flags);
extern void func_800D3460(void *object, int flags);
extern void func_800AE4D8(void *object, int flags);

typedef struct {
    int pad0;
    int pad4;
    short delta;
    short pad10;
    void (*dtor)(void *object, int flags);
} VEntry;

#define VTBL(obj) (*(void **)((char *)(obj) + 180))

static inline void destroy_array(char *first, char *end, int size)
{
    if (first != 0 && first != end) {
        char *stop = first;
        do {
            VEntry *entry;
            end -= size;
            entry = *(VEntry **)(end + 180);
            entry->dtor(end + entry->delta, 2);
        } while (stop != end);
    }
}

static inline void destroy_base(char *object)
{
    VTBL(object) = D_80086598;
    func_800ADDA4(object, 2);
}

static inline void destroy_view(char *object, char *self)
{
    VTBL(object) = D_8008C578;
    *(char **)(self + 25996) = D_80071568;
    *(char **)(self + 25968) = D_80071568;
    VTBL(object) = D_8008C140;
    func_800AC3A4(object, 2);
}

void func_800B6440(char *self, int flags)
{
    char *member;
    char *list;

    VTBL(self) = D_80071478;
    destroy_view(self + 25728, self);
    destroy_base(self + 25508);
    list = self + 23512;
    destroy_base(self + 25284);
    destroy_base(self + 25064);
    destroy_base(self + 24844);
    destroy_base(self + 24624);
    func_800CE380(self + 24412, 2);
    func_800ADDA4(self + 24200, 2);
    func_800ADDA4(self + 23988, 2);
    func_800ADDA4(self + 23776, 2);
    func_800ADDA4(list, 2);
    func_800AC3A4(self + 23228, 2);
    func_800A9C2C(self + 22984, 2);
    func_800D8170(self + 22564, 2);
    func_800ADE84(self + 22340, 2);
    func_800ADE84(self + 22128, 2);
    func_800ADE84(self + 21916, 2);
    destroy_array(self + 21296, self + 21912, 308);
    func_800CCE84(self + 21076, 2);
    func_8007E190(self + 19020, 2);
    destroy_array(self + 14820, self + 19020, 1400);
    func_800D3460(self + 13420, 2);
    func_800D3460(self + 12020, 2);
    destroy_base(self + 11784);
    member = self + 916;
    VTBL(member) = D_8008A490;
    destroy_array(self + 1156, self + 11756, 212);
    VTBL(member) = D_80086598;
    func_800ADDA4(member, 2);
    func_800ADE84(self + 696, 2);
    func_800AE4D8(self + 216, 2);
    func_800AC3A4(self, flags);
}
