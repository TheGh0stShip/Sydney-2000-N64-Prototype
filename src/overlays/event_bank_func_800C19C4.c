typedef struct Key { unsigned short pad0; unsigned short time; char pad4[36]; } Key;
typedef struct Track { char pad0[28]; Key *keys; } Track;
typedef struct Anim {
    char pad0[244]; Track *track; char pad248[4]; unsigned short frame;
    char pad254[10]; int key;
} Anim;
typedef struct Obj {
    char pad0[4552]; Anim anim; char pad4820[17592 - 4820]; int state;
    char pad17596[8]; int active; char pad17608[4]; int value;
    char pad17616[2]; unsigned short length;
} Obj;
#define D_80070988 (*(float *)0x80070988)
#define D_8007098C (*(float *)0x8007098C)
#define D_80070990 (*(float *)0x80070990)
void func_800C19C4(Obj *obj)
{
    Anim *a = &obj->anim;
    float one = D_80070988;
    float q;
    int v;

    q = (float)(unsigned short)(a->frame - a->track->keys[a->key].time) / (float)obj->length;
    q = one - q;
    obj->state = 0;
    obj->active = 1;
    v = (int)(q * D_8007098C * D_80070990);
    obj->value = v;
    if (v > 11520) obj->value = 11520;
}
