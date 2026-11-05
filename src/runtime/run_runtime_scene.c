/* Runtime scene setup, execution and cleanup. Rebuilt byte-exact against
 * func_800F0980: 0x4E0 text bytes and eight literal bytes at 0x8008CC48.
 * Target ABI: big-endian MIPS o32, with 32-bit pointers and integers. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 off; s16 pad; void (*fn)(); } VEntry;

typedef struct {
    void *pool;
    u8 *items;
    u8 **slots;
    u8 **cursor;
    u16 capacity;
    u16 count;
} FreeList;

typedef struct { u8 pad[0x18]; s32 depth; } Clock;

extern FreeList runtimeFreeList;
extern u8 commandContext[];
extern u8 runtimeOutputQueue[];
extern Clock runtimeClock;
extern void *sceneRoot;
extern s32 D_80100114[];
typedef struct { s32 pad[4]; s32 kind; } SceneDesc;
extern SceneDesc D_80100168;
extern char D_8008CBF8[], D_8008CC00[], D_8008CC28[], D_8008CC30[], D_8008CC38[], D_8008CC40[];
extern u8 D_8008A168[];

extern void func_800D28B0(void *);
extern s32 func_800AA804(void *, void *, s32, char *);
extern u8 *func_800AAA58(s32, void *);
extern void func_800AC3D4(void *);
extern void func_800AE568(void *);
extern void func_80017D84(char *, s32);
extern void func_800DAD10(void *, s32, s32, s32);
extern void func_800AA658(void *, void *);
extern void func_800ADC54(void *, s32);
extern void func_800D33A0(void *, void *, s32, s32);
extern void func_800ADED4(void *);
extern void func_80019680(void *, char *);
extern void func_8001A1D8(void *, f32, f32, f32, f32);
extern void func_8001A3AC(void *, s32);
extern void func_8001A210(void *, f32, f32, f32, f32, s32);
extern void func_800AB81C(void *, void *);
extern void func_800AB580(void *);
extern void func_80017820(s32, s32, s32, s32);
extern void func_80017860(s32);
extern void func_80014A2C(s32);
extern void func_800047E0(s32);
extern void func_80017D7C(void);
extern void func_800D29E0(void *);
extern void func_800AC334(void *);
extern void func_800DB124(s32);
extern void func_8001A248(void *);
extern void func_800D3460(void *, s32);

typedef char check_scene_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char check_scene_integer_width[sizeof(s32) == 4 ? 1 : -1];
typedef char check_scene_virtual_entry[sizeof(VEntry) == 8 ? 1 : -1];
typedef char check_scene_free_list[sizeof(FreeList) == 0x14 ? 1 : -1];
typedef char check_scene_clock[sizeof(Clock) == 0x1C ? 1 : -1];
typedef char check_scene_description[sizeof(SceneDesc) == 0x14 ? 1 : -1];

#define VT(o, n) ((VEntry *)(*(u8 **)((u8 *)(o) + 0xB4) + (n)))

void func_800F0980(u32 arg0)
{
    u8 scene[0x578];
    u8 *a;
    u8 *b;
    s32 models[1];
    s32 flag;
    u8 *o;
    u32 i;
    FreeList *fl;
    s32 *m;
    s32 *modelBase;
    s32 n;
    f32 k;
    f32 z;

    if (arg0 < 21) {
        flag = 0;
        a = 0;
        b = 0;
        func_800D28B0(scene);
        func_800AA804(commandContext, &a, 0x284, D_8008CBF8);
        o = func_800AAA58(0x284, a);
        n = 5;
        func_800AC3D4(o);
        *(void **)(o + 0xB4) = D_8008A168;
        *(s32 *)(o + 0xD8) = 1;
        func_800AE568(o + 0xDC);
        *(s32 *)(o + 0x280) = 0;
        func_80017D84(D_8008CC00, -1);
        func_800DAD10(commandContext, 300, flag, 1);
        fl = &runtimeFreeList;
        if (fl->pool == 0) {
            fl->pool = commandContext;
            fl->capacity = n;
            if (func_800AA804(commandContext, &fl->slots, 0x14, D_8008CC28) == 0 &&
                func_800AA804(commandContext, &fl->items, 0x44C, D_8008CC30) == 0) {
                u8 *p = fl->items;
                fl->cursor = fl->slots;
                do {
                    *fl->cursor = p;
                    p += 0xDC;
                    fl->cursor++;
                    fl->count++;
                } while ((u16)--n);
            } else {
                void *pool = fl->pool;
                if (pool) {
                    fl->pool = 0;
                    if (fl->items) func_800AA658(pool, &fl->items);
                    if (fl->slots) func_800AA658(pool, &fl->slots);
                    fl->capacity = 0;
                    fl->count = 0;
                    fl->cursor = 0;
                    fl->pool = 0;
                }
            }
        }
        VT(a, 0x40)->fn(a + VT(a, 0x40)->off, 0, 1);
        {
            u8 *s = scene;
            u8 *aa = a;
            VT(s, 0x10)->fn(s + VT(s, 0x10)->off, aa);
            func_800ADC54(s, 1 << *(s32 *)(aa + 0xD8));
            s[0xB0] = 1;
            D_80100168.kind = D_80100114[arg0];
            /* The sentinel scene preserves the constructor's flag byte. */
            if (D_80100114[arg0] != 0x59) {
                *(s32 *)(s + 0x1F8) = 2;
                func_800D33A0(s, &D_80100168, 0, -1);
                flag = 1;
                s[0xB1] = flag;
            }
        }
        func_800AA804(commandContext, &b, 0xD4, D_8008CC38);
        i = 0;
        modelBase = models;
        m = modelBase;
        z = 0.0f;
        k = 1.0f;
    top:
        if (i == 0) {
            func_800ADED4(func_800AAA58(0xD4, b));
            *modelBase = 0;
            func_80019680(m, D_8008CC40);
            func_8001A1D8(m, z, z, 602.0f, 240.0f);
            func_8001A3AC(m, 0x7F00);
            *(u32 *)(b + 0xC0) |= 0x20000;
            b[0xC9] = 0;
            func_8001A210(m, z, z, k, k, 0);
            func_800ADC54(b, 2);
            {
                register u8 *object __asm__("v1") = b;
                *(u32 *)(object + 0xC0) |= 2;
                *(s32 *)(object + 0xC4) = *modelBase;
                VT(object, 0x40)->fn(object + VT(object, 0x40)->off);
            }
            i++;
            goto top;
        }
        runtimeClock.depth++;
        func_800AB81C(runtimeOutputQueue, sceneRoot);
        func_800AB580(runtimeOutputQueue);
        runtimeClock.depth--;
        func_80017820(0, 0, 0, 0);
        func_80017860(1);
        func_80014A2C(-1);
        func_800047E0(flag);
        func_80017D7C();
        func_800D29E0(scene);
        func_800AC334(scene);
        fl = &runtimeFreeList;
        {
            void *pool = fl->pool;
            if (pool) {
                u8 *items = fl->items;
                fl->pool = 0;
                if (items) func_800AA658(pool, &fl->items);
                if (fl->slots) func_800AA658(pool, &fl->slots);
                fl->capacity = 0;
                fl->count = 0;
                fl->cursor = 0;
                fl->pool = 0;
            }
        }
        func_800DB124(1);
        VT(a, 0x48)->fn(a + VT(a, 0x48)->off);
        for (i = 0; i < 1; i++) {
            func_8001A248(&models[i]);
            {
                u8 *q = (u8 *)((u32)(i * 0xD4) + (u32)b);
                VT(q, 0x8)->fn(q + VT(q, 0x8)->off, 2);
            }
        }
        func_800AA658(commandContext, &b);
        func_800AA658(commandContext, &a);
        func_800D3460(scene, 2);
    }
}
