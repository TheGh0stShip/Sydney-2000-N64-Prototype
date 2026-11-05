extern void func_800C7570(void);

void func_800C7AB8(unsigned char *object, int *event)
{
    if (event[0] == 5 && *(unsigned short *)(object + 1760) == 1) {
        if (*(unsigned int *)(object + 1756) >= 15) {
            func_800C7570();
        } else {
            *(unsigned int *)(object + 1756) += 1;
        }
    }
    *(int *)(object + 16) = event[1];
}
