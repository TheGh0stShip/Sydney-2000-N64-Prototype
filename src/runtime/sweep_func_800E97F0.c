extern void func_800191E0(char *, unsigned int);

static __inline__ int is_active(char *sub)
{
    int on;

    on = 1;
    if (*(int *)(sub + 188) == 0) {
        on = *(int *)(sub + 184) != 0;
    }
    return on;
}

void func_800E97F0(char *obj)
{
    char *sub;
    short level;

    sub = obj + 27656;
    if (is_active(sub)) {
        if (*(short *)(obj + 27872) != 0) {
            level = *(short *)(obj + 27868) + *(short *)(obj + 27870) * *(short *)(obj + 27872);
            *(short *)(obj + 27868) = level;
            if (level > 128) {
                *(short *)(obj + 27868) = 128;
                *(short *)(obj + 27870) = -*(short *)(obj + 27870);
            } else if (level < 32) {
                *(short *)(obj + 27868) = 32;
                *(short *)(obj + 27870) = -*(short *)(obj + 27870);
            }
            level = *(short *)(obj + 27868);
            func_800191E0(obj + 27652, level | (level << 8) | (level << 16) | 0xFF000000);
        }
    }
}
