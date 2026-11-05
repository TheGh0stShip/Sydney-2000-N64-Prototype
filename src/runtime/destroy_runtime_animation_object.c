/* func_800B419C: restore this class's dispatch table before base cleanup. */
typedef struct {
    unsigned char base[0xB4];
    const void *dispatch;
} RuntimeChildObject;
typedef char child_dispatch_pointer[sizeof(void *) == 4 ? 1 : -1];
extern const unsigned int runtimeAnimationDispatch[];
extern void func_800AE4D8(void *);
void func_800B419C(RuntimeChildObject *object) {
    object->dispatch = runtimeAnimationDispatch;
    func_800AE4D8(object);
}
