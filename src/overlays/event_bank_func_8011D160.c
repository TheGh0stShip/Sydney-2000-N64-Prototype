extern void func_800AACB0(void *list, void *object, int flags);
extern char D_800F26E0[];

void func_8011D160(unsigned char *object)
{
    object[288] = 0;
    object[289] = 0;
    *(int *)(object + 192) |= 4;
    func_800AACB0(D_800F26E0, object, 15);
}
