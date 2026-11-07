typedef unsigned char u8;
extern u8 *D_800FC270;
extern void func_80075C54(u8 *);
extern void func_800A9BE8(u8 *, int);
extern void func_80099D70(u8 *, int, float);
extern void func_8009B9EC(int, int);
void func_80077590(u8 *o)
{
    if ((*(int *)(o + 25284) -= 256) <= 0) {
        switch (o[1557]) {
        case 0:
        case 1:
            func_80075C54(o);
            func_800A9BE8(o + 1116, 2);
            *(int *)(o + 25284) = 0;
            o[1551] = 3;
            break;
        case 4:
            func_80099D70(o + 20560, 1, *(int *)(D_800FC270 + 3344) / 30.0f * 0.00390625f);
        case 2:
        case 3:
            func_800A9BE8(o + 1116, 5);
            o[1551] = 7;
            break;
        case 5:
            break;
        }
    }
    func_8009B9EC(11520, 0);
}
