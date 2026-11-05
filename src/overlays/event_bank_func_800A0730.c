extern unsigned int D_800F13F0;
extern char D_800F1AE0[];
extern void func_8001D5D0(void *channel, int handle, int value);

static inline unsigned int event_random(int range)
{
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    return ((D_800F13F0 >> 15) * range) >> 16;
}

void func_800A0730(char *self)
{
    int step;

    if (*(int *)(self + 24112) == -1) {
        return;
    }
    if (*(unsigned char *)(self + 24120) == 0) {
        step = event_random(1200);
        if (step & 1) {
            if (*(int *)(self + 24116) - step > 8100) {
                step = -step;
            }
        } else if (*(int *)(self + 24116) + step > 36100) {
            step = -step;
        }
        *(unsigned char *)(self + 24120) = 4;
        *(int *)(self + 24116) += step;
        func_8001D5D0(D_800F1AE0, *(int *)(self + 24112), *(int *)(self + 24116));
    } else {
        *(unsigned char *)(self + 24120) -= 1;
    }
}
