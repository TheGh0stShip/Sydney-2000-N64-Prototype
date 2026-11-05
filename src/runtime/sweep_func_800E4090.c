/* Fill the roster display rows from either the direct lane list or the
 * remapped order, highlighting every row except the current selection. */
typedef struct Row {
    unsigned char highlight;
    unsigned char id;
    short timer;
    float scale;
    signed char anim;
    char pad9;
    unsigned char done;
    char padB;
} Row;

typedef struct Game {
    char pad0[1265];
    unsigned char selected;
    char pad1[2464 - 1266];
    unsigned char lanes[2576 - 2464];
    Row rows[8];
} Game;

extern Game *D_800FC270;
extern unsigned char D_800FD100[];

void func_800E4090(int unused, int direct)
{
    Game *g = D_800FC270;
    Row *row = g->rows;
    unsigned char *lanes = g->lanes;
    int count = 7;
    int i;

    if (direct) {
        count = 3;
    }
    for (i = count; i >= 0; row++, i--) {
        unsigned char id;

        if (direct) {
            id = lanes[i];
        } else {
            id = lanes[D_800FD100[i] - 1];
        }
        if (id == D_800FC270->selected) {
            row->highlight = 0;
        } else {
            row->highlight = 8;
        }
        row->id = id;
        row->timer = 0;
        row->scale = -1.0f;
        row->anim = -1;
        row->done = 0;
    }
}
