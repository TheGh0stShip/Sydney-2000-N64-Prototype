typedef void (*DestroyCallback)(void *object);
typedef void (*InitializeCallback)(void *object, void *owner);

void func_800E9B18(unsigned char *owner, unsigned char *replacement)
{
    unsigned char *current = *(unsigned char **)(owner + 640);
    unsigned char *descriptor;

    if (current != replacement) {
        if (current != 0) {
            descriptor = *(unsigned char **)(current + 180);
            ((DestroyCallback)*(void **)(descriptor + 28))(
                current + *(short *)(descriptor + 24));
        }
        *(unsigned char **)(owner + 640) = replacement;
        descriptor = *(unsigned char **)(replacement + 180);
        ((InitializeCallback)*(void **)(descriptor + 20))(
            replacement + *(short *)(descriptor + 16), owner);
    }
}
