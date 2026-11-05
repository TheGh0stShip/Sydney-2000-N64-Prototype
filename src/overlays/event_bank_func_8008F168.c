typedef struct EventState {
    char pad0[2564];
    int soundEnabled;
} EventState;

extern EventState *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *bank);

void func_8008F168(void)
{
    if (D_800FC270->soundEnabled) {
        func_800C0110(D_800F3BC0);
    }
}
