typedef struct { short offset; short pad; void (*fn)(void *); } VEntry;
typedef struct { char pad0[24]; VEntry reset; char pad1[40]; VEntry init; } VTable;
typedef struct { char pad0[180]; VTable *vt; char pad1[28]; } Unit;
extern signed char D_80102000[12];
extern unsigned char D_80102010[8];
extern unsigned char D_80102020[12];
extern signed char D_80102030[12];
extern unsigned char D_80102040[12][12];
extern Unit D_80101960[8];
extern int D_800F271C;
extern signed char D_800F40FD;
void func_800C4738(void)
{
    unsigned char i;
    unsigned char j;
    for (i = 0; i < 12; i++) {
        D_80102000[i] = -1;
        D_80102030[i] = -1;
        D_80102020[i] = 0;
        for (j = 0; j < 12; j++) D_80102040[i][j] = 0;
    }
    for (i = 0; i < 8; i++) {
        Unit *u = &D_80101960[i];
        u->vt->init.fn((char *)u + u->vt->init.offset);
        u->vt->reset.fn((char *)u + u->vt->reset.offset);
        D_80102010[i] = 0;
    }
    if (D_800F271C == 7) D_800F40FD = -1;
}
