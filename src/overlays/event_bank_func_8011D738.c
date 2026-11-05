extern void func_80080C54();

void func_8011D738(unsigned char *object, int *event)
{
    switch (event[0]) {
    case 3:
        break;
    case 5:
        func_80080C54();
        break;
    }
    *(int *)(object + 16) = event[1];
}
