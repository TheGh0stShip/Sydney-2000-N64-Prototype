typedef unsigned char u8;
extern void func_8001A114(void *, int);
extern void func_80017DF0(int);
typedef struct { u8 pad[28]; u8 *e; } Mdl;
void func_8007EE04(u8 *o, int *a)
{
    if (a[0] == 5) {
        *(u8 **)(o + 1844) = (*(Mdl **)(o + 332))->e + 84;
        *(u8 **)(o + 1364) = (*(Mdl **)(o + 332))->e + 84;
        if (o[336]) {
            if (-6.5533996f < *(float *)((*(Mdl **)(o + 332))->e + 88)) {
                o[336] = 0;
                func_8001A114(o + 936, 0);
                func_80017DF0(0);
            }
        } else if (*(float *)((*(Mdl **)(o + 332))->e + 88) < -6.5533996f) {
            o[336] = 1;
            func_8001A114(o + 936, 1);
            func_80017DF0(1);
        }
    }
    *(int *)(o + 16) = a[1];
}
