/* Input handler: on the confirm bit play the accept or reject cue at the
 * mixer's current volume (reject also notifies the owner and posts event 107);
 * otherwise forward the raw key to the default handler. */
typedef struct Event {
    unsigned char key;
    char pad[2];
    unsigned char bits;
} Event;

typedef struct Mixer {
    char pad[104];
    int volume;
} Mixer;

typedef struct Obj Obj;

typedef struct Desc {
    char pad[4];
    int flags;
    char pad2[28 - 8];
    void (*reject)(Obj *o);
} Desc;

struct Obj {
    char pad[4];
    void *owner;
    char pad2[220 - 8];
    Desc *desc;
};

extern Mixer D_800F1AE0;
extern int func_8001D4B8(Mixer *m, int id, int a, int b);
extern void func_8001D640(Mixer *m, int voice, int vol);
extern void func_800AC25C(void *owner, int ev, int a, int b);
extern void func_800B1550(Obj *o, int key);

void func_800C27B8(Obj *o, Event *e)
{
    int v;

    if (e->bits & 0x10) {
        if (o->desc->flags & 0x80000) {
            v = func_8001D4B8(&D_800F1AE0, 89, 0, 1);
            func_8001D640(&D_800F1AE0, v, (int)((long long)D_800F1AE0.volume * 32767) >> 15);
        } else {
            v = func_8001D4B8(&D_800F1AE0, 130, 0, 1);
            func_8001D640(&D_800F1AE0, v, (int)((long long)D_800F1AE0.volume * 32767) >> 15);
            o->desc->reject(o);
            func_800AC25C(o->owner, 107, 6, 0);
        }
    } else {
        func_800B1550(o, e->key);
    }
}
