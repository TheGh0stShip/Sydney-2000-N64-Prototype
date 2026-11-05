typedef struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *self);
} VEntry;

typedef struct Element {
    char pad00[0xB4];
    VEntry *vtable;
    char padB8[0x0C];
    int active;
    char padC8[0x0C];
} Element;

typedef struct Game {
    char pad000[0xD58];
    unsigned char mode;
} Game;

typedef struct Scene {
    char pad0000[0xC4];
    unsigned int elementCount;
    Element *elements;
    int hasExtra;
    char pad00D0[0x2EC - 0xD0];
    char partA[0x3C0 - 0x2EC];
    char partB[0x494 - 0x3C0];
    char panel[0x9BC - 0x494];
    char menu[0xB60 - 0x9BC];
    char cursor[0x1480 - 0xB60];
    char extraPanel[1];
} Scene;

extern char D_800F2758[];
extern Game *D_800FC270;

extern void func_800E5788(void *p);
extern void func_800A6334(Scene *scene);
extern void func_800AC308(Element *e);
extern void func_800ADE84(void *p, int arg);
extern void func_800AA658(void *list, Element **elements);
extern void func_800A69E8(void *p);
extern void func_800A6C28(void *p);
extern void func_800AC334(void *p);
extern void func_800A731C(void *p);
extern void func_800A7418(void *p);
extern void func_800ADC1C(void *p);
extern int func_80017D54(void);

void func_80119800(Scene *scene) {
    unsigned int i;
    VEntry *vt;

    func_800E5788((char *)scene + 0xD0);
    func_800A6334(scene);
    if (scene->elements != 0) {
        for (i = 0; i < scene->elementCount; i++) {
            if (scene->elements[i].active != 0) {
                func_800AC308(&scene->elements[i]);
                vt = scene->elements[i].vtable;
                vt[3].fn((char *)&scene->elements[i] + vt[3].delta);
                func_800ADE84(&scene->elements[i], 2);
            }
        }
        func_800AA658(D_800F2758, &scene->elements);
    }
    if (D_800FC270->mode == 2) {
        func_800A69E8(scene->panel);
        func_800AC334(scene->panel);
        if (scene->hasExtra != 0) {
            func_800A6C28(scene->extraPanel);
            func_800AC334(scene->extraPanel);
        }
    }
    func_800A731C(scene->menu);
    func_800AC334(scene->menu);
    func_800A7418(scene->cursor);
    func_800AC334(scene->cursor);
    func_800ADC1C(scene->partA);
    func_800ADC1C(scene->partB);
    func_800A731C(scene->menu);
    func_800AC334(scene->menu);
    if (func_80017D54() != 0) {
        func_800A69E8(scene->panel);
        func_800AC334(scene->panel);
    }
}
