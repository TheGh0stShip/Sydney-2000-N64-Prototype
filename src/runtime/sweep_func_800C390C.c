struct Blink {
    int pad0;
    int count;
    int pad8;
    int active;
};

struct Message {
    char pad[6];
    unsigned short code;
    char pad2[20];
    struct Blink *blink;
};

struct Sprite {
    char pad[160];
    float alpha;
    char pad2[28];
    int flags;
};

struct Widget {
    char pad[220];
    struct Message *msg;
    char pad2[712 - 224];
    struct Sprite *sprite;
    char pad3[780 - 716];
    int timer;
};

extern void func_800C3764(struct Widget *);
extern int func_800C69F4(struct Widget *, int, int);

int func_800C390C(struct Widget *self, int arg1, int arg2)
{
    struct Message *msg = self->msg;
    int code = msg->code;

    if (code == 15 || code == 16) {
        struct Blink *blink = msg->blink;

        if (blink->active) {
            if (code == 16) {
                blink->active = 0;
                blink->count = 0;
                func_800C3764(self);
            } else {
                if (blink->count > 0) {
                    blink->count--;
                } else {
                    blink->active = 0;
                }
                blink = self->msg->blink;
                if (blink->active) {
                    self->sprite->alpha = blink->count * 17;
                    self->sprite->flags &= ~4;
                    self->timer = 0;
                } else {
                    self->sprite->flags |= 4;
                }
            }
            return 1;
        }
    }
    if (code == 3) {
        return func_800C69F4(self, arg1, arg2);
    }
    return 0;
}
