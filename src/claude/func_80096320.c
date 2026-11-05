/* Runtime-stage C reconstruction: initialize a runtime object, install its handler and mark it active. */
typedef struct RuntimeObject {
    int active;
    char unused4[0xB0];
    void (*handler)(void);
} RuntimeObject;

extern RuntimeObject runtimeObject;
extern void func_800AC3D4(RuntimeObject *object);
extern void func_80084218(void);

void func_80096320(void) {
    func_800AC3D4(&runtimeObject);
    runtimeObject.handler = func_80084218;
    runtimeObject.active = 1;
}
