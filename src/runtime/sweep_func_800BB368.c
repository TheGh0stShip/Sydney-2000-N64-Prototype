void func_800AC718(void *dst, void *src);
void func_800B48CC(void *obj, int a, int b);
void func_800BB25C(void *obj);

void func_800BB368(char *obj, int value, int keep, unsigned int mode)
{
    if (mode - 1 < 2) {
        *(int *)(obj + 380) = value;
    }
    if (mode == 0 || mode == 2) {
        func_800AC718(obj + 20, obj + 396);
        func_800B48CC(obj, value, 0);
        func_800AC718(obj + 20, obj + 412);
        *(int *)(obj + 376) = value;
        if (keep == 0) {
            *(int *)(obj + 428) = 0;
            func_800BB25C(obj);
        }
    }
}
