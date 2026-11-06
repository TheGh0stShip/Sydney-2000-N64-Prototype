typedef struct Item { char pad[0x310]; float val; } Item;
typedef struct Obj {
    char pad[0x613]; unsigned char count; char pad614[0x4120 - 0x614];
    Item *items[1];
} Obj;

unsigned char func_80087F28(Obj *o)
{
    unsigned char i;
    unsigned char best;
    unsigned char cnt;
    unsigned char cnt2;
    float sum;
    float n;
    float one;
    float avg;
    float bestd;
    float zero;
    float d;

    i = 0;
    sum = 0.0f;
    cnt = o->count;
    one = *(float *)0x80071430;
    n = sum;
loop1:
    if (i < cnt) {
        if (o->items[i] != 0) {
            n += one;
            sum += o->items[i]->val;
        }
        i++;
        goto loop1;
    }
    sum = sum / n;
    best = 0;
    i = best;
    bestd = *(float *)0x80071434;
    cnt2 = o->count;
    zero = 0.0f;
loop2:
    if (i < cnt2) {
        if (o->items[i] != 0) {
            d = sum - o->items[i]->val;
            if (d < zero) d = -d;
            if (d < bestd) {
                bestd = d;
                best = i;
            }
        }
        i++;
        goto loop2;
    }
    return best;
}
