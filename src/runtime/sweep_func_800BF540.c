typedef struct { int magic; int version; unsigned short a; unsigned short b; unsigned short c; } Header;
typedef struct {
    int type; char pad0[180];
    Header *data; char *base; char *mid; char *end;
    unsigned short a, b, c;
    unsigned char ready, x207, x208, x209;
    char pad1[10]; int slot;
    char *name; int lang;
} Obj;
extern int D_800F3884;
extern int D_800F271C;
extern char D_800F2758[];
extern char *D_800F3EA4[][13];
extern int func_80005A3C(char *, void *, void *, int);
extern void func_800AA658(void *, void *);
extern void func_800AAA60(char *, int, char *);
int func_800BF540(Obj *o)
{
    int lang;
    Header *h;
    char *heap;
    o->x207 = 0;
    o->x208 = 0;
    o->x209 = 0;
    o->ready = 0;
    lang = D_800F3884;
    o->type = 54;
    heap = D_800F2758;
    o->data = 0;
    o->base = 0;
    o->mid = 0;
    o->end = 0;
    o->a = 0;
    o->b = 0;
    o->c = 0;
    if (!lang) lang = 1;
    o->name = "pinfo.com";
    o->lang = lang;
    if (!func_80005A3C(D_800F3EA4[D_800F271C][o->slot], &o->data, heap, 1)) return 0;
    h = o->data;
    if (h->magic != 0x4D4D4F43 || h->version != 0x30000) {
        func_800AA658(heap, &o->data);
        func_800AAA60("c:/dev/olympics_2000/code/common/Comm.cpp", 430, "Commentary database signature incorrect\n");
        return 0;
    }
    o->a = h->a;
    o->b = o->data->b;
    o->c = o->data->c;
    o->base = (char *)o->data + 16;
    o->mid = o->base + o->a * 8;
    o->end = o->mid + o->b * 4;
    return 1;
}
