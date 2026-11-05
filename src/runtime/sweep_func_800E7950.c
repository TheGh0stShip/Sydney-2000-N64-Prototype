extern void *D_800F2770;
extern void func_80017C4C(void *, int, void **);
extern void func_800E6194(void *, void *, void *, void *, void *);

void func_800E7950(char *object)
{
    void *result;

    if (D_800F2770 != 0) {
        func_80017C4C(*(void **)(object + 196), 0, &result);
        func_800E6194(object + 220,
                      *(void **)(object + 196),
                      result,
                      *(void **)(object + 212),
                      *(void **)(object + 216));
    }
}
