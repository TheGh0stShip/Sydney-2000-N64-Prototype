typedef struct Game {
    char pad0[0x4FC];
    float limit_default;
    char pad500[0x528 - 0x500];
    float limit_mode4;
    char pad52C[0xA00 - 0x52C];
    int mode;
    char padA04[0xDE4 - 0xA04];
    float limit_mode5;
} Game;

typedef struct Obj {
    char pad0[0x30C];
    int over;
    int over_mode4;
} Obj;

extern Game *D_800FC270;

int func_800F96D8(Obj *obj, float value)
{
    obj->over = 0;
    obj->over_mode4 = 0;
    switch (D_800FC270->mode) {
    case 5:
        if (D_800FC270->limit_mode5 < value) {
            obj->over = 1;
            return 1;
        }
        break;
    case 4:
        if (D_800FC270->limit_mode4 < value) {
            obj->over_mode4 = 1;
            return 1;
        }
    default:
        if (D_800FC270->limit_default < value) {
            obj->over = 1;
            return 1;
        }
        break;
    }
    return 0;
}
