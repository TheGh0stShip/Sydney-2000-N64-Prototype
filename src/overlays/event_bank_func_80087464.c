typedef struct {
    int v[8];
    short s0;
    short flag;
} Slot;

typedef struct {
    char pad0[0x613];
    unsigned char count;
    char pad614[0x52F0 - 0x614];
    Slot slots[8];
} Obj;

void func_80087464(Obj *obj)
{
    int minA = 0x119400;
    int minB = 0x119400;
    int minC = 0x119400;
    int minD = 0x119400;
    unsigned char i;

    for (i = 0; i < obj->count; i++) {
        if (obj->slots[i].flag != 1) {
            if (obj->slots[i].v[0] < minA) {
                minA = obj->slots[i].v[0];
            }
            if (obj->slots[i].v[6] < minB) {
                minB = obj->slots[i].v[6];
            }
            if (obj->slots[i].v[2] < minC) {
                minC = obj->slots[i].v[2];
            }
            if (obj->slots[i].v[4] < minD) {
                minD = obj->slots[i].v[4];
            }
        }
    }
    for (i = 0; i < obj->count; i++) {
        if (obj->slots[i].flag != 1) {
            obj->slots[i].v[1] = obj->slots[i].v[0] - minA;
            obj->slots[i].v[7] = obj->slots[i].v[6] - minB;
            obj->slots[i].v[3] = obj->slots[i].v[2] - minC;
            obj->slots[i].v[5] = obj->slots[i].v[4] - minD;
        }
    }
}
