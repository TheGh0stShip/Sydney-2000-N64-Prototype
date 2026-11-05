typedef struct {
    char data[220];
} Widget;

typedef struct {
    short unk0;
    short width;
    char pad[20];
} Layout;

extern Widget D_801028B0[11];
extern Layout D_800F57DC[];
extern void func_800B2158(Widget *, int);
extern void func_800B3214(Widget *, int);
extern void func_8001A1D8(char *, float, float, float, float);

void func_800D4C24(char *obj, int mode)
{
    *(int *)(obj + 2752) = mode;
    *(int *)(obj + 2764) = 0;
    if (*(int *)(obj + 2752) == 2) {
        *(unsigned char *)(obj + 2320) = 6;
        *(unsigned char *)(obj + 2761) = 6;
        func_800B2158(&D_801028B0[7], 0);
        func_800B2158(&D_801028B0[9], 0);
        func_800B2158(&D_801028B0[8], 0);
        func_800B2158(&D_801028B0[0], 0);
        func_800B2158(&D_801028B0[1], 0);
        func_800B2158(&D_801028B0[2], 0);
        func_800B2158(&D_801028B0[3], 1);
        func_800B2158(&D_801028B0[4], 1);
        func_800B2158(&D_801028B0[5], 1);
        func_800B2158(&D_801028B0[6], 1);
        func_800B3214(&D_801028B0[3], 0x80000);
        func_800B3214(&D_801028B0[4], 0x80000);
        func_800B3214(&D_801028B0[5], 0x80000);
        func_800B3214(&D_801028B0[6], 0x80000);
        func_8001A1D8(obj + 2520, -301.0f, -120.0f, 301.0f, 120.0f);
    } else {
        *(unsigned char *)(obj + 2320) = 1;
        *(unsigned char *)(obj + 2761) = 1;
        func_800B2158(&D_801028B0[0], 1);
        func_800B2158(&D_801028B0[1], 1);
        func_800B2158(&D_801028B0[2], 1);
        func_800B3214(&D_801028B0[0], 0x80000);
        func_800B3214(&D_801028B0[1], 0x80000);
        func_800B3214(&D_801028B0[2], 0x80000);
        func_800B2158(&D_801028B0[3], 0);
        func_800B2158(&D_801028B0[4], 0);
        func_800B2158(&D_801028B0[5], 0);
        func_800B2158(&D_801028B0[6], 0);
        func_8001A1D8(obj + 2520, -159.0f, -40.0f, 159.0f, 40.0f);
    }
    *(float *)(obj + 2700) = D_800F57DC[*(unsigned char *)(obj + 2320)].width - 2.0f;
    *(float *)(obj + 2624) = D_800F57DC[*(unsigned char *)(obj + 2320)].width - 2.0f;
}
