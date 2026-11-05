typedef struct {
    short delta;
    short index;
    void (*fn)(char *);
} VEntry;

typedef struct {
    char pad[180];
    VEntry *vtable;
    char pad2[28];
} Actor;

typedef struct {
    char pad[11088];
    Actor actors[12][3];
} Stage;

extern int D_80103430[];
extern int D_80103450[];
extern void func_800ADC1C(char *);
extern void func_8001A248(int *);

void func_800DF828(Stage *obj)
{
    unsigned char i;
    unsigned char j;

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 3; j++) {
            (obj->actors[i] + j)->vtable[9].fn((char *)&obj->actors[i][j] +
                                               (obj->actors[i] + j)->vtable[9].delta);
        }
    }
    func_800ADC1C((char *)obj + 18720);
    for (i = 0; i < 6; i++) {
        if (D_80103430[i] != 0) {
            func_8001A248(&D_80103430[i]);
            D_80103430[i] = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        if (D_80103450[i] != 0) {
            func_8001A248(&D_80103450[i]);
            D_80103450[i] = 0;
        }
    }
}
