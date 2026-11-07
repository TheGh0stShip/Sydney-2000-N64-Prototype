typedef unsigned char u8;
typedef unsigned short u16;
extern int func_8000EB20(const char *);
extern void func_80017CF4(int, int, u16);
void func_800709B0(u8 *o)
{
    switch ((*(signed char **)(o + 18192))[*(signed char *)(o + 18180) - 1]) {
    case 0:
    case 3:
        func_80017CF4(*(int *)(o + 17564), 0, func_8000EB20("FOOTON"));
        func_80017CF4(*(int *)(o + 17780), 0, func_8000EB20("FOOTRON"));
        break;
    case 1:
    case 4:
        func_80017CF4(*(int *)(o + 17564), 0, func_8000EB20("FOOTOFF"));
        func_80017CF4(*(int *)(o + 17780), 0, func_8000EB20("FOOTRON"));
        break;
    case 2:
    case 5:
        func_80017CF4(*(int *)(o + 17564), 0, func_8000EB20("FOOTON"));
        func_80017CF4(*(int *)(o + 17780), 0, func_8000EB20("FOOTROFF"));
        break;
    }
}
