extern int D_800FFE00;
extern void func_800EAF30(void *object, void *value);
extern void func_800EB38C(void *object, void *value);
extern void func_800EBE1C(void *object, void *value);
extern void func_800E9D10(void *object);

void func_800EBEB0(unsigned char *object, const int *event)
{
    if (event[0] == 5) {
        func_800EAF30(object, object + 588);
        func_800EB38C(object, object + 504);
        func_800EBE1C(object, object + 616);
        func_800E9D10(object);
    }
    D_800FFE00++;
}
