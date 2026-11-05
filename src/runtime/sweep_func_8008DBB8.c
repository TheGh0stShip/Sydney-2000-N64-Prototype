/* Message handler: on a tick message advance by elapsed time, on a
 * configure message forward settings to the object; always record time. */
typedef struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self, int arg);
} VEntry;

typedef struct Msg {
    int type;
    int time;
    int pad08;
    int arg0;
    int arg1;
} Msg;

typedef struct Actor {
    char pad0[16];
    int lastTime;
    char pad1[180 - 20];
    VEntry *vtbl;
    char pad2[192 - 184];
    char sub[1];
} Actor;

extern void func_8008D054(Actor *a, int ticks);
extern void func_8008CCE0(Actor *a, int arg);
extern void func_800ADC38(void *sub);

void func_8008DBB8(Actor *a, Msg *msg)
{
    switch (msg->type) {
    case 3:
        a->vtbl[2].fn((char *)a + a->vtbl[2].delta, msg->arg0);
        func_8008CCE0(a, msg->arg1);
        func_800ADC38(a->sub);
        break;
    case 5:
        func_8008D054(a, (msg->time - a->lastTime) >> 8);
        break;
    case 6:
        /* handled elsewhere */
        break;
    }
    a->lastTime = msg->time;
}
