/* func_800B3BF8, ROM 0x1574E8: extend the base object constructor. */
typedef unsigned int u32;
typedef struct {
    unsigned char base[0xC0];
    u32 state;
    unsigned char gapC4[0x28];
    u32 pending;
    u32 mode;
    unsigned char gapF4[0x30];
    u32 child[1];
} ExtendedRuntimeObject;
typedef char check_extended_child[(unsigned long)&((ExtendedRuntimeObject *)0)->child == 0x124 ? 1 : -1];
typedef char check_extended_word[sizeof(u32) == 4 ? 1 : -1];
extern void func_800AE4FC(void *);
extern void func_800AED04(void *);
void func_800B3BF8(ExtendedRuntimeObject *object) {
    func_800AE4FC(object);
    object->pending = 0;
    object->mode = 3;
    func_800AED04(object->child);
    object->state = 0;
}
