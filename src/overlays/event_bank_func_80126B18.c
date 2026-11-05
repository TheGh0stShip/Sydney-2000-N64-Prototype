extern void func_8007BA78(void *object);

typedef struct {
    char pad[26984];
    void *items[3];
} Owner;

void func_80126B18(Owner *object)
{
    unsigned char i;

    for (i = 0; i < 3; i++) {
        func_8007BA78(object->items[i]);
    }
}
