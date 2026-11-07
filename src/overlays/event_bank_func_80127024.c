/* Event-bank: select the active participant and accumulate timed score. */
#define F(p, o) (*(float *)((char *)(p) + (o)))
#define I(p, o) (*(int *)((char *)(p) + (o)))
#define P(p, o) (*(char **)((char *)(p) + (o)))

#define D_80081434 (30.0f)
#define D_80081438 (256.0f)

void func_80127024(char *self, int unused, int which)
{
    switch (which) {
    case 0:
        I(self, 0x804) = 0;
        I(self, 0x800) = I(self, 0x6974);
        I(P(self, 0x696C), 0xAD8) = 0;
        I(P(self, 0x696C), 0xBE4) = 1;
        I(self, 0x7FC) = 1;
        P(self, 0x6974) = P(self, 0x696C);
        break;
    case 1:
        I(self, 0x804) = 0;
        I(self, 0x800) = I(self, 0x6974);
        I(P(self, 0x6968), 0xAD8) = 0;
        I(P(self, 0x6968), 0xBE4) = 1;
        I(self, 0x7FC) = 1;
        P(self, 0x6974) = P(self, 0x6968);
        break;
    case 2:
        break;
    }
}

unsigned short func_80127098(char *self, unsigned int value)
{
    char *game = P(self, 4);
    int ok;

    if (I(self, 0x280) == 0) {
        I(self, 0x280) = value;
    }
    if ((int)value >= I(self, 0x280)) {
        value = *(unsigned int *)(game + 0x610);
        ok = 0;
        if (value >= 12) {
            ok = value < 23;
        }
        if (ok) {
            float rate;
            float sixty;
            float factor;

            if (*(unsigned short *)(self + 0x27E) & 1) {
                *(unsigned short *)(self + 0x27E) = 2;
            } else {
                *(unsigned short *)(self + 0x27E) = 1;
            }
            rate = F(self, 0x808);
            sixty = D_80081434;
            factor = D_80081438;
            I(self, 0x280) += (int)(sixty / rate * factor);
        }
    }
    return *(unsigned short *)(self + 0x27E);
}
