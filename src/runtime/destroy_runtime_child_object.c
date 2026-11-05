/* func_800B3E20: restore this class's dispatch table before base cleanup. */
typedef struct {
    unsigned char base[0xB4];
    const void *dispatch;
} RuntimeChildObject;
typedef char child_dispatch_pointer[sizeof(void *) == 4 ? 1 : -1];
extern const unsigned int runtimeChildDispatch[];
extern void func_800AE4D8(void *);
void func_800B3E20(RuntimeChildObject *object) {
    object->dispatch = runtimeChildDispatch;
    func_800AE4D8(object);
}
