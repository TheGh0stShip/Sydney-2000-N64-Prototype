/* Exact reconstruction of func_8000B608, including all 0xA28 text bytes.
 * Structure names are provisional; offsets follow the original o32 layout. */
/* Build per-track entries and range records for a source model/track set. */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef float f32;

typedef struct { u32 w0; u16 h4; u16 h6; } Sub8;

typedef struct {
    s16 a[4][4];        /* 0x00 */
    s16 b[4][6];        /* 0x20 */
    void *p50[4];       /* 0x50 */
    Sub8 *p60[4];       /* 0x60 */
    u8 pad70[8];        /* 0x70 */
    u16 h78[4];         /* 0x78 */
    u8 b80;             /* 0x80 */
    u8 pad81;
    u16 h82;            /* 0x82 */
} Track;

typedef struct {
    u32 w0;
    u16 start[4];
    u16 end[4];
} Record;

typedef struct {
    s16 a[4][4];        /* 0x00 */
    s16 c[4][6];        /* 0x20 */
    Record *p50[4];     /* 0x50 */
    u16 h60[4];         /* 0x60 */
    u8 b68;             /* 0x68 */
    u8 pad69[3];
    u16 h6C;            /* 0x6C */
    u16 pad6E;
} Entry;

typedef struct { u32 a, b; } Elem8;
typedef struct { u32 a, b, c, d; } Elem16;

typedef struct {
    u8 pad00[0x14];
    f32 f14, f18, f1C;  /* 0x14 */
    u16 h20;            /* 0x20 */
    u16 pad22;
    u32 n24;            /* 0x24 */
    u32 pad28;
    Track *tracks;      /* 0x2C */
    u32 pad30;
    void *p34;          /* 0x34 */
    u32 pad38;
    void *p3C;          /* 0x3C */
    u32 pad40[2];
    void *p48;          /* 0x48 */
    u32 pad4C;
    u32 n50;            /* 0x50 */
    u16 *p54;           /* 0x54 */
} Source;

typedef struct {
    u32 flags;          /* 0x00 */
    u32 n4;             /* 0x04 */
    u32 max8;           /* 0x08 */
    Entry *entries;     /* 0x0C */
    Record *records;    /* 0x10 */
    u32 pad14;
    Elem8 *p18;         /* 0x18 */
    Elem16 *p1C;        /* 0x1C */
    u32 recordSize;     /* 0x20 */
    u32 entrySize;      /* 0x24 */
    u32 pad28;
    f32 f2C, f30, f34;  /* 0x2C */
    u32 pad38[4];
    u32 n48;            /* 0x48 */
    u32 n4C;            /* 0x4C */
} Dest;

typedef char check_track_size[sizeof(Track) == 0x84 ? 1 : -1];
typedef char check_entry_size[sizeof(Entry) == 0x70 ? 1 : -1];
typedef char check_record_size[sizeof(Record) == 20 ? 1 : -1];
typedef char check_track_pointer[sizeof(void *) == 4 ? 1 : -1];

extern void *D_80047814;
extern u32 D_80047998;
extern u32 D_8004799C;
extern u32 D_800F1258;
extern Record *D_8005A0FC[];
extern char D_80000614[];
extern char D_8000061C[];
extern char D_80000628[];

extern s32 func_800AA804(void *heap, void *output, s32 size, const char *tag);
extern s32 func_800AA488(void *heap, void *output, s32 size);
extern void func_8000AD30(Sub8 *, void *, void *, void *, void *, u32, Elem16 *, Elem8 *);
extern void func_8002F684(void *, void *, s32);
extern u32 func_8000C68C(u32, s32, s32, s32, u32);

void func_8000B608(Source *arg0, Dest *dst) {
    Elem16 *buf16;
    Elem8 *buf8;
    Track *tracks;
    Source *src;
    void *p48;
    u16 *p54;
    void *p50;
    void *p34;
    void *p3C;
    u32 pass;
    u32 count;
    u32 total;
    u32 i, j, k, m;
    u32 n;
    Sub8 *sub;
    s32 span;
    u32 key, w, fl;
    Record *rec;

    src = arg0;
    D_80047998 = 0;
    D_8004799C = 0;
    tracks = src->tracks;
    p34 = src->p34;
    p3C = src->p3C;
    if (src->h20 > 1) {
        dst->f2C = src->f14;
        dst->f30 = src->f18;
        dst->f34 = src->f1C;
    } else {
        dst->f2C = dst->f30 = dst->f34 = 0.0f;
    }
    dst->entrySize = src->n24 * sizeof(Entry);
    dst->entries = 0;
    dst->records = 0;
    func_800AA804(D_80047814, &dst->entries, dst->entrySize, D_80000614);

    count = 0;
    for (i = 0; i < src->n24; i++) {
        for (j = 0; j < tracks[i].b80; j++) {
            for (k = 0; k < tracks[i].h78[j]; k++) {
                count++;
            }
        }
    }
    dst->recordSize = count * sizeof(Record);
    func_800AA804(D_80047814, &dst->records, dst->recordSize, D_80000614);

    dst->max8 = 0;
    dst->n48 = D_80047998;
    dst->n4 = src->n24;
    for (i = 0; i < src->n24; i++) {
        dst->entries[i].b68 = tracks[i].b80;
        dst->entries[i].h6C = tracks[i].h82;
        if (dst->max8 < dst->entries[i].h6C) {
            dst->max8 = dst->entries[i].h6C;
        }
        for (j = 0; j < 4; j++) {
            dst->entries[i].a[j][0] = tracks[i].a[j][0] / 2;
            dst->entries[i].a[j][1] = tracks[i].a[j][1] / 2;
            dst->entries[i].a[j][2] = tracks[i].a[j][2] / 2;
            dst->entries[i].a[j][3] = tracks[i].a[j][3];
            dst->entries[i].c[j][0] = tracks[i].b[j][0] / 2;
            dst->entries[i].c[j][1] = tracks[i].b[j][2] / 2;
            dst->entries[i].c[j][2] = tracks[i].b[j][4] / 2;
            dst->entries[i].c[j][3] = tracks[i].b[j][1] / 2;
            dst->entries[i].c[j][4] = tracks[i].b[j][3] / 2;
            dst->entries[i].c[j][5] = tracks[i].b[j][5] / 2;
            dst->entries[i].h60[j] = tracks[i].h78[j];
        }
    }

    total = 0;
    buf16 = 0;
    buf8 = 0;
    p54 = src->p54;
    for (i = 0; i < src->n24; i++) {
        for (j = 0; j < tracks[i].b80; j++) {
            sub = tracks[i].p60[j];
            for (k = 0; k < tracks[i].h78[j]; k++) {
                total += sub->h6 * 3;
                sub++;
            }
        }
    }
    total++;
    func_800AA804(D_80047814, &buf16, total * sizeof(Elem16), D_8000061C);

    for (pass = 0; pass < 2; pass++) {
        if (pass == 1) {
            func_800AA488(D_80047814, &buf16, (D_80047998 + 1) * sizeof(Elem16));
            func_800AA804(D_80047814, &buf8, D_8004799C * sizeof(Elem8), D_80000628);
        }
        D_80047998 = 0;
        D_8004799C = 0;
        n = 0;
        p48 = src->p48;
        for (i = 0; i < src->n24; i++) {
            for (j = 0; j < tracks[i].b80; j++) {
                sub = tracks[i].p60[j];
                p50 = tracks[i].p50[j];
                dst->entries[i].p50[j] = &dst->records[n];
                m = 0;
                for (k = 0; k < tracks[i].h78[j]; k++) {
                    dst->records[n].start[0] = D_8004799C;
                    dst->records[n].w0 = p54[sub->w0];
                    D_8005A0FC[0] = rec = &dst->records[n];
                    rec->w0 |= 0xC0000000;
                    func_8000AD30(sub, p50, p34, p3C, p48, pass, buf16, buf8);
                    dst->records[n].end[0] = (u16)D_8004799C - 1;
                    span = dst->records[n].end[0] - dst->records[n].start[0];
                    span++;
                    dst->records[n].start[1] = D_8004799C;
                    D_8004799C += span;
                    dst->records[n].end[1] = (u16)D_8004799C - 1;
                    if (D_800F1258) {
                        dst->records[n].start[2] = D_8004799C;
                        D_8004799C += span;
                        dst->records[n].end[2] = (u16)D_8004799C - 1;
                        dst->records[n].start[3] = D_8004799C;
                        D_8004799C += span;
                        dst->records[n].end[3] = (u16)D_8004799C - 1;
                    }
                    if (pass == 1) {
                        func_8002F684((void *)(dst->records[n].start[1] * 8 + (u32)buf8), (void *)(dst->records[n].start[0] * 8 + (u32)buf8), span * sizeof(Elem8));
                        {
                            Elem8 *copyBuffer = buf8;
                            if (D_800F1258) {
                                func_8002F684((void *)(dst->records[n].start[2] * 8 + (u32)copyBuffer), (void *)(dst->records[n].start[0] * 8 + (u32)copyBuffer), span * sizeof(Elem8));
                                func_8002F684((void *)(dst->records[n].start[3] * 8 + (u32)buf8), (void *)(dst->records[n].start[0] * 8 + (u32)buf8), span * sizeof(Elem8));
                            }
                        }
                    }
                    sub++;
                    n++;
                    m++;
                }
                if (pass == 1) {
                    dst->entries[i].h60[j] = m;
                }
            }
        }
    }

    dst->n4C = D_80047998 - 1;
    dst->p18 = buf8;
    dst->p1C = buf16;
    if (D_800F1258) {
        dst->flags |= 0x80;
    }

    for (j = 0; j < src->n50; j++) {
        for (i = 0; i < n; i++) {
            key = dst->records[i].w0 & 0x3FFFFFFF;
            if (key == p54[src->n50 + j]) {
                fl = 0;
                if (dst->records[i].w0 & 0x80000000) {
                    fl = 1;
                }
                if (dst->records[i].w0 & 0x40000000) {
                    fl |= 2;
                }
                for (k = i + 1; k < n; k++) {
                    if ((dst->records[k].w0 & 0x3FFFFFFF) == key) {
                        if (!(dst->records[k].w0 & 0x80000000)) {
                            fl &= ~1;
                        }
                        if (!(dst->records[k].w0 & 0x40000000)) {
                            fl &= ~2;
                        }
                    }
                }
                dst->records[i].w0 = func_8000C68C(key, 0, 0, 0, fl) | 0x20000000;
            }
        }
    }
    for (i = 0; i < n; i++) {
        dst->records[i].w0 &= ~0x20000000;
    }
}
