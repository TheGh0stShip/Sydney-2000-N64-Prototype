extern char D_800F2AD8[];
extern void func_800BBD78(void *list, int id, int on, void *owner, int kind);
extern void func_800BC180(void *list);
extern void func_800D771C(void *obj);
extern void func_8009B0E4(int id, int a, void *obj, int b, int c, int d, int e);

void func_80078FE0(char *self)
{
    unsigned char slot = self[0x10B04] << 1;

    func_800BBD78(D_800F2AD8, 12, 1, self, 2);
    func_800BBD78(D_800F2AD8, 13, 1, self, 2);
    func_800BC180(D_800F2AD8);
    func_800D771C(self + 0xD954);
    *(int *)(self + 1552) = 28;
    *(int *)(self + 1216) = 0x1C200;
    func_8009B0E4(235, 0, self + 0xD954, 4, 1, 0, slot);
}
