typedef struct VTEntry {
    char pad0[8];
    short offset;
    short pad1;
    void (*fn)(void *, int);
} VTEntry;

typedef struct { char pad[180]; VTEntry *vt; } Elem184;
typedef struct { char pad[180]; VTEntry *vt; char rest[220]; } Elem404;
typedef struct { char pad[180]; VTEntry *vt; char rest[28]; } Elem212;

typedef struct EventBankObj {
    char pad0[240];
    char sub240[212];
    Elem212 arr452[3];
    Elem212 arr1088[3];
    Elem404 arr1724[3];
    char sub2936[32];
    char sub2968[480];
    Elem184 arr3448[3];
    char sub4000[4];
    char sub4004[244];
    char sub4248[16];
    char sub4264[200];
    char sub4464[4];
} EventBankObj;

extern void func_800A86AC(void *, int);
extern void func_800AC3A4(void *, int);
extern void func_800AF064(void *, int);
extern void func_800A9C2C(void *, int);
extern void func_800AE4D8(void *, int);
extern void func_800ADE84(void *, int);

#define DESTROY_ARRAY(base, n)                                          \
    if (base) {                                                         \
        __typeof__(&(base)[0]) q = &(base)[n];                          \
        while ((base) != q) {                                              \
            q--;                                                        \
            q->vt->fn(q->vt->offset + (char *)q, 2);                    \
        }                                                               \
    }

void func_800734B4(EventBankObj *obj, int mode)
{
    func_800A86AC(obj->sub4464, 2);
    func_800AC3A4(obj->sub4264, 2);
    func_800AF064(obj->sub4248, 2);
    func_800A9C2C(obj->sub4004, 2);
    DESTROY_ARRAY(obj->arr3448, 3);
    func_800AE4D8(obj->sub2968, 2);
    DESTROY_ARRAY(obj->arr1724, 3);
    DESTROY_ARRAY(obj->arr1088, 3);
    DESTROY_ARRAY(obj->arr452, 3);
    func_800ADE84(obj->sub240, 2);
    func_800AC3A4(obj, mode);
}
