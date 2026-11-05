extern unsigned char D_800FFD30;
extern void func_800EA184(void *object);
extern void func_800EA4B0(void *object);
extern void func_800EA5FC(void *object);

void func_800EBF14(unsigned char *object)
{
    func_800EA184(object + 448);
    func_800EA184(object + 476);
    func_800EA184(object + 588);
    func_800EA184(object + 560);
    func_800EA184(object + 504);
    func_800EA184(object + 532);
    func_800EA184(object + 616);
    func_800EA4B0(object);
    func_800EA5FC(&D_800FFD30);
}
