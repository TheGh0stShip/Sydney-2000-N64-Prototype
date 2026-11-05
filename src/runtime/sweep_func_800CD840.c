extern void func_8001A248(void *slot);

void func_800CD840(unsigned char *object)
{
    if (*(void **)(object + 424) != 0) {
        func_8001A248(object + 424);
    }
    *(void **)(object + 424) = 0;
    if (*(void **)(object + 428) != 0) {
        func_8001A248(object + 428);
    }
    *(void **)(object + 428) = 0;
    if (*(void **)(object + 480) != 0) {
        func_8001A248(object + 480);
    }
    *(void **)(object + 480) = 0;
}
