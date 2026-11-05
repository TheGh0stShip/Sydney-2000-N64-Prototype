typedef struct Thing {
    unsigned char pad0[192];
    int cur;
    int last;
    unsigned char pad200[20];
    void *obj;
} Thing;

extern void func_800B4ACC(void *obj, int from, int to);

void func_800A9AE4(Thing *p, int v) {
    p->last = p->cur;
    p->cur = v;
    func_800B4ACC(p->obj, p->last, p->cur);
}
