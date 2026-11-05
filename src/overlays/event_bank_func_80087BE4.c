extern void func_800CB7A8(void *obj, float x, float y);

typedef struct EventBankObj {
    unsigned char pad0[1555];
    unsigned char entryCount;
    unsigned char pad1[16672 - 1556];
    unsigned char *entries[8];
} EventBankObj;

void func_80087BE4(EventBankObj *object)
{
    unsigned char i;
    unsigned char *entry;

    i = 0;
loop:
    if (i < object->entryCount) {
        entry = object->entries[i];
        if (entry != 0) {
            func_800CB7A8(entry + 1036, -27.85194969177246f, 16.383499145507812f);
        }
        i++;
        goto loop;
    }
}
