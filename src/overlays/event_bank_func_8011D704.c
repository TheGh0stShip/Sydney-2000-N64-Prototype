extern void func_800B9E9C(void *object, int value, int mode, float scale,
                         int extra);

void func_8011D704(unsigned char *object)
{
    *(int *)(object + 172) = 1;
    *(int *)(object + 436) = 1;
    func_800B9E9C(object, 0, -1, 1.0f, 0);
}
