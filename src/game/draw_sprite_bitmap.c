/* func_8001B414 (ROM 0x1C014..0x1CE98, size 0xE84): libultra-style sprite bitmap
 * draw (spDraw/drawbitmap core: render-mode setup, optional CI8 TLUT load, prim
 * colour/combiner, per-bitmap scissor clip, gDPLoadTextureBlock 16b/8b,
 * gSPTextureRectangle via a static TexRect at 0x8006B050).
 * EXACT under SN GCC -O2 -G0 -mcpu=vr4300 -mips3 -mhard-float -meb,
 * --section-base=.rdata:0x80001070, --no-infer. Key shapes: F3 load-block word
 * built in `words` after w0; curRect dsdx before dtdy and yh before yl; the
 * bottom row (row + bitmap height) kept in its own `bottom` temporary. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef struct { u32 w0, w1; } Gwords;
typedef union { Gwords words; long long force_structure_alignment; } Gfx;
typedef struct { s16 width, width_img, s, t; void *buf; s16 actualHeight, LUToffset; } Bitmap;
typedef struct {
    s16 x, y, width, height;
    float scalex, scaley;
    s16 expx, expy;
    u16 attr;
    u16 zdepth;
    u8 red, green, blue, alpha;
    s16 startTLUT, nTLUT;
    void *LUT;
    s16 istart, istep, nbitmaps, ndisplist, bmheight, bmHreal;
    u8 bmfmt, bmsiz;
    Bitmap *bitmap;
    Gfx *rsp_dl, *rsp_dl_next;
    s16 frac_s, frac_t;
} Sprite;
typedef struct {
    unsigned int cmd:8, xl:12, yl:12;
    unsigned int pad:5, tile:3, xh:12, yh:12;
    u16 s, t, dsdx, dtdy;
} TexRect;

extern Gfx *dlHead __asm__("D_800663DC");
extern TexRect *curRect __asm__("D_80063500");
extern void *lastImage __asm__("D_80063504");
extern s32 maskS __asm__("D_80063508");
extern s32 maskT __asm__("D_8006350C");
extern u16 spAttr __asm__("D_80063514");
extern TexRect rectBuf __asm__("D_8006B050");
extern s32 scissorXMax __asm__("D_8006B060");
extern s32 scissorYMax __asm__("D_8006B064");
extern s32 scissorXMin __asm__("D_8006B068");
extern s32 scissorYMin __asm__("D_8006B06C");

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) ((0x800 + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))
#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((1 << (w)) - 1)) << (s)))
#define gImmp1(pkt, c, p0) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(c, 24, 8); _g->words.w1 = (u32)(p0); }
#define gSPTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = (_SHIFTL(0xE4, 24, 8) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)); \
    _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)); \
    gImmp1(pkt, 0xE1, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))); \
    gImmp1(pkt, 0xF1, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16))); }
#define EMIT(a, b) { Gfx *_g = dlHead++; _g->words.w0 = (a); _g->words.w1 = (b); }

void func_8001B414(Sprite *sp, s32 ms, s32 mt) {
    s32 bmIndex;
    s32 dsdx, dtdy;
    s32 set = 0;
    s32 xoff, yoff;
    Bitmap *b;
    s32 col, row;
    s32 ul_x, ul_y, lr_x, lr_y;
    s32 bottom;
    s32 fs, ft;
    s32 rx0, ry0, rx1, ry1;
    s32 sStart, tStart;
    s32 width, height, words, lrs, dxt;
    float sx, sy, fx, fy;
    u32 mask;

    if (sp->attr & 4) return;
    xoff = 0;
    yoff = 0;
    b = sp->bitmap;
    lastImage = 0;
    if (sp->attr & 8) {
        EMIT(0xE2001D00, 4);
        EMIT(0xEE000000, sp->zdepth << 16);
        if (sp->attr & 1) {
            EMIT(0xE200001C, 0x005049F8);
            EMIT(0xF9000000, 0xFFFFFF01);
            EMIT(0xE2001E01, 1);
            set = 1;
        }
        if (sp->attr & 2) { EMIT(0xE200001C, 0x00553078); EMIT(0xE2001E01, 0); set = 1; }
        if (sp->attr & 0x20) { EMIT(0xE200001C, 0x00552078); EMIT(0xE2001E01, 0); set = 1; }
        if (!set) { EMIT(0xE200001C, 0x00552078); EMIT(0xE2001E01, 0); }
    } else {
        if (sp->attr & 1) {
            EMIT(0xE200001C, 0x005049F8);
            EMIT(0xF9000000, 0xFFFFFF01);
            EMIT(0xE2001E01, 1);
            set = 1;
        }
        if (sp->attr & 2) { EMIT(0xE200001C, 0x00553048); EMIT(0xE2001E01, 0); set = 1; }
        if (sp->attr & 0x20) { EMIT(0xE200001C, 0x00552048); EMIT(0xE2001E01, 0); set = 1; }
        if (!set) { EMIT(0xE200001C, 0x00552048); EMIT(0xE2001E01, 0); }
    }
    if (sp->bmsiz == 1) {
        EMIT(0xE3001001, 0x8000);
        EMIT(0xFD100000, (u32)sp->LUT);
        EMIT(0xE8000000, 0);
        EMIT(0xF5000100, 0x07000000);
        EMIT(0xE6000000, 0);
        EMIT(0xF0000000, 0x073FC000);
        EMIT(0xE7000000, 0);
    }
    spAttr = sp->attr;
    EMIT(0xE3001201, 0x2000);
    EMIT(0xFA000000, (sp->red << 24) | (sp->green << 16) | (sp->blue << 8) | sp->alpha);
    if (sp->alpha == 0xFF) {
        EMIT(0xFC11FE23, 0xFFFFF3F9);
    } else {
        EMIT(0xFC119623, 0xFF2FFFFF);
    }
    sx = sp->scalex;
    sy = sp->scaley;
    maskS = ms;
    maskT = mt;
    dsdx = (s32)(1024.0f / sx + 0.5f);
    dtdy = (s32)(1024.0f / sy + 0.5f);
    col = 0;
    if (b == 0) return;
    row = 0;
    fy = sp->y + row * sy;
    ul_y = (s32)(fy + 0.99999f);
    ft = (s32)(dtdy * ((float)ul_y - fy));
    ft = (ft + 16) >> 5;
    if (sp->attr & 0x80) ft += 16;
    if (sp->attr & 0x100) ft += sp->frac_t;
    bmIndex = 0;
    bottom = sp->bmheight;
    lr_y = (s32)(sp->y + bottom * sy + 0.99999f);
    mask = 0xFF000FFF;
    for (;;) {
        if (!(bmIndex < sp->nbitmaps && b->width > 0)) { bm_exit: break; }
        if (sp->width < col + b->width) {
            row += sp->bmheight;
            fy = sp->y + row * sy;
            col = 0;
            ul_y = (s32)(fy + 0.9999f);
            xoff = 0;
            yoff += sp->expy;
            bottom = row + sp->bmheight;
            ft = (s32)(dtdy * ((float)ul_y - fy));
            ft = (ft + 16) >> 5;
            if (sp->attr & 0x80) ft += 16;
            if (sp->attr & 0x100) ft += sp->frac_t;
            lr_y = (s32)(sp->y + bottom * sy + 0.9999f);
            ul_y += yoff;
            lr_y += yoff;
            { s32 h = b->actualHeight ? b->actualHeight : sp->bmheight; if (sp->height < row + h) return; }
        }
        fx = sp->x + col * sx;
        ul_x = (s32)(fx + 0.9999f);
        fs = (s32)(dsdx * ((float)ul_x - fx));
        fs = (fs + 16) >> 5;
        if (sp->attr & 0x80) fs += 16;
        if (sp->attr & 0x100) fs += sp->frac_s;
        lr_x = (s32)(sp->x + (col + b->width) * sx + 0.9999f);
        if (b->actualHeight) { bottom = row + b->actualHeight; lr_y = (s32)(sp->y + bottom * sy + 0.9999f); lr_y += yoff; }
        ul_x += xoff;
        lr_x += xoff;
        if (b->buf != 0) {
            width = b->width_img;
            height = sp->bmHreal;
            curRect = &rectBuf;
            if (ul_x < scissorXMax && ul_y < scissorYMax && lr_x >= scissorXMin && lr_y >= scissorYMin) {
                if (ul_x < scissorXMin) {
                    rx0 = scissorXMin << 2;
                    sStart = (b->s << 5) + fs + (((scissorXMin - ul_x) * dsdx) >> 5);
                } else {
                    rx0 = ul_x << 2;
                    sStart = (b->s << 5) + fs;
                }
                if (ul_y < scissorYMin) {
                    ry0 = scissorYMin << 2;
                    tStart = (b->t << 5) + ft + (((scissorYMin - ul_y) * dtdy) >> 5);
                } else {
                    ry0 = ul_y << 2;
                    tStart = (b->t << 5) + ft;
                }
                rx1 = lr_x < scissorXMax ? lr_x << 2 : scissorXMax << 2;
                ry1 = lr_y < scissorYMax ? lr_y << 2 : scissorYMax << 2;
                if (b->buf != lastImage) {
                    if (sp->bmsiz == 2) {
                        EMIT(0xE3001001, 0);
                        EMIT(0xFD100000 | ((sp->bmfmt & 7) << 21), (u32)b->buf);
                        EMIT(0xF5100000 | ((sp->bmfmt & 7) << 21), 0x07080200 | ((maskT & 0xF) << 10) | (maskS & 0xF));
                        EMIT(0xE6000000, 0);
                        { Gfx *_g = dlHead++; _g->words.w0 = 0xF3000000; words = 0x07000000 | ((MIN(width * height - 1, 0x7FF) & 0xFFF) << 12) | (CALC_DXT(width, 2) & 0xFFF); _g->words.w1 = words; }
                        EMIT(0xE7000000, 0);
                        EMIT(0xF5100000 | ((sp->bmfmt & 7) << 21) | ((((width * 2 + 7) >> 3) & 0x1FF) << 9),
                             0x00080200 | ((maskT & 0xF) << 10) | (maskS & 0xF));
                        EMIT(0xF2000000, ((((width - 1) << 2) & 0xFFF) << 12) | (((height - 1) << 2) & 0xFFF));
                    } else {
                        EMIT(0xFD100000 | ((sp->bmfmt & 7) << 21), (u32)b->buf);
                        EMIT(0xF5100000 | ((sp->bmfmt & 7) << 21), 0x07080200 | ((maskT & 0xF) << 10) | (maskS & 0xF));
                        EMIT(0xE6000000, 0);
                        { Gfx *_g = dlHead++; _g->words.w0 = 0xF3000000; words = 0x07000000 | ((MIN(((width * height + 1) >> 1) - 1, 0x7FF) & 0xFFF) << 12) | (CALC_DXT(width, 1) & 0xFFF); _g->words.w1 = words; }
                        EMIT(0xE7000000, 0);
                        EMIT(0xF5080000 | ((sp->bmfmt & 7) << 21) | ((((width + 7) >> 3) & 0x1FF) << 9),
                             0x00080200 | ((maskT & 0xF) << 10) | (maskS & 0xF));
                        EMIT(0xF2000000, ((((width - 1) << 2) & 0xFFF) << 12) | (((height - 1) << 2) & 0xFFF));
                    }
                    lastImage = b->buf;
                }
                curRect->cmd = 0xE4;
                curRect->s = sStart;
                curRect->t = tStart;
                curRect->dsdx = dsdx;
                curRect->dtdy = dtdy;
                curRect->tile = 0;
                curRect->xh = rx0;
                curRect->xl = rx1;
                curRect->yh = ry0;
                curRect->yl = ry1;
                gSPTextureRectangle(dlHead++, curRect->xl, curRect->yl, curRect->xh, curRect->yh,
                                    curRect->tile, curRect->s, curRect->t, curRect->dsdx, curRect->dtdy);
                EMIT(0xE7000000, 0);
            }
        }
        col += b->width;
        xoff += sp->expx;
        bmIndex++;
        b++;
    }
}
