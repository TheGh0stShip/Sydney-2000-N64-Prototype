extern void func_8007B95C(void *);
extern void func_800B9FA4(void *, int, int, float, int, int);
extern void func_800B9E9C(void *, int, int, float, int);

void func_800FE3D8(unsigned char *object) {
    float scale;
    unsigned char *bytes;
    int next_state;

    func_8007B95C(object);
    scale = *(float *)0x80078C94;
    func_800B9FA4(object, 6, -1, scale, 0, 1);
    func_800B9E9C(object, 6, -1, scale, 0);

    bytes = *(unsigned char **)(object + 648);
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    bytes[3] = 0;
    bytes[4] = 0;
    bytes[5] = 0;
    bytes[6] = 0;
    bytes[7] = 0;

    bytes = *(unsigned char **)(object + 644);
    *(unsigned short *)(bytes + 2) = 0;
    next_state = 5;
    *(int *)(object + 172) = next_state;
}
