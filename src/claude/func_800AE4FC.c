extern void func_800AED04(void *obj);

void func_800AE4FC(char *obj)
{
    *(int *)(obj + 0xBC) = 1;
    *(float *)(obj + 0xF4) = 1.5707964f;
    *(int *)(obj + 0x10C) = 0;
    *(int *)(obj + 0xB8) = 0;
    *(int *)(obj + 0x0) = 2;
    func_800AED04(obj + 0x124);
    *(short *)(obj + 0xC4) = 0;
    *(int *)(obj + 0xC8) = 0;
    *(float *)(obj + 0xF8) = 1.0f / 30.0f;
    *(float *)(obj + 0xFC) = 1.0f;
}
