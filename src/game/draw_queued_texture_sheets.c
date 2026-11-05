/* Byte-exact reconstruction of func_8001A660, ROM 0x1B260..0x1B918.
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
extern Gfx *initialDisplayListBuffers[] __asm__("displayListBuffers");
extern u32 displayListIndex;
extern s32 maximumSpriteLayer;
extern u32 spriteQueueCount;
extern TextureSheet *textureSheets[4];
extern SheetRecord sheetRecords[4];
extern QueueEntry spriteQueue[512];
extern s32 halfWidthMode;
#define HEAD (*(Gfx **)(displayBase + 0x63DC))
#define EMIT(word, value) do { Gfx *command = HEAD++; \
    command->command = (word); command->argument = (u32)(value); } while (0)

#define SETUP_EMIT(reg, n, word, value) do { register Gfx *command __asm__("$" #reg) = initialCursor + (n); \
    HEAD = command + 1; command->command = (word); \
    command->argument = (u32)(value); } while (0)

#define W0(n, value) (((volatile Gfx *)initialCursor)[n].command = (value))
#define W1(pointer, value) (((volatile Gfx *)(pointer))->argument = (u32)(value))
#define COMMIT(pointer) (*(Gfx *volatile *)(displayBase + 0x63DC) = (pointer))

void func_8001A660(void) {
    register u8 *displayBase __asm__("$25");
    register Gfx *initialCursor __asm__("$24");
    register Gfx **initialBuffers __asm__("$3");
    register u8 *bufferPage __asm__("$3");
    register u32 initialIndex __asm__("$2");
    u32 previousAlpha = 0xFFFF;
    register u32 sheetIndex __asm__("$20");
    u32 texture;
    register u32 queueIndex __asm__("$18");
    u8 layer;
    u32 *textureCount;
    TextureSheet **sheetCursor;
    __asm__("" : "+m"(displayListHead));
    initialBuffers = initialDisplayListBuffers;
    initialIndex = displayListIndex;
    initialCursor = displayListHead;
    if (initialCursor - initialBuffers[initialIndex] >= 0x17ED) return;
    {
        register Gfx *p3 __asm__("$3");
        register Gfx *p4 __asm__("$4");
        register Gfx *p5 __asm__("$5");
        register u32 temporary __asm__("$2");
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
        /* Reuse the page already resident in s2; the original schedules this
         * copy instead of materializing a second 0x8006 high half. */
        __asm__("addu $25,$18,$0");
        __asm__("" : "=r"(displayBase));
        p3 = initialCursor + 1;
        layer = 0;
        W0(0, setup0);
        p4 = initialCursor + 2;
        temporary = 0x00800000;
        W1(initialCursor, 0);
        W0(1, setup1);
        W1(p3, temporary);
        temporary = (u32)(initialCursor + 3);
        COMMIT(p3);
        p3 = initialCursor + 4;
        COMMIT(p4);
        W0(2, setup2);
        W1(p4, 0);
        p4 = initialCursor + 5;
        COMMIT((Gfx *)temporary);
        COMMIT(p3);
        W0(3, setup3);
        W1((Gfx *)temporary, 0);
        W0(4, setup4);
        W1(p3, 0);
        p3 = initialCursor + 6;
        temporary = 0xC00;
        W0(5, setup5);
        W1(p4, temporary);
        temporary = (u32)(initialCursor + 7);
        COMMIT(p4);
        COMMIT(p3);
        W0(6, setup6);
        W1(p3, 0);
        p3 = initialCursor + 8;
        p4 = initialCursor + 9;
        COMMIT((Gfx *)temporary);
        W0(7, setup7);
        W1((Gfx *)temporary, 0);
        temporary = 0x30;
        COMMIT(p3);
        W0(8, setup8);
        W1(p3, temporary);
        p3 = initialCursor + 10;
        temporary = 0xC0;
        COMMIT(p4);
        W0(9, setup9);
        W1(p4, temporary);
        p4 = initialCursor + 11;
        p5 = initialCursor + 12;
        temporary = 0xF9000000;
        COMMIT(p3);
        COMMIT(p4);
        W0(10, setup10);
        W1(p3, setup11);
        COMMIT(p5);
        W0(11, temporary);
        temporary = 0xFFFFFF01;
        p3 = initialCursor + 13;
        W1(p4, temporary);
        temporary = 1;
        p4 = initialCursor + 14;
        W0(12, setup7);
        W1(p5, temporary);
        temporary = 0xE7000000;
        COMMIT(p3);
        W0(13, temporary);
        W1(p3, 0);
        p3 = initialCursor + 15;
        temporary = 0xFFFFF3F9;
        W0(14, setup12);
        W1(p4, temporary);
        temporary = (u32)(initialCursor + 16);
        COMMIT(p4);
        COMMIT(p3);
        COMMIT((Gfx *)temporary);
        temporary = 4;
        W0(15, setup13);
        W1(p3, temporary);
    }
    __asm__("" : "+m"(displayListHead));
    for (; ; layer++) {
        s32 depth;
        if (layer > maximumSpriteLayer) break;
        switch (layer) {
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
        sheetIndex = 0;
        { register Gfx *cursor __asm__("$2");
        register Gfx *command __asm__("$3");
        cursor=HEAD;
        __asm__("" : : "r"(cursor));
        __asm__("" : "=r"(sheetCursor) : "0"(textureSheets));
        __asm__("" : : "r"(cursor));
        command=cursor++;
        HEAD=cursor;
        command->command=0xEE000000;
        command->argument=depth<<17; }
        for (; ; sheetIndex++, sheetCursor++) {
            TextureSheet *sheet;
            Gfx *textureCommands;
            SheetEntry *entries;
            if (sheetIndex >= 4) break;
            sheet = *sheetCursor;
            if (!sheet) continue;
            textureCount = &sheet->textureCount;
            entries = sheet->entries;
            textureCommands = (Gfx *)((u8 *)sheet + sheet->displayListOffset);
            for (texture = 0; ; textureCommands = (Gfx *)((u8 *)textureCommands + 0x8E0), texture++) {
                u32 first = 1;
                register QueueEntry *queued __asm__("$13");
                u32 one;
                if (texture >= *textureCount) break;
                queueIndex = 0;
                one = first;
                for (queued = spriteQueue; ; queued++, queueIndex++) {
                    register SpriteObject *object __asm__("$4");
                    u32 encoded;
                    register u32 group __asm__("$14");
                    register s32 entryIndex __asm__("$11");
                    u32 alpha;
                    Gfx *packet, *rectangle;
                    register Gfx *coords __asm__("$6");
                    Gfx *end;
                    register u32 rectangleWord __asm__("$4");
                    u32 rectangleArgument;
                    u32 s, t, step;
                    s32 x, y, width, height, originX, originY;
                    u32 dx, dy;
                    s32 adjustment;
                    if (queueIndex >= spriteQueueCount) break;
                    object = queued->object;
                    if (object->layer != layer) continue;
                    encoded = object->sheetEntry;
                    group = encoded >> 8;
                    if (group != sheetIndex) continue;
                    entryIndex = (encoded & 0xFF) - 3;
                    if (entries[entryIndex].textureGroup != texture) continue;
                    if (HEAD - displayListBuffers[displayListIndex] >= 0x17ED)
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
                        register u32 argument __asm__("$2") = 0x050505FF;
                        register Gfx *cursor __asm__("$3") = HEAD;
                        register Gfx *command __asm__("$4") = cursor;
                        cursor++;
                        __asm__("lui $23,0xFA00");
                        HEAD = cursor;
                        __asm__("sw $23,0(%0)" : : "r"(command));
                        command->argument = argument;
                    } else {
                        register Gfx *cursor __asm__("$2") = HEAD;
                        register Gfx *command __asm__("$3") = cursor;
                        register u32 argument __asm__("$2");
                        cursor++;
                        __asm__("lui $23,0xFA00");
                        HEAD = cursor;
                        argument = 0xFFFFFF00 | alpha;
                        __asm__("" : "+r"(argument));
                        __asm__("sw $23,0(%0)" : : "r"(command));
                        command->argument = argument;
                    }
                    if (halfWidthMode == one) {
                        dx = 0x800;
                        dy = 0x400;
                        queued->x >>= 1;
                        x = entries[entryIndex].x;
                        y = entries[entryIndex].y;
                        width = entries[entryIndex].width << 1;
                        height = entries[entryIndex].height << 2;
                    } else {
                        dx = dy = 0x400;
                        x = entries[entryIndex].x;
                        y = entries[entryIndex].y;
                        width = entries[entryIndex].width << 2;
                        height = entries[entryIndex].height << 2;
                    }
                    if (halfWidthMode == one) x <<= 1;
                    else x <<= 2;
                    y <<= 2;
                    {
                    register u32 fv __asm__("$5") = sheetRecords[group].frameValue;
                    register u32 opcode __asm__("$2");
                    register u32 bottom __asm__("$3");
                    u32 yArgument;
                    __asm__ volatile ("" : "=r"(opcode) : "0"(0xE4000000), "r"(fv) : "memory");
                    packet = HEAD;
                    rectangle = packet++;
                    originX = x + queued->x;
                    originY = queued->y + y;
                    __asm__ volatile ("" : "=r"(fv) : "0"(fv), "r"(originY));
                    fv = (fv - 6) << 1;
                    __asm__ volatile ("" : : "r"(opcode), "r"(fv), "r"(originY) : "$4");
                    rectangleWord = originX + width;
                    bottom = originY + height - fv;
                    rectangleWord &= 0xFFF;
                    rectangleWord <<= 12;
                    bottom &= 0xFFF;
                    bottom |= opcode;
                    rectangleWord |= bottom;
                    yArgument = originY - fv;
                    __asm__ volatile ("" : "=r"(originX) : "0"(originX), "r"(yArgument));
                    rectangleArgument = (originX & 0xFFF) << 12;
                    rectangleArgument |= yArgument & 0xFFF;
                    }
                    coords = packet + 1;
                    rectangle->command = rectangleWord;
                    rectangle->argument = rectangleArgument;
                    packet[0].command = 0xE1000000;
                    __asm__ volatile ("" : : "r"((u32)entryIndex * 20 + (u32)entries) : "$5");
                    { register Gfx *sync __asm__("$5") = packet + 2;
                    *(Gfx *volatile *)(displayBase + 0x63DC) = packet;
                    *(Gfx *volatile *)(displayBase + 0x63DC) = coords;
                    s = entries[entryIndex].s;
                    t = entries[entryIndex].t;
                    packet[1].command = 0xF1000000;
                    end = packet + 3;
                    *(Gfx *volatile *)(displayBase + 0x63DC) = sync;
                    *(Gfx *volatile *)(displayBase + 0x63DC) = end;
                    step = (dx << 16) | dy;
                    packet[0].argument = (s << 21) | (t << 5);
                    coords->argument = step;
                    packet[2].command = 0xE7000000;
                    sync->argument = 0;
                    }
                }
            }
        }
    }
reset:
    {
        register u32 resetMode __asm__("$6") = 0xE3000C00;
        register u32 resetOther __asm__("$7") = 0xE2000000;
        register u8 *resetPage __asm__("$4") = (u8 *)0x80060000;
        register Gfx *resetCursor __asm__("$2");
        register Gfx *resetNext __asm__("$5");
        register u32 temporary __asm__("$3");
        __asm__ volatile ("" : "=r"(resetOther) : "0"(resetOther));
        __asm__ volatile ("" : : "r"(resetPage));
        resetOther |= 0x1D00;
        resetCursor = *(Gfx *volatile *)(resetPage + 0x63DC);
        temporary = 0xE7000000;
        resetNext = resetCursor;
        resetCursor++;
        ((volatile Gfx *)resetNext)->command = temporary;
        ((volatile Gfx *)resetNext)->argument = 0;
        resetNext = resetCursor + 1;
        temporary = 0x80000;
        ((volatile Gfx *)resetCursor)->argument = temporary;
        temporary = (u32)(resetCursor + 2);
        *(Gfx *volatile *)(resetPage + 0x63DC) = resetCursor;
        *(Gfx *volatile *)(resetPage + 0x63DC) = resetNext;
        ((volatile Gfx *)resetCursor)->command = resetMode;
        *(Gfx *volatile *)(resetPage + 0x63DC) = (Gfx *)temporary;
        ((volatile Gfx *)resetCursor)[1].command = resetOther;
        ((volatile Gfx *)resetNext)->argument = 0;
    }
}
