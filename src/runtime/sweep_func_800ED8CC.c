extern int D_800FFE10;
extern void func_800ED354(void *object, void *value);
extern void func_800ECF40(void *object, void *value);
extern void func_800ECAF0(void *object, void *value);
extern void func_800E9D10(void *object);

void func_800ED8CC(unsigned char *object, const int *event)
{
    if (event[0] == 5) {
        func_800ED354(object, object + 220);
        func_800ECF40(object, object + 192);
        func_800ECAF0(object, object + 248);
        func_800E9D10(object);
    }
    D_800FFE10++;
}
