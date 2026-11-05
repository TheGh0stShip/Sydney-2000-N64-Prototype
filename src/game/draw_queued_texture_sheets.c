/* NONMATCHING reconstruction of func_8001A660, ROM 0x1B260..0x1B918.
 * All pointers and display-list address tokens use the N64 big-endian o32 ABI.
 * Sampled behavior: tools/validate_queued_texture_sheets.py (SN GCC -O2).
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u32 command, argument; } Gfx;
typedef struct {
    u16 id, textureGroup;
    u8 s, t, width, height;
    s8 x, y;
    u8 unused0A[10];
} SheetEntry;
typedef struct {
    u32 displayListOffset;
    u8 unused04[12];
    u32 textureCount;
    u8 unused14[12];
    SheetEntry entries[1];
} TextureSheet;
typedef struct {
    u16 frameCount, cursor, frameValue;
    u16 unused06;
    void *frames;
} SheetRecord;
typedef struct {
    u8 unused00[0xC0];
    u32 flags;
    u32 sheetEntry;
    u8 unusedC8;
    u8 layer;
    u8 unusedCA;
    u8 alpha;
} SpriteObject;
typedef struct { SpriteObject *object; s16 x, y; } QueueEntry;
typedef char check_entry_size[sizeof(SheetEntry) == 20 ? 1 : -1];
typedef char check_queue_size[sizeof(QueueEntry) == 8 ? 1 : -1];
typedef char check_record_size[sizeof(SheetRecord) == 12 ? 1 : -1];
extern Gfx *displayListHead;
extern Gfx *displayListBuffers[];
extern u32 displayListIndex;
extern s32 maximumSpriteLayer;
extern u32 spriteQueueCount;
extern TextureSheet *textureSheets[4];
extern SheetRecord sheetRecords[4];
extern QueueEntry spriteQueue[512];
extern s32 halfWidthMode;
#define EMIT(word, value) do { Gfx *command = displayListHead++; \
    command->command = (word); command->argument = (u32)(value); } while (0)

void func_8001A660(void) {
    register Gfx *initialCursor __asm__("$24") = displayListHead;
    register Gfx **initialBuffers __asm__("$3") = displayListBuffers;
    register u32 previousAlpha __asm__("$22") = 0xFFFF;
    register u32 sheetIndex __asm__("$20");
    register u32 texture __asm__("$24");
    register u32 queueIndex __asm__("$18");
    struct {
        u8 reserved00[7];
        u8 layer;
        u32 *volatile textureCount;
        u32 reserved0C;
        TextureSheet **volatile sheetCursor;
    } frame;
    if (initialCursor - initialBuffers[displayListIndex] >= 0x17ED) return;
    __asm__("" : "=m"(frame));
    frame.layer = 0;
    {
        /* Keep setup command constants in their original live registers. */
        register u32 setup0 __asm__("$4") = 0xE3000A01;
        register u32 setup1 __asm__("$5") = 0xE3000800;
        register u32 setup2 __asm__("$6") = 0xE3000D01;
        register u32 setup3 __asm__("$7") = 0xE3000C00;
        register u32 setup4 __asm__("$8") = 0xE3001201;
        register u32 setup5 __asm__("$9") = 0xE3001402;
        register u32 setup6 __asm__("$11") = 0xE3001700;
        register u32 setup7 __asm__("$10") = 0xE2001E01;
        register u32 setup8 __asm__("$12") = 0xE3001A01;
        register u32 setup9 __asm__("$13") = 0xE3001801;
        register u32 setup10 __asm__("$15") = 0xE200001C;
        register u32 setup11 __asm__("$14") = 0x00500278;
        register u32 setup12 __asm__("$16") = 0xFC11FE23;
        register u32 setup13 __asm__("$17") = 0xE2001D00;
        __asm__("" : "=r"(setup0) : "0"(setup0));
        __asm__("" : "=r"(setup1) : "0"(setup1));
        __asm__("" : "=r"(setup2) : "0"(setup2));
        __asm__("" : "=r"(setup3) : "0"(setup3));
        __asm__("" : "=r"(setup4) : "0"(setup4));
        __asm__("" : "=r"(setup5) : "0"(setup5));
        __asm__("" : "=r"(setup6) : "0"(setup6));
        __asm__("" : "=r"(setup7) : "0"(setup7));
        __asm__("" : "=r"(setup8) : "0"(setup8));
        __asm__("" : "=r"(setup9) : "0"(setup9));
        __asm__("" : "=r"(setup10) : "0"(setup10));
        __asm__("" : "=r"(setup11) : "0"(setup11));
        __asm__("" : "=r"(setup12) : "0"(setup12));
        __asm__("" : "=r"(setup13) : "0"(setup13));
        EMIT(setup0, 0);
        EMIT(setup1, 0x00800000);
        EMIT(setup2, 0);
        EMIT(setup3, 0);
        EMIT(setup4, 0);
        EMIT(setup5, 0xC00);
        EMIT(setup6, 0);
        EMIT(setup7, 0);
        EMIT(setup8, 0x30);
        EMIT(setup9, 0xC0);
        EMIT(setup10, setup11);
        EMIT(0xF9000000, 0xFFFFFF01);
        EMIT(setup7, 1);
        EMIT(0xE7000000, 0);
        EMIT(setup12, 0xFFFFF3F9);
        EMIT(setup13, 4);
    }
    for (; ; frame.layer++) {
        s32 depth;
        if (frame.layer > maximumSpriteLayer) break;
        switch (frame.layer) {
        case 0: depth = 32; break;
        case 1: depth = 24; break;
        case 2: depth = 22; break;
        case 3: depth = 20; break;
        case 4: depth = 18; break;
        case 5: depth = 16; break;
        case 6: depth = 8; break;
        case 7: depth = 6; break;
        case 8: depth = 4; break;
        case 9: depth = 2; break;
        default: depth = 32; break;
        }
        EMIT(0xEE000000, depth << 17);
        for (sheetIndex = 0, frame.sheetCursor = textureSheets; ; sheetIndex++, frame.sheetCursor++) {
            TextureSheet *sheet;
            register Gfx *textureCommands __asm__("$19");
            register SheetEntry *entries __asm__("$17");
            if (sheetIndex >= 4) break;
            sheet = *frame.sheetCursor;
            if (!sheet) continue;
            frame.textureCount = &sheet->textureCount;
            entries = sheet->entries;
            textureCommands = (Gfx *)((u8 *)sheet + sheet->displayListOffset);
            for (texture = 0; ; texture++,
                 textureCommands = (Gfx *)((u8 *)textureCommands + 0x8E0)) {
                register u32 first __asm__("$21") = 1;
                register QueueEntry *queued __asm__("$13");
                if (texture >= *frame.textureCount) break;
                for (queueIndex = 0, queued = spriteQueue; ; queueIndex++, queued++) {
                    SpriteObject *object;
                    u32 encoded;
                    register u32 group __asm__("$14");
                    register s32 entryIndex __asm__("$11");
                    u32 alpha;
                    s32 x, y, width, height, originX, originY;
                    u32 dx, dy;
                    s32 adjustment;
                    if (queueIndex >= spriteQueueCount) break;
                    object = queued->object;
                    if (object->layer != frame.layer) continue;
                    encoded = object->sheetEntry;
                    group = encoded >> 8;
                    if (group != sheetIndex) continue;
                    entryIndex = (encoded & 0xFF) - 3;
                    if (entries[entryIndex].textureGroup != texture) continue;
                    if (displayListHead - displayListBuffers[displayListIndex] >= 0x17ED)
                        goto reset;
                    if (first) {
                        first = 0;
                        EMIT(0xDE000000, textureCommands);
                    }
                    alpha = queued->object->alpha;
                    if (alpha == 0xFF) {
                        if (previousAlpha != alpha) EMIT(0xFC11FE23, 0xFFFFF3F9);
                    } else {
                        if (previousAlpha != alpha) EMIT(0xFC119623, 0xFF2FFFFF);
                    }
                    previousAlpha = alpha;
                    if (queued->object->flags & 0x80000) {
                        EMIT(0xFA000000, 0x050505FF);
                    } else {
                        EMIT(0xFA000000, 0xFFFFFF00 | alpha);
                    }
                    dy = 0x400;
                    if (halfWidthMode == 1) {
                        dx = 0x800;
                        queued->x >>= 1;
                        x = entries[entryIndex].x;
                        y = entries[entryIndex].y;
                        width = entries[entryIndex].width << 1;
                        height = entries[entryIndex].height << 2;
                    } else {
                        dx = 0x400;
                        x = entries[entryIndex].x;
                        y = entries[entryIndex].y;
                        width = entries[entryIndex].width << 2;
                        height = entries[entryIndex].height << 2;
                    }
                    if (halfWidthMode == 1) x <<= 1;
                    else x <<= 2;
                    y <<= 2;
                    adjustment = (sheetRecords[group].frameValue - 6) << 1;
                    originX = x + queued->x;
                    originY = y + queued->y;
                    EMIT(0xE4000000 | (((originX + width) & 0xFFF) << 12) |
                         ((originY + height - adjustment) & 0xFFF),
                         ((originX & 0xFFF) << 12) | ((originY - adjustment) & 0xFFF));
                    EMIT(0xE1000000, (entries[entryIndex].s << 21) |
                         (entries[entryIndex].t << 5));
                    EMIT(0xF1000000, (dx << 16) | dy);
                    EMIT(0xE7000000, 0);
                }
            }
        }
    }
reset:
    EMIT(0xE7000000, 0);
    EMIT(0xE3000C00, 0x80000);
    EMIT(0xE2001D00, 0);
}
