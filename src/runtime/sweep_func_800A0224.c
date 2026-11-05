/* Reset every grid cell's vectors and clear the grid selection state. */
typedef struct Vec3 { float x, y, z; } Vec3;

typedef struct Cell {
    char pad[12];
    Vec3 b;
    Vec3 a;
    Vec3 c;
    int pad30;
} Cell;

typedef struct Grid {
    char pad0[184];
    int width;
    int height;
    int pad0C0;
    Cell *cells;
    char pad1[240 - 200];
    unsigned int flags;
    char pad2[256 - 244];
    short selA;
    short selB;
} Grid;

static __inline__ void vec3_zero(Vec3 *v)
{
    v->x = 0;
    v->y = 0;
    v->z = 0;
}

void func_800A0224(Grid *grid)
{
    int i;
    int j;

    i = 0;
    j = 0;
loop:
    if (i < grid->width * grid->height) {
        i++;
        vec3_zero(&((Cell *)(j + (int)grid->cells))->a);
        vec3_zero(&((Cell *)(j + (int)grid->cells))->b);
        vec3_zero(&((Cell *)(j + (int)grid->cells))->c);
        j += sizeof(Cell);
        goto loop;
    }
    grid->selB = -1;
    grid->selA = -1;
    grid->flags &= ~1;
    grid->flags &= ~2;
}
