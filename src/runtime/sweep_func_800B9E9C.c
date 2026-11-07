typedef struct { unsigned short u0, u2, u4, u6; char pad[32]; } Entry;
typedef struct { char pad[28]; Entry *entries; } Bank;
typedef struct {
    char pad0[0xF4];
    Bank *bank;           /* 0xF4 */
    char padf8[0x130 - 0xF8];
    int index;            /* 0x130 */
    int f134;             /* 0x134 */
    unsigned int f138;    /* 0x138 */
    unsigned int f13c;    /* 0x13C */
    int f140;             /* 0x140 */
    int flags;            /* 0x144 */
} Voice;
int func_800B9E9C(Voice *v, int index, int arg2, float pitch, unsigned int frame)
{
    Bank *bank = v->bank;
    unsigned int rate;
    v->index = index;
    v->f134 = arg2;
    rate = bank->entries[index].u6;
    if (rate & 0x8000) {
        rate &= 0x7FFF;
    } else {
        rate <<= 8;
    }
    rate = ((int)(pitch * 65536.0f) * rate) / 7680;
    v->f13c = rate;
    if (v->flags >= 0) {
        v->f138 = rate;
    }
    if (bank->entries[index].u4 >= 2) {
        if (frame >= bank->entries[index].u4 - 1) {
            frame = bank->entries[index].u4 - 2;
        }
    } else {
        frame = 0;
    }
    v->f140 = bank->entries[index].u2 + frame;
    if (v->flags & 2) {
        v->flags = (v->flags & 0x80000000) | 0x40000004;
    }
    return 0;
}
