/* Copy a24-byte record from the second argument into the third argument. */
extern void func_800B3870(void *destination, const void *source, unsigned int size);
void func_800AB004(void *unused, const void *source, void *destination) {
    func_800B3870(destination, source, 24);
}
