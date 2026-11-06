/* Event-bank state handler (link VRAM 0x800737D4), ROM 0x76B34..0x76DA4. */
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    u8 pad0[0x18];
    s16 delta;
    void (*fn)(void *);
} Thunk;

typedef struct {
    u8 pad0[0x68];
    s32 volume;
} Bank;

extern void *D_80070C18[];
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern s32 D_800F2728;
extern u8 D_800F3BC0[];
extern Bank D_800F1AE0;

extern void func_800AB2A4(void *, s32, s32, void *, s32, s32);
extern void func_800C013C(void *);
extern void func_800ADC1C(void *);
extern void func_80075610(void *);
extern void func_80075A2C(void *);
extern void func_8008382C(void *);
extern void func_800D29E0(void *);
extern void func_8001D550(void *, s32);
extern s32 func_8001D4B8(void *, s32, s32, s32);
extern void func_8001D640(void *, s32, s32);
extern void func_8001D5D8(void *, s32, s32, s32, s32, s32);
extern void func_800AC25C(void *, s32, s32, s32);

#define W(o) (*(s32 *)(ctx + (o)))

void func_80076B34(u8 *ctx)
{
    u8 *hi = ctx + 0x10000;
    u8 state;
    s32 snd;
    s32 k;

    if (*(s32 *)(hi + 0xD48) != 0) {
        W(0xD950) = 0;
        func_800AB2A4(D_800F26E0, D_800F2744, 7, ctx, 0, 9);
    }
    state = ctx[0x614];
    if (state == 2) {
        D_800F2728 = 0;
        *(s32 *)(hi + 0xB08) = -7680;
        *(s32 *)(hi + 0xB10) = 0;
        W(0x4C0) = 0;
        W(0x610) = 26;
        func_800C013C(D_800F3BC0);
        return;
    }
    if (state == 5) {
        u8 *obj = ctx + 0x10A2C;
        Thunk *t;
        func_800ADC1C(obj);
        t = *(Thunk **)(obj + 0xB4);
        t->fn(obj + t->delta);
        obj[0xB0] = 0;
        func_80075610(ctx);
        return;
    }
    if (ctx[0x4BC] == 0 && state != 3 && W(0x610) != 28) {
        u8 *p;
        *(s32 *)(hi + 0xB10) = 1;
        func_80075A2C(ctx);
        p = ctx + 0x630;
        if (*(s32 *)(p + 0x2E0) != 0) {
            func_8008382C(p);
        }
        p = ctx + 0x6FC0;
        if (*(s32 *)(p + 0x2E0) != 0) {
            func_8008382C(p);
        }
        func_800D29E0(ctx + 0x103C8);
        func_80075610(ctx);
        return;
    }
    {
        static void *const unused_tbl[] = { &&start, &&clear, &&end };
        unsigned int i = W(0x610) - 1;
        if (i >= 28) goto end;
        goto *D_80070C18[i];
    }
start:
    func_800D29E0(ctx + 0x103C8);
    func_800C013C(D_800F3BC0);
    if (ctx[0x614] != 4) {
        func_8001D550(&D_800F1AE0, 1);
    }
    k = 19660;
    snd = func_8001D4B8(&D_800F1AE0, 95, 0, -1);
    func_8001D640(&D_800F1AE0, snd, 0);
    func_8001D5D8(&D_800F1AE0, snd, (D_800F1AE0.volume * k) >> 15, 1, 0, 0);
    *(s32 *)(ctx + 0x10D58) = snd;
    func_800AC25C(ctx, 56, 17, 0);
    W(0x4C0) = 0x9600;
    W(0x610) = 8;
    return;
clear:
    W(0x4C0) = 0;
end:
    ;
}
