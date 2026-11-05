/* NONMATCHING: func_8000AD30 (0x8000AD30, size 0x6C8) best score 46 with
 * pipeline sn, flags -O2 -G0 -mcpu=vr4300 -mips3 -mhard-float -meb
 * (lane02; was 130). Size matches exactly (0x6C8). Key wins: prologue
 * computes end before start; k-loop bound copied into `stop`; TRI1 uses
 * idx = D_8004799C; D_8004799C = idx + 1; `start` declared last.
 * Remaining: start spill slot sits before the t4-t8 caller-save area
 * (ours sp+0x40, target sp+0x58, shifting caller-save slots by 8);
 * colour-row load scheduling at +0x2B8; TRI1 sll-before-increment order
 * at +0x5C4; three commutative addu operand orders.
 * Semantics: builds deduplicated F3DEX2 vertices (Vtx 16 bytes) from mesh
 * triangles, normalises S/T into a 0x800 window (clearing flag bits in
 * *D_8005A0FC when out of range), batches up to 32 verts / 256 indices,
 * emits G_VTX + G_TRI2/G_TRI1 (when mode == 1) and a final 0xDE010000.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u16 pad0;
    u16 pad2;
    u16 start;
    u16 count;
} Mesh;

typedef struct {
    u16 pos;
    u16 col;
    s16 s;
    s16 t;
} MeshVert;

typedef struct {
    s16 x, y, z;
    u16 flag;
    s16 s, t;
    u8 r, g, b, a;
} Vtx16;

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 r, g, b;
} Color3;

extern u32 D_80047998;
extern u32 D_8004799C;
extern u32 *D_8005A0FC;
extern s32 D_8005A100[];

extern s32 func_80037EF0(void *a, void *b, s32 size);

u32 func_8000AD30(Mesh *mesh, MeshVert *verts, u16 (*pos)[3], Color3 *col,
                  u16 (*tris)[3], s32 mode, Vtx16 *vtxBuf, Gfx *gfx)
{
    s32 s[3];
    s32 t[3];
    u32 end;
    u32 i;
    u32 j;
    u32 k;
    u32 m;
    u32 n;
    u32 last;
    u32 lastVtx;
    u32 savedVtx;
    u32 base;
    u32 nIdx;
    s32 full;
    s32 found;
    s32 minS, maxS, minT, maxT;
    Gfx *g;
    s32 dS, dT, oS, oT;
    u32 w0, w1, idx;
    u32 stop;

    end = mesh->start + mesh->count;
    {
    register u32 start;
    start = mesh->start;
restart:
        nIdx = 0;
        base = D_80047998;
        full = 0;
        for (i = start; i < end; i++) {
            savedVtx = D_80047998;
            minT = 0x7FFFFFFF;
            minS = 0x7FFFFFFF;
            maxT = 0x80000001;
            maxS = 0x80000001;
            for (j = 0; j < 3; j++) {
                s[j] = verts[tris[i][j]].s;
                t[j] = verts[tris[i][j]].t;
                if (s[j] < minS) minS = s[j];
                if (s[j] > maxS) maxS = s[j];
                if (t[j] < minT) minT = t[j];
                if (t[j] > maxT) maxT = t[j];
            }
            dS = maxS - minS;
            dT = maxT - minT;
            oS = (minS + 0x8000) & 0x7FF;
            oT = (minT + 0x8000) & 0x7FF;
            if (dS < 0x841 && oS < 0x20) {
                minS &= ~0x7FF;
                for (j = 0; j < 3; j++) {
                    s[j] -= minS;
                }
            } else {
                *D_8005A0FC &= 0x7FFFFFFF;
            }
            if (dT < 0x841 && oT < 0x20) {
                minT &= ~0x7FF;
                for (j = 0; j < 3; j++) {
                    t[j] -= minT;
                }
            } else {
                *D_8005A0FC &= 0xBFFFFFFF;
            }
            for (j = 0; j < 3; j++) {
                u16 *p;
                register Color3 *c __asm__("$4");
                register u32 colorIndex __asm__("$3");
                u32 firstColorOut;
                u32 colorBase;
                Vtx16 *firstOut;
                p = (u16 *)((u32)(verts[tris[i][j]].pos * 6) + (u32)pos);
                vtxBuf[D_80047998].x = p[0];
                vtxBuf[D_80047998].y = p[1];
                vtxBuf[D_80047998].z = p[2];
                vtxBuf[D_80047998].flag = 0;
                vtxBuf[D_80047998].a = 0xFF;
                found = -1;
                firstColorOut = D_80047998;
                firstOut = (Vtx16 *)((firstColorOut << 4) + (u32)vtxBuf);
                colorBase = (u32)col;
                colorIndex = verts[tris[i][j]].col;
                __asm__("" : "+r"(colorIndex) : "r"(firstColorOut), "r"(colorBase));
                {
                    register u32 twice __asm__("$4");
                    twice = colorIndex << 1;
                    __asm__("" : "+r"(twice));
                    colorIndex = twice + colorIndex;
                }
                c = (Color3 *)(colorBase + colorIndex);
                firstOut->r = c->r;
                vtxBuf[D_80047998].g = c->g;
                vtxBuf[D_80047998].b = c->b;
                vtxBuf[D_80047998].s = s[j];
                vtxBuf[D_80047998].t = t[j];
                for (m = base; m < D_80047998; m++) {
                    if (func_80037EF0(&vtxBuf[m], &vtxBuf[D_80047998], 16) == 0) {
                        found = m;
                        break;
                    }
                }
                if (found != -1) {
                    D_8005A100[nIdx++] = found - base;
                } else {
                    D_8005A100[nIdx++] = D_80047998 - base;
                    D_80047998++;
                }
                if (D_80047998 - base > 0x20) {
                    full = 1;
                }
                if (nIdx >= 0x100) {
                    full = 1;
                }
                if (full == 1) {
                    D_80047998 = savedVtx;
                    break;
                }
            }
            if (full == 1) {
                break;
            }
            last = i;
            lastVtx = D_80047998;
        }
        if (mode == 1) {
            Gfx *vertexCmd = &gfx[D_8004799C];
            vertexCmd->w0 = 0x01000000 | (((lastVtx - base) & 0xFF) << 12)
                                     | (((lastVtx - base) & 0x7F) << 1);
            vertexCmd->w1 = (u32)vtxBuf + (base * 16);
        }
        D_8004799C++;
        stop = last;
        n = 0;
        k = start;
        for (;;) {
next:
            if (k > stop) {
                break;
            }
            if (k < stop) {
                if (mode == 1) {
                    g = &gfx[D_8004799C++];
                    g->w0 = (((D_8005A100[n + 2] * 2) & 0xFF) << 16)
                          | (((D_8005A100[n + 1] * 2) & 0xFF) << 8)
                          | ((D_8005A100[n + 0] * 2) & 0xFF) | 0x06000000;
                    g->w1 = (((D_8005A100[n + 5] * 2) & 0xFF) << 16)
                          | (((D_8005A100[n + 4] * 2) & 0xFF) << 8)
                          | ((D_8005A100[n + 3] * 2) & 0xFF);
                } else {
                    D_8004799C++;
                }
                n += 6;
                k++;
            } else {
                if (mode == 1) {
                    { Gfx *one;
                    one = &gfx[D_8004799C++];
                    one->w0 = (((D_8005A100[n + 2] * 2) & 0xFF) << 16)
                          | (((D_8005A100[n + 1] * 2) & 0xFF) << 8)
                          | ((D_8005A100[n + 0] * 2) & 0xFF) | 0x05000000;
                    one->w1 = 0; }
                } else {
                    D_8004799C++;
                }
            }
            k++;
            goto next;
        }
        if (k < end) {
            start = last + 1;
            goto restart;
        }
    }
    if (mode == 1) {
        Gfx *final = &gfx[D_8004799C];
        final->w0 = 0xDE010000;
        final->w1 = 0;
    }
    return ++D_8004799C;
}
