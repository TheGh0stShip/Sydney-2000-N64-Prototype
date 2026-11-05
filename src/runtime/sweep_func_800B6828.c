extern void func_800AE568(void *object);
extern void func_800B6400(void *object);
extern unsigned char D_80086990[];

void *func_800B6828(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_80086990;
    func_800B6400(object);
    return object;
}
