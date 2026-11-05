/* Runtime-stage C reconstruction: initialize a runtime object, install its handler, then start a companion record. */
typedef struct RuntimeObject {
    char unused0[0xB4];
    void (*handler)(void);
} RuntimeObject;

extern RuntimeObject runtimeObject;
extern char runtimeCompanion[];
extern void func_800AC3D4(RuntimeObject *object);
extern void func_800EA678(void *record);
extern void func_8008C180(void);

void func_800EA0AC(void) {
    func_800AC3D4(&runtimeObject);
    runtimeObject.handler = func_8008C180;
    func_800EA678(runtimeCompanion);
}
