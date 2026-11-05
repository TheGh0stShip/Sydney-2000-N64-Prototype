extern unsigned char *D_800FF480;
extern unsigned char D_800FF488[];
extern unsigned char D_800F26F4[];
extern void func_800B4794(int mode);
extern void func_800E1078(void *object);
extern void func_800E8714(void *object);
extern void func_800AB9B8(void *list, void *item);
extern void func_800E90AC(void *object, int value);
extern void func_800B3178(void *data, int mode);
extern void func_800B3208(int value);

void func_800E9B88(unsigned char *object, unsigned short value)
{
    D_800FF480 = object;
    func_800B4794(1);
    func_800E1078(object + 3412);
    *(int *)(object + 636) = value;
    func_800E8714(object);
    func_800B4794(0);
    func_800AB9B8(D_800F26F4, object);
    func_800E90AC(object, value);
    func_800B3178(D_800FF488, 1);
    func_800B3208(479);
}
