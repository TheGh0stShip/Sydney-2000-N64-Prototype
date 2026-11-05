/* func_800B41C0: base construction, dispatch installation and child setup. */
typedef struct {
    unsigned char base[0xB4];
    const void *dispatch;
} RuntimeChildObject;
typedef char child_constructor_pointer[sizeof(void *) == 4 ? 1 : -1];
extern const unsigned int runtimeAnimationDispatch[];
extern void func_800AE568(void *);
extern void func_800B3E88(void *);
RuntimeChildObject *func_800B41C0(RuntimeChildObject *object) {
    func_800AE568(object);
    object->dispatch = runtimeAnimationDispatch;
    func_800B3E88(object);
    return object;
}
