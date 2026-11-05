/* Build the complete mipmap chain, including aligned source copying,
 * filtered downsampling, format-specific packing, and final draw setup. */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

typedef struct {
    u8 *src;
    s32 format;
    s32 size;
    s32 unkC;
    s32 unk10;
    s32 stride;
    s32 offset;
    s32 width;
    s32 height;
    s32 x;
    s32 y;
} TexSource;

typedef struct {
    u8 unk0;
    u8 shift;
    u8 scale;
    u8 unk3;
} TexSizeInfo;

typedef struct {
    s32 lineWidth;
    s32 width;
    s32 height;
    s32 tmemOffset;
} MipmapLevel;

extern TexSizeInfo texSizeInfo[] __asm__("D_8005A800");
extern s32 mipmapStatus __asm__("D_8005A810");
extern MipmapLevel mipmapLevels[] __asm__("D_8006A3B0");
extern s32 mipmapMaxLevel __asm__("D_8005A810+64544");
extern u8 *mipmapImage __asm__("D_8006A434");
extern s32 mipmapLineScale __asm__("D_8006A438");
extern u32 mipmapTexelCount __asm__("D_8006A43C");
extern s32 mipmapLevelCount __asm__("D_8006A440");

extern void func_80010800(MipmapLevel *level, s32 *sx, s32 *ty, u32 *out,
                          s32 shift, s32 size);
extern void func_80010968(s32 i, s32 c0, s32 c1, s32 c2, s32 c3, f32 *o0,
                          f32 *o1, f32 *o2, f32 *o3);
extern void func_800103E0(void *dl, TexSource *tex, u8 *image, u8 tile,
                          u8 palette, u8 cms, u8 cmt, u8 masks, u8 maskt,
                          u8 shifts, u8 shiftt);

s32 func_8000F4B0(void *dl, u8 *image, TexSource *tex, u8 tile, u8 palette,
                  u8 cms, u8 cmt, u8 masks, u8 maskt, u8 shifts, u8 shiftt,
                  u8 clampS, u8 clampT)
{
    s32 sx[10];
    s32 ty[10];
    u32 texels[10];
    f32 fr, fg, fb, fa, fi, fdummy, fia;
    u8 *src;
    u8 *dst;
    u8 *p;
    u8 oddStart;
    u8 oddEnd;
    s32 rowBytes;
    s32 padded;
    s32 lineWords;
    s32 x;
    s32 y;
    s32 swz;
    s32 t;
    s32 s;
    s32 sNext;
    s32 sPrev;
    s32 i;
    s32 hi, lo;
    s32 ia;
    s32 arg;
    s32 offset;
    u8 *dstRow;
    s32 shift;
    s32 tNext;
    s32 tPrev;
    s32 r, g, b, ci;
    s32 rowSwz;
    u32 bitPos;
    s32 step;
    double inv16;

    mipmapLineScale = texSizeInfo[tex->size].scale;
    src = tex->src + (tex->y * tex->stride + ((tex->x * mipmapLineScale) >> 1));
    oddStart = (tex->x & 1) && tex->size == 0;
    oddEnd = ((tex->x + tex->width) & 1) && tex->size == 0;
    rowBytes = (tex->width * mipmapLineScale + 1) >> 1;
    padded = rowBytes / 8;
    padded *= 8;
    if (padded < rowBytes) {
        padded += 8;
    }
    dst = image + tex->offset;

    if (oddStart) {
        for (y = 0; y < tex->height; y++) {
            swz = (y & 1) << 2;
            for (x = 0; x < rowBytes; x++) {
                dst[x ^ swz] = ((src[x] & 0xF) << 4) | (src[x + 1] >> 4);
            }
            if (!oddEnd) {
                dst[(x - 1) ^ swz] &= 0xF0;
            }
            for (x = rowBytes; x < padded; x++) {
                dst[x ^ swz] = 0;
            }
            dst += padded;
            src += tex->stride;
        }
    } else {
        for (y = 0; y < tex->height; y++) {
            swz = (y & 1) << 2;
            for (x = 0; x < rowBytes; x++) {
                dst[x ^ swz] = src[x];
            }
            if (oddEnd) {
                dst[(x - 1) ^ swz] &= 0xF0;
            }
            for (x = rowBytes; x < padded; x++) {
                dst[x ^ swz] = 0;
            }
            dst += padded;
            src += tex->stride;
        }
    }

    lineWords = padded / mipmapLineScale;
    step = 8 / mipmapLineScale * 2;
    inv16 = 0.0625;
    mipmapLevels[0].width = tex->width;
    mipmapImage = image;
    mipmapLevels[0].height = tex->height;
    mipmapLevels[0].lineWidth = lineWords * 2;
    mipmapMaxLevel = 7;
    mipmapLevels[0].tmemOffset = tex->offset;
    mipmapTexelCount = mipmapLevels[0].lineWidth * mipmapLevels[0].height;
    shift = texSizeInfo[tex->size].shift;
    mipmapLevelCount = 0;

    while (mipmapLevels[mipmapLevelCount].width >= 2 || mipmapLevels[mipmapLevelCount].height >= 2) {
        {
            mipmapLevelCount++;
            mipmapLevels[mipmapLevelCount].tmemOffset = offset = mipmapLevels[mipmapLevelCount - 1].tmemOffset +
                ((mipmapLevels[mipmapLevelCount - 1].lineWidth * mipmapLineScale *
                  mipmapLevels[mipmapLevelCount - 1].height) >> 1);
            dstRow = mipmapImage + offset;
            mipmapLevels[mipmapLevelCount].width = mipmapLevels[0].width >> mipmapLevelCount;
            mipmapLevels[mipmapLevelCount].height = mipmapLevels[0].height >> mipmapLevelCount;
            if (mipmapLevels[mipmapLevelCount].width == 0) {
                mipmapLevels[mipmapLevelCount].width = 1;
            }
            if (mipmapLevels[mipmapLevelCount].height == 0) {
                mipmapLevels[mipmapLevelCount].height = 1;
            }
            { s32 w1 = mipmapLevels[mipmapLevelCount].width - 1;
            mipmapLevels[mipmapLevelCount].lineWidth =
                ((w1 + step) >> (shift + 1)) << (shift + 1); }
            mipmapTexelCount += mipmapLevels[mipmapLevelCount].lineWidth *
                                mipmapLevels[mipmapLevelCount].height;
            if ((mipmapTexelCount * mipmapLineScale) >> 1 >= 0x1000) {
                mipmapStatus = 1;
                mipmapTexelCount -= mipmapLevels[mipmapLevelCount].lineWidth *
                                    mipmapLevels[mipmapLevelCount].height;
                goto done;
            }

            for (t = 0; t < mipmapLevels[mipmapLevelCount - 1].height; t += 2) {
                swz = 0;
                rowSwz = (t & 2) << 1;
                tNext = t + 1;
                tPrev = t - 1;
                if (clampT) {
                    if (tNext >= mipmapLevels[mipmapLevelCount - 1].height) {
                        tNext = t;
                    }
                    if (tPrev < 0) {
                        tPrev = t;
                    }
                } else {
                    if (tNext >= mipmapLevels[mipmapLevelCount - 1].height) {
                        tNext = 0;
                    }
                    if (tPrev < 0) {
                        tPrev = mipmapLevels[mipmapLevelCount - 1].height - 1;
                    }
                }
                bitPos = 0;
                for (s = 0; s < mipmapLevels[mipmapLevelCount - 1].width; s += 2) {
                    sNext = s + 1;
                    sPrev = s - 1;
                    if (clampS) {
                        if (sNext >= mipmapLevels[mipmapLevelCount - 1].width) {
                            sNext = s;
                        }
                        if (sPrev < 0) {
                            sPrev = s;
                        }
                    } else {
                        if (sNext >= mipmapLevels[mipmapLevelCount - 1].width) {
                            sNext = 0;
                        }
                        if (sPrev < 0) {
                            sPrev = mipmapLevels[mipmapLevelCount - 1].width - 1;
                        }
                    }
                    sx[0] = s;
                    ty[0] = tPrev;
                    sx[1] = sNext;
                    ty[1] = tPrev;
                    sx[2] = sNext;
                    ty[2] = t;
                    sx[3] = sNext;
                    ty[3] = tNext;
                    sx[4] = s;
                    ty[4] = tNext;
                    sx[5] = sPrev;
                    ty[5] = tNext;
                    sx[6] = sPrev;
                    ty[6] = t;
                    sx[7] = sPrev;
                    ty[7] = tPrev;
                    sx[8] = s;
                    ty[8] = t;
                    func_80010800(&mipmapLevels[mipmapLevelCount - 1], sx, ty, texels,
                                  shift, tex->size);
                    lo = hi = 0;
                    r = g = b = ci = 0;
                    fr = fg = fb = fa = fi = fia = 0.0f;
                    p = dstRow + ((bitPos >> 1) ^ rowSwz);

                    switch (tex->format) {
                    case 0:
                        if (tex->size == 2) {
                            for (i = 0; i < 9; i++) {
                                arg = texels[i] & 1;
                                func_80010968(i, (texels[i] & 0xF800) >> 11, (texels[i] & 0x7C0) >> 6,
                                              (texels[i] & 0x3E) >> 1, arg, &fr, &fg, &fb, &fa);
                            }
                            r = fr * inv16 + 0.5;
                            g = fg * inv16 + 0.5;
                            b = fb * inv16 + 0.5;
                            lo = fa * inv16 + 0.5;
                        } else {
                            return mipmapStatus = 2;
                        }
                        break;
                    case 2:
                        if (tex->size == 0) {
                            for (i = 0; i < 9; i++) {
                                func_80010968(i, texels[i] & 0xF, 0, 0, 0, &fi, &fdummy, &fdummy, &fdummy);
                            }
                        } else if (tex->size == 1) {
                            for (i = 0; i < 9; i++) {
                                func_80010968(i, texels[i] & 0xFF, 0, 0, 0, &fi, &fdummy, &fdummy, &fdummy);
                            }
                        } else {
                            return mipmapStatus = 2;
                        }
                        ci = fi * inv16 + 0.5;
                        break;
                    case 3:
                        if (tex->size == 0) {
                            for (i = 0; i < 9; i++) {
                                func_80010968(i, (texels[i] & 0xE) >> 1, texels[i] & 1, 0, 0, &fia, &fa, &fdummy, &fdummy);
                            }
                        } else if (tex->size == 1) {
                            for (i = 0; i < 9; i++) {
                                func_80010968(i, (texels[i] & 0xF0) >> 4, texels[i] & 0xF, 0, 0, &fia, &fa, &fdummy, &fdummy);
                            }
                        } else if (tex->size == 2) {
                            for (i = 0; i < 9; i++) {
                                func_80010968(i, x = (texels[i] >> 8) & 0xFF, arg = texels[i] & 0xFF, 0, 0, &fia, &fa, &fdummy, &fdummy);
                            }
                        } else {
                            return mipmapStatus = 2;
                        }
                        hi = fia * inv16 + 0.5;
                        lo = fa * inv16 + 0.5;
                        break;
                    case 4:
                        if (tex->size == 0) {
                            for (i = 0; i < 9; i++) {
                                func_80010968(i, texels[i] & 0xF, 0, 0, 0, &fia, &fdummy, &fdummy, &fdummy);
                            }
                        } else if (tex->size == 1) {
                            for (i = 0; i < 9; i++) {
                                func_80010968(i, texels[i] & 0xFF, 0, 0, 0, &fia, &fdummy, &fdummy, &fdummy);
                            }
                        } else {
                            return mipmapStatus = 2;
                        }
                        hi = fia * inv16 + 0.5;
                        break;
                    case 1:
                        return mipmapStatus = 2;
                    }

                    switch (tex->format) {
                    case 0:
                        ia = ((r & 0x1F) << 11) | ((g & 0x1F) << 6) | ((b & 0x1F) << 1) | lo;
                        *(u16 *)((u32)p ^ swz) = ia;
                        break;
                    case 1:
                        break;
                    case 2:
                        if (tex->size == 0) {
                            ia = ci;
                            { s32 value; u8 old;
                            register u8 *storePtr __asm__("$5") = (u8 *)((u32)p ^ swz);
                            old = *storePtr;
                            value = old | ((s & 2) ? ia : ia << 4);
                            *storePtr = value; }
                        } else if (tex->size == 1) {
                            *(u8 *)((u32)p ^ swz) = ci;
                        }
                        break;
                    case 3:
                        if (tex->size == 0) {
                            { register s32 highPart __asm__("$2") = (hi & 7) << 1;
                              ia = highPart | (lo & 1); }
                            { s32 value; u8 old;
                            register u8 *storePtr __asm__("$5") = (u8 *)((u32)p ^ swz);
                            old = *storePtr;
                            value = old | ((s & 2) ? ia : ia << 4);
                            *storePtr = value; }
                        } else if (tex->size == 1) {
                            ia = (lo & 0xF) | ((hi & 0xF) << 4);
                            *(u8 *)((u32)p ^ swz) = ia;
                        } else if (tex->size == 2) {
                            ia = (hi << 8) | lo;
                            *(u16 *)((u32)p ^ swz) = ia;
                        }
                        break;
                    case 4:
                        if (tex->size == 0) {
                            ia = hi;
                            { s32 value; u8 old;
                            register u8 *storePtr __asm__("$5") = (u8 *)((u32)p ^ swz);
                            old = *storePtr;
                            value = old | ((s & 2) ? ia : ia << 4);
                            *storePtr = value; }
                        } else if (tex->size == 1) {
                            ia = hi;
                            *(u8 *)((u32)p ^ swz) = ia;
                        }
                        break;
                    }
                    bitPos += mipmapLineScale;
                }
                dstRow += (mipmapLevels[mipmapLevelCount].lineWidth * mipmapLineScale) >> 1;
            }
        }
        if (mipmapLevels[mipmapLevelCount].width < 2 && mipmapLevels[mipmapLevelCount].height < 2) {
            mipmapMaxLevel = mipmapLevelCount;
            goto done;
        }
    }
done:
    func_800103E0(dl, tex, image, tile, palette, cms, cmt, masks, maskt, shifts, shiftt);
    return mipmapStatus;
}
