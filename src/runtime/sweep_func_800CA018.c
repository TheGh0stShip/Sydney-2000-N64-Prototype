extern void func_800C9C9C(void);
extern void func_800C99FC(void *object);

void func_800CA018(unsigned char *object, int *event)
{
    if (event[0] == 5) {
        switch (*(int *)(object + 604)) {
        case 1:
            func_800C9C9C();
        case 0:
            if (object[586] == 0 && *(int *)(object + 588) != 0) {
                func_800C99FC(object);
            }
            break;
        }
    }
    *(int *)(object + 16) = event[1];
}
