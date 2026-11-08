typedef struct Node { char pad0[12]; struct Node *next; char pad1[176]; int flags; char pad2[7]; unsigned char alpha; } Node;
typedef struct { char pad[4]; int flags; } Cfg;
typedef struct {
    char pad0[8]; Node *list;
    char pad1[184]; int handle;
    char pad2[20]; Cfg *cfg;
    char pad3[232]; int current;
    char pad4[224]; int alt;
    char pad5[164]; int mode;
} Obj;
extern void func_800191E0(int *, unsigned int);
void func_800B0CEC(Obj *o, int on)
{
    int flags = o->cfg->flags;
    if (flags & 0x10000) {
        if (o->handle) {
            if (on && !(flags & 0x8000000)) {
                func_800191E0(&o->handle, 0xC8404040);
            } else if (!(o->cfg->flags & 0x2000000)) {
                func_800191E0(&o->handle, 0xC8FFFFFF);
            }
        }
    } else {
        Node *n = o->list;
        if (!n) return;
        if (on) {
            while (1) {
                if (!n) break;
                if (n->flags & 0x10000) n->alpha = 128;
                n = n->next;
            }
        } else {
            while (1) {
                if (!n) break;
                if (n->flags & 0x10000) n->alpha = 255;
                n = n->next;
            }
            if (o->mode & 1) o->current = o->alt;
        }
    }
    if (on) o->cfg->flags |= 0x80000;
    else o->cfg->flags &= ~0x80000;
}
