extern void func_80074664(void *obj, int arg);
extern float func_8007AF50(void *res);
extern void func_80074B14(void *obj, float value);
extern void func_800762A8(void *obj, int arg);

void func_8009BF10(char *obj)
{
    func_80074664(obj, 1);
    func_80074B14(obj, func_8007AF50(*(void **)(obj + 12136)));
    func_800762A8(obj, 1);
}
