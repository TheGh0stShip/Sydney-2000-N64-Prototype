typedef struct Vertex {
    char pad[16];
    short x;
    short y;
    short z;
    short pad2;
    float u;
    float v;
} Vertex;

typedef struct OutVertex {
    char pad[12];
    float x;
    float y;
    float z;
    char pad2[4];
    float u;
    float v;
} OutVertex;

typedef struct Grid {
    char pad[188];
    void *buffer;
    char pad2[220];
    Vertex *verts;
    char pad3[36];
    unsigned int cols;
    unsigned int rows;
} Grid;

extern void func_80017C4C(void *buffer, int flags, void *out);
extern void func_80017C3C(void *buffer);

void func_8008DA2C(Grid *self)
{
    OutVertex *out;
    Vertex *src;
    unsigned int row;
    unsigned int col;
    float scale;

    func_80017C4C(self->buffer, 0, &out);
    scale = 1.0f / 4096.0f;
    row = 0;
next_row:
    if (row < self->rows) {
        col = 0;
next_col:
        if (col < self->cols) {
            src = &(self->verts + row * self->cols)[col];
            out->x = src->x * scale;
            out->y = src->y * scale;
            out->z = src->z * scale;
            out->u = src->u;
            out->v = src->v;
            out++;
            col++;
            goto next_col;
        }
        row++;
        goto next_row;
    }
    func_80017C3C(self->buffer);
}
