typedef struct RuntimeDestructor {
    char pad[24];
    short adjustment;
    char pad26[2];
    void (*destroy)(void *);
} RuntimeDestructor;

extern int D_800F63F0;
extern char D_800F26F4;
extern void func_80006A18(void *);
extern void func_80017B24(void *);
extern void func_800AB934(void *, void *);
extern void func_800AC308(void *);

void func_800D58E0(char *object)
{
    RuntimeDestructor *destructor;

    if (D_800F63F0 != 0) {
        func_80017B24(*(void **)(object + 184));
        func_80006A18(object + 596);
        func_800AC308(object + 220);
        func_800AC308(object);
        if (*(int *)(object + 640) == 0) {
            func_800AB934(&D_800F26F4, object);
        } else {
            destructor = *(RuntimeDestructor **)(object + 180);
            destructor->destroy(object + destructor->adjustment);
        }
        *(int *)(object + 640) = 0;
        D_800F63F0 = 0;
    }
}
