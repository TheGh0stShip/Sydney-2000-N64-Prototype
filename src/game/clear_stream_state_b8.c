typedef unsigned char u8;

u8 *func_80020E90(u8 *context, u8 *stream)
{
    context[0xB8] = 0;
    return stream;
}
