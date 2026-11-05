typedef unsigned char u8;
typedef unsigned int u32;

u8 *func_80021494(u8 *context, u8 *stream)
{
    *(u32 *)(context + 0x84) = 0;
    return stream;
}
