typedef struct VEntry {
    short offset;
    short pad;
    void (*fn)();
} VEntry;

typedef struct VObject {
    char pad[176];
    unsigned char active;
    char pad2[3];
    VEntry *vtbl;
} VObject;

typedef struct ListSlot {
    void *list;
    void *first;
    void *second;
    int count;
    short a;
    short b;
} ListSlot;

extern unsigned char D_800F2AD8[];
extern unsigned char D_800F26E0[];
extern unsigned char D_800F2758[];
extern unsigned char D_800F4D00[];
extern unsigned char D_80076530[];
extern unsigned char D_80076540[];
extern unsigned char D_800F7270[];
extern ListSlot D_800F26B0;

extern void func_8009BDC4(unsigned char *state);
extern void func_800BC274(void *object);
extern void func_800BC0B4(void);
extern void func_800AACB0(void *list, void *object, int mode);
extern void func_800AC25C(unsigned char *state, int a, int b, int c);
extern void func_800AA658(void *list, void *slot);
extern void func_800D29E0(void *object);
extern void func_800AC334(void *object);
extern void func_800D6EA0(void *object);
extern void func_800D771C(void *object);
extern void func_800CE594(void);
extern void func_80073498(unsigned char *state);
extern void func_800ADC1C(void *object);
extern void func_800CCE4C(void *object);
extern void func_800D52A8(void *object);
extern void func_80017B24(int value);
extern void func_800BAC24(void);
extern void func_800AEFA0(void *object);
extern void func_8007E098(void *object);
extern void func_800D7F5C(void *object);
extern void func_8009C100(void);


void func_80076244(unsigned char *state)
{
    unsigned char *sceneA;
    unsigned char *sceneB;
    VObject *camera;
    VObject *hud;
    VEntry *vt;
    unsigned char *sub;
    unsigned char *menu;
    unsigned char *slots;
    int *slot;
    unsigned int i;
    void *list;

    func_8009BDC4(state);
    func_800BC274(D_800F2AD8);
    func_800BC0B4();
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_800AC25C(state, 107, 7, 0);
    if (*(int *)(state + 1564) != 0) {
        func_800AA658(D_800F2758, state + 1564);
    }

    sceneA = state + 0x103C8;
    func_800D29E0(sceneA);
    func_800AC334(sceneA);

    sceneB = state + 0x10940;
    func_800D6EA0(sceneB);
    func_800AC334(sceneB);

    camera = (VObject *)(state + 0xD954);
    func_800D771C(camera);
    camera->vtbl[3].fn((char *)camera + camera->vtbl[3].offset);
    camera->active = 0;
    func_800CE594();
    func_80073498(state);

    hud = (VObject *)(state + 0x10A2C);
    func_800ADC1C(hud);
    hud->vtbl[3].fn((char *)hud + hud->vtbl[3].offset);
    hud->active = 0;
    func_800CCE4C(hud);
    func_800D52A8(D_800F4D00);

    vt = ((VObject *)(state + 252))->vtbl;
    sub = state + 252;
    vt[3].fn(sub + vt[3].offset);
    func_80017B24(*(int *)(state + 184));
    if ((unsigned int)(state[1556] - 2) >= 3) {
        vt = ((VObject *)(state + 628))->vtbl;
        sub = state + 628;
        vt[3].fn(sub + vt[3].offset);
        func_80017B24(*(int *)(state + 216));
    }
    func_800BAC24();

    menu = state + 1224;
    func_800AEFA0(D_80076530);
    func_800AEFA0(D_80076540);
    func_800AC334(menu);
    func_8007E098(menu);

    slots = state + 0x10B20;
    func_800AEFA0(D_800F7270);
    func_800D7F5C(slots);
    slot = (int *)slots;
    for (i = 0; i < 8; i++) {
        slot[46] = 0;
        slot++;
    }
    func_800AC334(state + 0x10B20);

    list = D_800F26B0.list;
    if (list != 0) {
        D_800F26B0.list = 0;
        if (D_800F26B0.first != 0) {
            func_800AA658(list, &D_800F26B0.first);
        }
        if (D_800F26B0.second != 0) {
            func_800AA658(list, &D_800F26B0.second);
        }
        D_800F26B0.a = 0;
        D_800F26B0.b = 0;
        D_800F26B0.count = 0;
        D_800F26B0.list = 0;
    }
    func_8009C100();
    func_800AACB0(D_800F26E0, state, 0);
    *(int *)(state + 172) = 2;
    *(int *)(state + 1552) = 0;
}
