extern int D_800FFDF0;
extern void func_800EA6D0(void *object, void *value);
extern void func_800EA9C4(void *object, void *value);
extern void func_800E9D10(void *object);

void func_800EADFC(unsigned char *object, const int *event)
{
    if (event[0] == 5) {
        func_800EA6D0(object, object + 220);
        func_800EA9C4(object, object + 332);
        func_800E9D10(object);
    }
    D_800FFDF0++;
}
