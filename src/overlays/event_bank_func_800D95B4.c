typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { s16 adj; s16 pad; void (*fn)(); } VE;
typedef struct { VE e[10]; } VT;
typedef struct { u8 pad[12]; u8 **ptr; u16 max; u16 n; } Pool;
extern u8 D_800F26E0[];
typedef struct { s32 f0; u8 r[56]; } E60;
typedef struct { u8 pad[72]; E60 a[1]; } G;
extern G *D_800FC270;
typedef struct { u8 pad[20168]; Pool pool; u8 *arr[8]; } O;
extern void func_800AACB0(void *, void *, s32);
extern void func_800172CC(s32, s32);
#define VT_OF(p) (*(VT **)((p) + 180))
#define VCALL(p, i) VT_OF(p)->e[i].fn((p) + VT_OF(p)->e[i].adj)
void func_80074A44(O *o, u8 i)
{
    u8 *e = o->arr[i];
    u8 *s;
    u8 *f;
    Pool *q;
    u8 b;
    if (e != 0) {
        func_800AACB0(D_800F26E0, e, 0);
        s = e + 1004;
        if (s != 0) {
            VCALL(s, 3);
            VCALL(s, 9);
            if (*(s32 *)(s + 196) != 0) {
                func_800172CC(*(s32 *)(s + 196), 1);
            }
        }
        s = e + 792;
        if (s != 0) {
            VCALL(s, 3);
            VCALL(s, 9);
        }
        b = e[424];
        if (b != 8) {
            D_800FC270->a[b].f0 = 0;
        }
        q = &o->pool;
        f = o->arr[i];
        VCALL(f, 3);
        func_800AACB0(D_800F26E0, f, 0);
        if (q->n < q->max) {
            VT_OF(f)->e[1].fn(f + VT_OF(f)->e[1].adj, 2);
            *q->ptr = f;
            q->ptr++;
            q->n++;
        }
        o->arr[i] = 0;
    }
}
