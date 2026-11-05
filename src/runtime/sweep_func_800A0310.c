typedef struct {
    char pad[184];
    int rows;
    int cols;
    unsigned short edgeCount;
    char pad2[196 - 194];
    void *cells;
    char pad3[204 - 200];
    void *edges;
} Grid;
extern char D_800F2758[];
extern char D_80084C30[];
extern char D_80084C3C[];
extern int func_800AA804(void *, void *, int, void *);
extern void func_800A0224(Grid *);

void func_800A0310(Grid *g)
{
    int rowBytes = g->cols * 52;

    g->cells = 0;
    func_800AA804(D_800F2758, &g->cells, g->rows * rowBytes, D_80084C30);
    g->edges = 0;
    g->edgeCount = (g->rows - 1) * (g->cols - 2) + (g->cols - 1) * (g->rows - 2);
    func_800AA804(D_800F2758, &g->edges, g->edgeCount * 8, D_80084C3C);
    func_800A0224(g);
}
