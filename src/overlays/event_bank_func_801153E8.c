typedef int s32;
typedef unsigned char u8;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern u8 D_800F11A0[];
extern void func_800B4794(s32);
extern void func_8007E170(u8 *);
extern void func_8007E96C(u8 *);
extern void func_8007E834(u8 *);
extern void func_800AB2A4(u8 *, s32, s32, void *, void *, s32);
void func_8007EEA8(u8 *o, s32 *m)
{
    switch (m[0]) {
    case 3:
        func_800B4794(1);
        func_8007E170(o);
        func_800B4794(0);
        break;
    case 5:
        func_8007E96C(o);
        break;
    case 1:
        if (((u8 *)m)[17]) func_800AB2A4(D_800F26E0, D_800F2744, 7, o, 0, 0);
        break;
    case 2:
        if (((u8 *)m)[17]) func_800AB2A4(D_800F26E0, D_800F2744, 7, o, 0, 0);
        break;
    case 7:
        func_8007E834(o);
        func_800AB2A4(D_800F26E0, D_800F2744, 3, D_800F11A0, o, 0);
        break;
    case 4:
    case 6:
        break;
    }
    *(s32 *)(o + 16) = m[1];
}
