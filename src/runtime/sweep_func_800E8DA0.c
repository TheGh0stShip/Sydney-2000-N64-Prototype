typedef struct {
    short offset;
    short pad;
    void (*func)(void *, void *);
} VEntry800E8DA0;

extern void func_800C0300(void *);
extern void func_800C0AD4(void *, void *, void *);
extern void func_800E9A48(void *, int);
extern void func_800C8120(void *, void *, void *);
extern void func_8008C030(void);
extern char D_800F5900[];
extern char D_800FF4F4[];
extern char D_800FF504[];
extern char D_800FF514[];
extern char D_800FF524[];
extern char D_800FF534[];
extern char D_800FF4BC[];
extern char D_800FF4CC[];

void func_800E8DA0(char *obj)
{
    char *sub;
    VEntry800E8DA0 *v;

    sub = obj + 23368;
    *(int *)(obj + 28536) = -1;
    func_800C0300(sub);
    v = (VEntry800E8DA0 *)(*(char **)(sub + 180) + 16);
    v->func(sub + v->offset, D_800F5900);
    *(char *)(sub + 176) = 1;
    func_800C0AD4(obj + 24632, obj, D_800FF4F4);
    func_800C0AD4(obj + 24864, obj, D_800FF504);
    func_800C0AD4(obj + 25096, obj, D_800FF514);
    func_800C0AD4(obj + 25328, obj, D_800FF524);
    func_800C0AD4(obj + 25560, obj, D_800FF534);
    *(int *)(obj + 28536) = 5;
    func_800C0AD4(obj + 25792, obj, D_800FF4BC);
    func_800C0AD4(obj + 26024, obj, D_800FF4CC);
    func_800E9A48(obj, 0);
    func_800C8120(obj + 28540, obj, (void *)func_8008C030);
}
