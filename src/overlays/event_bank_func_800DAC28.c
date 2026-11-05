typedef struct {
    int x;
    int rx;
    int y;
    int ry;
    short pad;
    short flag;
} Item;

typedef struct {
    char pad[0x60AC];
    Item items[1];
} Obj;

void func_800DAC28(Obj *obj)
{
    int minx = 0x4B000;
    int miny = 0x4B000;
    unsigned char i;

    for (i = 0; i < ((unsigned char *)obj)[1555]; i++) {
        if (obj->items[i].flag != 1) {
            if (obj->items[i].x < minx) {
                minx = obj->items[i].x;
            }
            if (obj->items[i].y < miny) {
                miny = obj->items[i].y;
            }
        }
    }
    for (i = 0; i < ((unsigned char *)obj)[1555]; i++) {
        if (obj->items[i].flag != 1) {
            obj->items[i].rx = obj->items[i].x - minx;
            obj->items[i].ry = obj->items[i].y - miny;
        }
    }
}
