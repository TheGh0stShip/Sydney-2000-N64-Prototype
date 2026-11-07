typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int key; char pad; u8 bits; } Ent;
typedef struct { signed char a; u8 bits; u8 c; u8 d; } Msg;
typedef struct {
    char pad0[427]; signed char id;
    char pad1[644 - 428]; void *list; Ent *cur;
} Obj;
extern Ent *func_800BBB04(void *, int);
extern void func_800BBB30(void *, int, Msg *);
extern void func_800BC07C(Ent *, int);
void func_800AAB54(Obj *o, u16 bits, int key)
{
    Msg m;
    Ent *e;
    Ent *e2;
    int id;
    e = func_800BBB04(o->list, -1);
    if (e != 0) {
        if (e->key == key) {
            e->bits |= bits;
            e2 = func_800BBB04(o->list, -2);
            if (e2) o->cur->bits = e2->bits;
            else o->cur->bits = 0;
            func_800BC07C(o->cur, e->bits);
            return;
        }
        if ((e->bits & bits) == bits) return;
        m.bits = bits | e->bits;
    } else {
        m.bits = bits;
    }
    id = o->id;
    m.c = 0;
    m.d = 0;
    m.a = id;
    func_800BBB30(o->list, key, &m);
    func_800BC07C(o->cur, m.bits);
}
