/* Exact func_8000CA34: load a texture resource and emit its GBI commands.
 * Field names are provisional; target widths/layouts follow the N64 o32 ABI.
 * The fixed height register and empty early clobber constrain SN allocation;
 * they supply no target instructions. Complete text and constants are checked.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u32 identifier;
    u8 padding04[4];
    u16 field08;
    u8 padding0A[6];
    Gfx commands[25];
    u8 *fieldD8;
    u8 paddingDC[4];
} ResourceRecord;

typedef struct {
    u8 logWidth;
    u8 logHeight;
    u8 flags;
    u8 format;
    u8 pad4[2];
    u8 field6;
    u8 field7;
    u32 field8;
    u32 padC;
} TextureHeader;

typedef struct {
    u8 field0;
    u8 field1;
    u8 field2;
    u8 field3;
    u32 field4;
    u64 field8;
    u8 *field10;
    u8 *field14;
    u32 field18;
    u32 field1C;
    u64 field20;
    u32 field28;
    u32 field2C;
} AnimEntry;

typedef struct {
    u32 w[11];
} TextureDesc;

typedef char texture_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char texture_word_width[sizeof(u32) == 4 ? 1 : -1];
typedef char texture_counter_width[sizeof(u64) == 8 ? 1 : -1];
typedef char texture_command_size[sizeof(Gfx) == 8 ? 1 : -1];
typedef char texture_header_size[sizeof(TextureHeader) == 0x10 ? 1 : -1];
typedef char texture_record_size[sizeof(ResourceRecord) == 0xE0 ? 1 : -1];
typedef char texture_animation_size[sizeof(AnimEntry) == 0x30 ? 1 : -1];
extern u32 D_80039450;
extern u32 D_80047824[];
extern u32 D_80047984;
extern u32 D_80047988;
extern u32 D_8004798C;
extern ResourceRecord D_80049A28[];
extern u32 D_800499E0;
extern AnimEntry *D_8005A0A8;
extern TextureDesc D_8005A500;
extern u8 D_80064740[];
extern u32 D_800693A0;
extern u32 D_800693A4;
extern u32 D_800693A8;
extern u32 D_800693AC;
extern u8 D_800693B0[];

extern s32 func_80037E9C(void);
extern void func_800320B0(const char *, ...);
extern TextureHeader *func_8000F13C(u32);
extern void func_8001C644(void);
extern void func_8002F684(void *, void *, u32);
extern void func_8000F4B0(Gfx **, void *, TextureDesc *, u32, u32, s32, s32, u32, u32, u32, u32, u32, u32);
extern u64 func_800341E0(void);

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define WORDS(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }

s32 func_8000CA34(u32 id, u32 clearMip, u32 unused2, u32 unused3, s32 index, u32 flags)
{
    s32 reset = 0;
    s32 found;
    s32 cms = 0;
    s32 cmt = 0;
    Gfx *gfx;
    TextureHeader *hdr;
    u8 *data;
    u64 time;
    u32 w, logW, logH, ss, ts, fmt;
    register u32 h __asm__("$23");

    if (D_80039450 != 0) {
        u32 k;
        for (k = 0; D_80047824[k] != 0; k++) {
            if (id == D_80047824[k]) {
                __asm__("" : : : "$23");
                switch (func_80037E9C() % 4) {
                case 0:
                    id = D_800693A0;
                    break;
                case 1:
                    id = D_800693A4;
                    break;
                case 2:
                    id = D_800693A8;
                    break;
                case 3:
                    id = D_800693AC;
                    break;
                case 4:
                    id = D_800693A0;
                    break;
                default:
                    id = D_800693A0;
                    break;
                }
            }
        }
    }

    found = -1;
    if (index == found) {
        u32 i;
        for (i = 0; i < D_80047984; i++) {
            if (id == D_80049A28[i].identifier) {
                return i;
            }
            if (D_80049A28[i].identifier == 0xFFFE) {
                found = i;
            }
        }
        if (found == -1) {
            index = D_80047984++;
        } else {
            index = found;
        }
        D_80049A28[index].field08 = 0;
    }

    if (D_80047984 >= 300) {
        for (;;) {
            func_800320B0("Aggg 1 %d\n", id);
        }
    }

    D_80049A28[index].identifier = id;
    data = (u8 *)func_8000F13C(id);
    if (data == 0) {
        for (;;) {
            func_800320B0("Aggg 2 %d\n", id);
        }
    }
    hdr = (TextureHeader *)data;
    D_80049A28[index].fieldD8 = data;
    if (clearMip) {
        ((TextureHeader *)data)->flags &= ~0x10;
    }
    data += 0x10;
    if (id == D_800499E0) {
        data = D_80064740;
        func_8001C644();
    }

    gfx = D_80049A28[index].commands;
    WORDS(gfx++, 0xE7000000, 0);

    w = 1 << hdr->logWidth;
    ss = w << 10;
    h = 1 << hdr->logHeight;
    ts = h << 10;
    logW = hdr->logWidth;
    logH = hdr->logHeight;
    if (ss > 0xFFFF) ss = 0xFFFF;
    if (ts > 0xFFFF) ts = 0xFFFF;
    if (flags & 1) cms = 2;
    if (flags & 2) cmt = 2;

    fmt = hdr->format;
    if (fmt == 0) {
        if (hdr->flags & 0x10) {
            u32 lvl;
            func_8002F684(D_800693B0, data, w * h * 2);
            D_8005A500.w[0] = (u32)D_800693B0;
            D_8005A500.w[2] = 2;
            D_8005A500.w[5] = w * 2;
            D_8005A500.w[1] = 0;
            D_8005A500.w[3] = w;
            D_8005A500.w[4] = h;
            D_8005A500.w[6] = 0;
            D_8005A500.w[7] = w;
            D_8005A500.w[8] = h;
            D_8005A500.w[9] = 0;
            D_8005A500.w[10] = 0;
            lvl = logW;
            if (logH < logW) lvl = logH;
            WORDS(gfx++, 0xD7000002 | ((lvl & 7) << 11), (ss << 16) | (ts & 0xFFFF));
            WORDS(gfx++, 0xE3001001, 0);
            func_8000F4B0(&gfx, data, &D_8005A500, 0, 0, cms, cmt, logW, logH, 1, 1, 0, 0);
        } else {
            u32 words, dxt, lrs;
            WORDS(gfx++, 0xE3001001, 0);
            WORDS(gfx++, 0xD7000002, (ss << 16) | (ts & 0xFFFF));
            WORDS(gfx++, 0xFD100000, (u32)data);
            WORDS(gfx++, 0xF5100000, 0x07000000 | (cmt << 18) | ((logH & 0xF) << 14) | (cms << 8) | ((logW & 0xF) << 4));
            WORDS(gfx++, 0xE6000000, 0);
            {
                Gfx *_g = gfx++;
                _g->w0 = 0xF3000000;
                lrs = 0x07000000 | ((MIN(w * h - 1, 0x7FF) & 0xFFF) << 12) | ((((1 << 11) + MAX(1, w * 2 / 8) - 1) / MAX(1, w * 2 / 8)) & 0xFFF); _g->w1 = lrs;
            }
            WORDS(gfx++, 0xE7000000, 0);
            WORDS(gfx++, 0xF5100000 | ((((w * 2) + 7) >> 3 & 0x1FF) << 9), (cmt << 18) | ((logH & 0xF) << 14) | (cms << 8) | ((logW & 0xF) << 4));
            WORDS(gfx++, 0xF2000000, ((((w - 1) << 2) & 0xFFF) << 12) | (((h - 1) << 2) & 0xFFF));
            WORDS(gfx++, 0xDF000000, 0);
            goto done;
        }
    } else if (fmt == 4) {
        u32 words, dxt, lrs;
        WORDS(gfx++, 0xE3001001, 0x8000);
        WORDS(gfx++, 0xFD100000, (u32)data);
        WORDS(gfx++, 0xE8000000, 0);
        WORDS(gfx++, 0xF5000100, 0x07000000);
        WORDS(gfx++, 0xE6000000, 0);
        WORDS(gfx++, 0xF0000000, 0x0703C000);
        WORDS(gfx++, 0xE7000000, 0);
        WORDS(gfx++, 0xD7000002, (ss << 16) | (ts & 0xFFFF));
        WORDS(gfx++, 0xFD500000, (u32)(data + 0x20));
        WORDS(gfx++, 0xF5500000, 0x07000000 | (cmt << 18) | ((logH & 0xF) << 14) | (cms << 8) | ((logW & 0xF) << 4));
        WORDS(gfx++, 0xE6000000, 0);
        {
            Gfx *_g = gfx++;
            _g->w0 = 0xF3000000;
            lrs = 0x07000000 | ((MIN(((w * h + 3) >> 2) - 1, 0x7FF) & 0xFFF) << 12) | ((((1 << 11) + MAX(1, w / 16) - 1) / MAX(1, w / 16)) & 0xFFF); _g->w1 = lrs;
        }
        WORDS(gfx++, 0xE7000000, 0);
        WORDS(gfx++, 0xF5400000 | (((w >> 1) + 7) >> 3 & 0x1FF) << 9, (cmt << 18) | ((logH & 0xF) << 14) | (cms << 8) | ((logW & 0xF) << 4));
        WORDS(gfx++, 0xF2000000, ((((w - 1) << 2) & 0xFFF) << 12) | (((h - 1) << 2) & 0xFFF));
    }
    WORDS(gfx++, 0xDF000000, 0);
done:
    if (hdr->field6 != 0 && D_8004798C < D_80047988) {
        if (reset) {
            D_8005A0A8[D_8004798C].field28 = 1;
        }
        D_8005A0A8[D_8004798C].field0 = hdr->field6;
        D_8005A0A8[D_8004798C].field1 = hdr->field7;
        D_8005A0A8[D_8004798C].field8 = hdr->field8;
        if (hdr->format == 0) {
            D_8005A0A8[D_8004798C].field10 = data;
            D_8005A0A8[D_8004798C].field18 = w * h * 2;
        } else if (hdr->format == 4) {
            D_8005A0A8[D_8004798C].field10 = data + 0x20;
            D_8005A0A8[D_8004798C].field18 = (w * h) >> 1;
        }
        D_8005A0A8[D_8004798C].field14 = D_8005A0A8[D_8004798C].field10;
        D_8005A0A8[D_8004798C].field14 += D_8005A0A8[D_8004798C].field18;
        time = func_800341E0();
        D_8005A0A8[D_8004798C].field20 = time;
        D_8005A0A8[D_8004798C].field2 = 0;
        D_8005A0A8[D_8004798C].field3 = 1;
        D_8004798C++;
    }
    return index;
}
