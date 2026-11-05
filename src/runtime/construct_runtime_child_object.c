/* func_800B3E44: base construction, dispatch installation and child setup. */
typedef struct {
    unsigned char base[0xB4];
    const void *dispatch;
} RuntimeChildObject;
typedef char child_constructor_pointer[sizeof(void *) == 4 ? 1 : -1];
extern const unsigned int runtimeChildDispatch[];
extern void func_800AE568(void *);
extern void func_800B3BF8(void *);
RuntimeChildObject *func_800B3E44(RuntimeChildObject *object) {
    func_800AE568(object);
    object->dispatch = runtimeChildDispatch;
    func_800B3BF8(object);
    return object;
}
