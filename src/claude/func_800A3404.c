/* Runtime-stage C reconstruction: toggle a resident service once per state change, then refresh the object. */
extern int runtimeServiceEnabled;
extern void func_8001D770(void *);
extern void func_8001D6D8(void *object);
extern void func_800A330C(void *object);
int func_800A3404(void *object, int enable) {
    if (enable) {
        if (!runtimeServiceEnabled) {
            func_8001D770(object);
            runtimeServiceEnabled = 1;
        }
    } else {
        if (runtimeServiceEnabled) {
            func_8001D6D8(object);
            runtimeServiceEnabled = 0;
        }
    }
    func_800A330C(object);
    return 1;
}
