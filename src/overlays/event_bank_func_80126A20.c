typedef struct {
    unsigned char pad[0x6968];
    unsigned char *entries[3];
} EventObject;

void func_80126A20(EventObject *object, float amount)
{
    int i;
    unsigned char mode = *((unsigned char *)object + 0x1AA);

    if (mode == 1 || mode == 4) {
        i = 0;
        for (;;) {
            unsigned int index = (unsigned char)i;
            unsigned char *entry;
            if (index >= 3) {
                break;
            }
            entry = object->entries[index];
            *(float *)(entry + 0xBD4) += amount;
            i++;
        }
    }
}
