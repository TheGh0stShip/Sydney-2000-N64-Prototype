extern char D_800F2AD8[];
extern char D_800F26E0[];
extern int D_800F2744;
extern char D_800F1AE0[];
extern void func_8000F420(void);
extern void func_800BC274(char *);
extern void func_800AACB0(char *, char *, int);
extern void func_800AB2A4(char *, int, int, int, int, int);
extern void func_800177F8(void);
extern void func_800BC2B8(char *, char *);
extern void func_800D4B30(char *);
extern void func_800B31EC(int);
extern int func_8001D6CC(void *, int, int, int);
extern void func_8001D640(void *, int, int);
extern void func_800A3404(char *, int);
extern void func_800B4794(int);

void func_800D47A0(char *obj)
{
    int voice;
    char *mgr;
    unsigned char kind;

    *(int *)(obj + 644) = 0;
    if (*(int *)(obj + 648) == 0) {
        return;
    }
    func_8000F420();
    mgr = D_800F2AD8;
    func_800BC274(mgr);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    if (*(int *)(obj + 2752) == 2) {
        func_800BC2B8(D_800F2AD8, obj + 2060);
    } else {
        if (*(int *)(obj + 2764) != 0) {
            *(int *)(obj + 2764) = 0;
        }
        kind = *(unsigned char *)(obj + 2320);
        if (kind == 1) {
            goto normal;
        } else if (kind == 2) {
            if (*(int *)(obj + 2752) == 1) {
                func_800AB2A4(D_800F26E0, D_800F2744, 7, *(int *)(obj + 640), 0, 55);
            } else {
                func_800AB2A4(D_800F26E0, D_800F2744, 7, *(int *)(obj + 640), 0, 7);
            }
            func_800177F8();
            goto done;
        } else {
        normal:
            if (*(int *)(obj + 2752) == 1) {
                func_800AB2A4(D_800F26E0, D_800F2744, 7, *(int *)(obj + 640), 0, 56);
            } else {
                func_800AB2A4(D_800F26E0, D_800F2744, 7, *(int *)(obj + 640), 0, 8);
            }
            func_800BC2B8(D_800F2AD8, obj + 2060);
        }
    }
done:
    func_800D4B30(obj);
    func_800B31EC(*(int *)(obj + 2748));
    if (*(int *)(obj + 2772) != -1) {
        voice = func_8001D6CC(D_800F1AE0, *(int *)(obj + 2772), 0, 0);
        func_8001D640(D_800F1AE0, voice,
                      (int)((long long)*(int *)(D_800F1AE0 + 100) * 32767) >> 15);
    }
    func_800A3404(D_800F1AE0, 0);
    func_800B4794(0);
    *(int *)(obj + 648) = 0;
}
