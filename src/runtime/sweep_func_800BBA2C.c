typedef struct {
    int time;
    int value;
} Key;

typedef struct {
    int pad;
    Key *keys;
} Track;

void func_800BBA2C(Track *t, int start)
{
    int first = t->keys[0].time;
    unsigned short i;

    if (first != -7680) {
        if (start < 256) {
            start = 256;
        }
        i = 0;
        if (first != start) {
            start = first - start;
            while (t->keys[i].time != -7680) {
                t->keys[i++].time -= start;
            }
        }
    }
}
