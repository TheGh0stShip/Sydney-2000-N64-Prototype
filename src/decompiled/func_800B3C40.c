#include "sydney_types.h"

/* Shuts down the race scene: stops sounds and effects, hides and frees all of its parts. */
typedef struct {
    s16 delta;
    s16 index;
    void (*func)(void *);
} VtEntry;

typedef struct {
    u8 pad00[0xB0];
    u8 unk_B0;
    u8 padB1[3];
    VtEntry *vtable;
} Node;

typedef struct {
    Node node;
    s32 unk_B8[8];
} Holder;

typedef struct {
    void *heap;
    void *objs;
    void *stack;
    void **sp;
    u16 cap;
    u16 count;
} Pool;

typedef struct {
    u8 pad0[0xAC];
    s32 unk_AC;
    u8 padB0[0x8];
    s32 unk_B8;
    u8 padBC[0x1C];
    u8 unk_D8[4];
    u8 padDC[0x2B8];
    Node unk_394;
    u8 pad44C[0x29BC];
    Node unk_2E08;
    u8 pad2EC0[0x34];
    Node unk_2EF4;
    u8 pad2FAC[0x4C0];
    Node unk_346C;
    u8 pad3524[0x4C0];
    Node unk_39E4;
    u8 pad3A9C[0x4C0];
    Node unk_3F5C;
    u8 pad4014[0x4C0];
    Node unk_44D4;
    u8 pad458C[0x4C0];
    u8 unk_4A4C[4];
    u8 pad4A50[0x804];
    u8 unk_5254[4];
    u8 pad5258[0xD8];
    Node unk_5330;
    u8 pad53E8[0x7C];
    Node unk_5464;
    u8 pad551C[0x7C];
    s32 unk_5598;
    Node unk_559C;
    u8 pad5654[0x1C];
    Node unk_5670;
    u8 pad5728[0x1C];
    Node unk_5744;
    u8 pad57FC[0x1C];
    s32 unk_5818;
    s32 unk_581C;
    s32 unk_5820;
    Holder unk_5824;
    u8 pad58FC[0xCC];
    u8 unk_59C8[4];
    u8 pad59CC[0x1D8];
    void * unk_5BA4;
    u8 pad5BA8[0x30];
    u8 unk_5BD8[4];
    u8 pad5BDC[0x8A4];
    u8 unk_6480[4];
} Game;

extern u8 D_80077640[];
extern u8 D_80077650[];
extern Pool D_800F26B0;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern u8 D_800F2758[];
extern u8 D_800F2AD8[];
extern u8 D_800F4D00[];
extern u8 D_800F7270[];

void func_80014384(void);
void func_8001786C(s32);
void func_80017B24(s32);
void func_8001A248(s32 *);
void func_80075714(Game *, s32);
void func_8007E080(void *);
void func_80081400(Node *);
void func_8009BDC4(void);
void func_8009C100(void);
void func_800A8850(void *);
void func_800AA658(void *, void *);
void func_800AACB0(void *, s32, s32);
void func_800AB2A4(void *, s32, s32, Node *, s32, s32);
void func_800AC25C(Game *, s32, s32, s32);
void func_800AC334(void *);
void func_800ADC1C(Node *);
void func_800AEFA0(void *);
void func_800BAC24(void);
void func_800BC274(void *);
void func_800CCE4C(void *);
void func_800D11E8(void *);
void func_800D29E0(Node *);
void func_800D52A8(void *);
void func_800D6EA0(Node *);
void func_800D771C(Node *);
void func_800D7F5C(Holder *);
void func_800ECA30(void *);

#define VCALL(n, i) ((n)->vtable[i].func((u8 *) (n) + (n)->vtable[i].delta))

static inline void hide(Node *n) {
    VCALL(n, 3);
    n->unk_B0 = 0;
}

#define STOP(p, m) (func_80081400(p), \
                    (m).vtable[9].func((u8 *) (p) + (m).vtable[9].delta), \
                    (m).vtable[3].func((u8 *) (p) + (m).vtable[3].delta))

static inline void pool_free(Pool *pool) {
    void *heap = pool->heap;

    if (heap != NULL) {
        pool->heap = NULL;
        if (pool->objs != NULL) {
            func_800AA658(heap, &pool->objs);
        }
        if (pool->stack != NULL) {
            func_800AA658(heap, &pool->stack);
        }
        pool->cap = 0;
        pool->count = 0;
        pool->sp = NULL;
        pool->heap = NULL;
    }
}

void func_80074A70(Game *g) {
    u32 i;
    Holder *h;
    Node *n;

    func_8009BDC4();
    func_800ECA30(g->unk_6480);
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_800AC25C(g, 0x6B, 7, 0);
    n = &g->unk_5330;
    STOP(n, g->unk_5330);
    n = &g->unk_5464;
    STOP(n, g->unk_5464);
    if (g->unk_5818 != 0) {
        func_8001A248(&g->unk_5818);
        func_8001A248(&g->unk_581C);
        func_8001A248(&g->unk_5820);
    }
    func_800CCE4C(g->unk_5254);
    func_80075714(g, 0);
    func_8001786C(g->unk_5598);
    if (g->unk_5BA4 != NULL) {
        func_800AA658(D_800F2758, &g->unk_5BA4);
    }
    func_800AC334(g->unk_59C8);
    func_800A8850(g->unk_59C8);
    func_800AEFA0(D_80077650);
    hide(&g->unk_2E08);
    hide(&g->unk_2EF4);
    hide(&g->unk_346C);
    hide(&g->unk_39E4);
    hide(&g->unk_3F5C);
    hide(&g->unk_44D4);
    func_800AB2A4(D_800F26E0, D_800F2744, 7, &g->unk_2E08, 0, 0);
    func_800D771C(&g->unk_394);
    hide(&g->unk_394);
    func_800D6EA0(&g->unk_2E08);
    func_800D29E0(&g->unk_2EF4);
    func_800D29E0(&g->unk_39E4);
    func_800D29E0(&g->unk_3F5C);
    func_800D29E0(&g->unk_44D4);
    hide(&g->unk_2E08);
    func_800ADC1C(&g->unk_559C);
    hide(&g->unk_559C);
    func_800ADC1C(&g->unk_5670);
    hide(&g->unk_5670);
    func_800ADC1C(&g->unk_5744);
    hide(&g->unk_5744);
    func_800AC334(g->unk_D8);
    func_80017B24(g->unk_B8);
    func_800D52A8(D_800F4D00);
    pool_free(&D_800F26B0);
    func_800D11E8(g->unk_5BD8);
    h = &g->unk_5824;
    func_800AEFA0(D_800F7270);
    func_800D7F5C(h);
    for (i = 0; i < 8; i++) {
        h->unk_B8[i] = 0;
    }
    func_800AC334(&g->unk_5824);
    func_800BAC24();
    func_800AEFA0(D_80077640);
    func_8007E080(g->unk_4A4C);
    func_800AC334(g->unk_4A4C);
    func_8009C100();
    g->unk_AC = 1;
    func_80014384();
}
