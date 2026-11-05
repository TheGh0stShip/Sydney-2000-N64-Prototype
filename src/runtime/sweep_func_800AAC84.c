extern void func_800B3870(void *destination, const void *source, unsigned int size);

void func_800AAC84(void *unused, void **source, void **destination, unsigned int size)
{
    (void)unused;
    func_800B3870(destination[1], source[1], size);
}
