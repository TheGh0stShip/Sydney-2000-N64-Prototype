typedef struct { short a; short b; unsigned short nfrm; unsigned short ncam; } VdHdr;
typedef struct { char pad[0x68]; } VdCam;
typedef struct { char pad[8]; } VdFrm;
typedef struct {
    char pad0[0xB8];
    VdHdr *hdr;
    char padbc[0xC0 - 0xBC];
    int fc0;
    char padc4[0xC8 - 0xC4];
    VdFrm *frms;
    int *camst;
    char padd0[0xD8 - 0xD0];
    VdCam *cams;
    int id;
    char pade0[0xE2 - 0xE0];
    unsigned short nfrm;
    unsigned short ncam;
    char pade6[0xEC - 0xE6];
    int fec;
    int src;
} Vd;

extern char D_800F2758[];
extern int func_80005A3C(int src, void *out, char *heap, int n);
extern void func_800AA804(char *heap, void *out, int size, char *tag);
extern void func_800A8F38(Vd *v, char *cur, int arg, unsigned char i);
extern void func_800A9CE0(VdFrm *f, char **cur);

void func_800A97D4(Vd *v, int id, int src, int arg)
{
    char *cur;
    unsigned char i;
    unsigned char j;
    char *heap;
    unsigned short ncam;
    unsigned short nfrm;

    v->id = id;
    v->src = src;
    if (func_80005A3C(src, &v->hdr, D_800F2758, 1) == 0) {
        return;
    }
    heap = D_800F2758;
    cur = (char *)v->hdr;
    ncam = v->hdr->ncam;
    nfrm = v->hdr->nfrm;
    v->ncam = ncam;
    v->nfrm = nfrm;
    func_800AA804(heap, &v->cams, ncam * sizeof(VdCam), "VD_CAMD");
    func_800AA804(heap, &v->camst, ncam * sizeof(int), "VD_CAMS");
    for (j = 0; j < v->ncam; j++) {
        v->camst[j] = 0;
    }
    func_800AA804(heap, &v->frms, nfrm * sizeof(VdFrm), "VD_FRMS");
    cur += 8;
    for (i = 0; i < v->ncam; i++) {
        func_800A8F38(v, cur, arg, i);
        cur += 96;
    }
    for (i = 0; i < v->nfrm; i++) {
        func_800A9CE0(&v->frms[i], &cur);
    }
    v->fc0 = 0;
    v->fec = 0;
}
