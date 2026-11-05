extern unsigned char D_800F1B84[];
extern void func_8001E024(void *list, void *node);

void func_800C02B4(void **object)
{
    void *node = object[28];

    func_8001E024(D_800F1B84, node);
}
