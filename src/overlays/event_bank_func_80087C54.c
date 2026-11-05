extern void func_800CB838(void *obj, float value);

typedef struct EventBankObj {
    unsigned char pad0[1555];
    unsigned char entryCount;
    unsigned char pad1[16672 - 1556];
    unsigned char *entries[8];
} EventBankObj;

void func_80087C54(EventBankObj *object, float value)
{
    unsigned char i;
    unsigned char *entry;

    i = 0;
loop:
    if (i < object->entryCount) {
        entry = object->entries[i];
        if (entry != 0) {
            func_800CB838(entry + 1036, value);
        }
        i++;
        goto loop;
    }
}
