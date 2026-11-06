typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct VEntry {
    s16 pad0[8];
    s16 offset;
    s16 pad12;
    void (*fn)(void *, void *);
} VEntry;

extern void *D_800F1A44;
extern void func_800A1538(void *obj, s32 id, void *data, s32 flag);
extern void func_800A13A0(void *obj, float scale);

void func_8007B3C4(u8 *ctx)
{
    u8 i;
    u8 *hi;
    s32 c8000;
    u8 *sp_;
    u8 *sq;
    s32 two;
    s32 c8cdc;
    s32 flag;
    s32 off;
    u8 *obj;
    VEntry *v;

    i = 0;
    c8000 = 0x8000;
    hi = ctx + c8000;
    two = 2;
    c8cdc = 0x8CDC;
    D_800F1A44 = *(void **)(ctx + 0x536C);
loop:
    if (i < 11) {
        if (*(s32 *)((sp_ = ctx + i * 36) + c8000 + 0x2238) == 0) {
            i = 11;
            goto loop;
        }
        flag = 0;
        do {
            if (hi[0xC9D] == 5) {
                goto set1;
            }
        } while (0);
        if ((*(u8 **)(ctx + 0x536C))[0x1AA] == two ||
            (*(u8 **)(ctx + 0x536C))[0x1AA] == 3) {
set1:
            flag = 1;
        }
        if (hi[0xC9D] == two) {
            flag = 0;
        }
        off = i * 496;
        obj = ctx + (off + c8cdc);
        func_800A1538(obj, *(u8 *)((sq = ctx + i * 36) + c8000 + 0x223B),
                      ctx + (i * 36 + 0xA22C), flag ^ 1);
        i++;
        func_800A13A0(obj, 55.0f);
        v = *(VEntry **)((u8 *)off + (s32)ctx + c8cdc + 0xB4);
        v->fn(obj + v->offset, ctx);
        goto loop;
    }
}
