typedef struct ObjectFields {
    char pad0[0x68];
    short field68;
    short field6A;
    int field6C;
    char pad70[4];
    short field74;
    short field76;
} ObjectFields;

int func_80017C20(ObjectFields *object, short field68, short field6A, int field6C) {
    object->field76 = 3;
    object->field68 = field68;
    object->field6A = field6A;
    object->field6C = field6C;
    return 0;
}
