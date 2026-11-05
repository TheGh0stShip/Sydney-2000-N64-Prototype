extern void func_800BE630(void *object);

void func_800BF36C(unsigned char *object, void *value, unsigned char state)
{
    object[380] = state;
    *(void **)(object + 376) = value;
    func_800BE630(object);
}
