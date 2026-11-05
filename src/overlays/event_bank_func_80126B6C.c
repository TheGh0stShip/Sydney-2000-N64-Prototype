extern float D_8008142C;

void func_80126B6C(unsigned char *object)
{
    if (object[0x1AA] != 4) {
        unsigned char *entry = object + 0x4384;
        entry[0x787] ^= 12;
    }
    *(float *)(object + 0x30C) = D_8008142C;
}
