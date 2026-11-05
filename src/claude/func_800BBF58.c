typedef struct {
    int targetA;
    int targetB;
    int rateA;
    int rateB;
    signed char valueA;
    signed char valueB;
    short timerA;
    short timerB;
    char pad[2];
} Channel;

typedef struct {
    int a;
    int b;
} Slot;

extern Slot D_800F2A70[];
extern Channel D_800F2AD8[];
extern int D_800F2C14;
extern void func_800BC450(void *);

void func_800BBF58(void)
{
    int i;
    Slot *s;
    Channel *c;
    Channel *base;
    int j;

    s = D_800F2A70;
    for (i = 12; i != -1; i--) {
        func_800BC450(s);
        s++;
    }
    base = D_800F2AD8;
    c = base;
    for (j = 12; j != -1; j--) {
        c->targetA = 0;
        c->targetB = 0;
        c->rateA = 3;
        c->rateB = 3;
        c->valueA = -1;
        c->valueB = -1;
        c->timerA = 0;
        c->timerB = 0;
        c++;
    }
    base[13].targetA = 0;
    D_800F2C14 = 1234;
}
