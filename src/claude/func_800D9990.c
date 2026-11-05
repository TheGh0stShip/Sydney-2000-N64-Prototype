/* Runtime-stage C reconstruction: reset the resident mixer voice table. */
typedef struct {
    short level;          /* 0x00 */
    char pad02[0x0A];
    unsigned char active; /* 0x0C */
    unsigned char index;  /* 0x0D */
    char pad0E[0x26];
    int handle;           /* 0x34 */
    signed char owner;    /* 0x38 */
    char pad39[3];
} MixVoice;

typedef struct {
    char pad0[0x14];
    MixVoice voices[8];   /* 0x14 */
    char pad1F4[0x1FC - 0x1F4];
    unsigned char flagA;  /* 0x1FC */
    unsigned char flagB;  /* 0x1FD */
    unsigned char flagC;  /* 0x1FE */
    char pad1FF;
    int count;            /* 0x200 */
} MixSettings;

extern MixSettings *D_800FC270;

void func_800D9990(void) {
    unsigned char i;
    D_800FC270->flagA = 0;
    D_800FC270->flagB = 0;
    D_800FC270->flagC = 0;
    D_800FC270->count = 0;
    for (i = 0; i < 8; i++) {
        D_800FC270->voices[i].level = 0;
        D_800FC270->voices[i].active = 0;
        D_800FC270->voices[i].index = i;
        D_800FC270->voices[i].handle = 0;
        D_800FC270->voices[i].owner = -1;
    }
}
