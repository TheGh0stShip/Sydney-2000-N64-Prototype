/* Runtime-stage C reconstruction: tear down the resident overlay cache and optionally reset the pool. */
typedef struct {
    void *pool;   /* 0x00 */
    void *bufA;   /* 0x04 */
    void *bufB;   /* 0x08 */
    int size;     /* 0x0C */
    short countA; /* 0x10 */
    short countB; /* 0x12 */
} OverlayCache;

extern OverlayCache D_800FCB30;
extern char D_800F2758[];
extern void func_800AA658(void *pool, void *slot);
extern void func_800DAFBC(void);
extern void func_800D9938(void *pool);

void func_800DB124(int resetPool) {
    void *pool = D_800FCB30.pool;
    if (pool != 0) {
        D_800FCB30.pool = 0;
        if (D_800FCB30.bufA != 0) {
            func_800AA658(pool, &D_800FCB30.bufA);
        }
        if (D_800FCB30.bufB != 0) {
            func_800AA658(pool, &D_800FCB30.bufB);
        }
        D_800FCB30.countA = 0;
        D_800FCB30.countB = 0;
        D_800FCB30.size = 0;
        D_800FCB30.pool = 0;
    }
    func_800DAFBC();
    if (resetPool) {
        func_800D9938(D_800F2758);
    }
}
