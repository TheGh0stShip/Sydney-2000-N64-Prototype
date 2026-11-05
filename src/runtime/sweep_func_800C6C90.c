extern unsigned char D_800FD158[];
extern unsigned char D_80102010[];

void func_800C6C90(unsigned char *object)
{
    unsigned char *state = *(unsigned char **)(*(unsigned char **)(object + 220) + 28);

    state[2] = 0;
    state[1] = 0;
    *(void **)(object + 220) = D_800FD158;
    D_80102010[state[0]] = 1;
    state[3] = 1;
}
