#ifndef LEAF_NAME
#define LEAF_NAME writeSaveEeprom
#endif

#ifndef DISABLE_INTERRUPTS_NAME
#define DISABLE_INTERRUPTS_NAME disableInterrupts
#endif

#ifndef SET_INTERRUPT_MASK_NAME
#define SET_INTERRUPT_MASK_NAME setInterruptMask
#endif

#ifndef EEPROM_WRITE_NAME
#define EEPROM_WRITE_NAME eepromWrite
#endif

#ifndef SAVE_SIZE_NAME
#define SAVE_SIZE_NAME saveSize
#endif

#ifndef SAVE_BUSY_NAME
#define SAVE_BUSY_NAME saveBusy
#endif

#ifndef SAVE_QUEUE_NAME
#define SAVE_QUEUE_NAME saveQueue
#endif

#ifndef EEPROM_BUFFER_NAME
#define EEPROM_BUFFER_NAME eepromBuffer
#endif

#ifndef SAVE_MARKER_NAME
#define SAVE_MARKER_NAME saveMarker
#endif

#ifndef SAVE_DATA_NAME
#define SAVE_DATA_NAME saveData
#endif

#ifndef GAME_CONTEXT_NAME
#define GAME_CONTEXT_NAME gameContext
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 words[0x7D0 / 4];
} SaveData;

typedef struct {
    u8 padding00[0x20C];
    SaveData save;
} GameContext;

extern volatile u32 SAVE_SIZE_NAME;
extern u32 SAVE_BUSY_NAME;
extern u8 SAVE_QUEUE_NAME[];
extern u8 EEPROM_BUFFER_NAME[];
extern u32 SAVE_MARKER_NAME;
extern SaveData SAVE_DATA_NAME;
extern GameContext *GAME_CONTEXT_NAME;

extern u32 DISABLE_INTERRUPTS_NAME(void);
extern u32 SET_INTERRUPT_MASK_NAME(u32 mask);
extern int EEPROM_WRITE_NAME(void *queue, u8 address, u8 *buffer, int length);

void LEAF_NAME(void) {
    u32 interruptMask;
    int delay;
    register volatile u32 *sizeBase __asm__("$2");
    register u32 currentSize __asm__("$3");

    sizeBase = (volatile u32 *)0x80040000;
    __asm__("" : "=r"(sizeBase) : "0"(sizeBase));
    currentSize = sizeBase[0x4608 / 4];
    if (currentSize == 0x800) {
        {
            register u32 *busyAddress __asm__("$3");
            register u32 one __asm__("$2");

            busyAddress = (u32 *)0x80040000;
            one = 1;
            __asm__("" : "=r"(busyAddress), "=r"(one)
                    : "0"(busyAddress), "1"(one));
            busyAddress[0x3724 / 4] = one;
            __asm__ volatile("" : : : "memory");
        }
        interruptMask = DISABLE_INTERRUPTS_NAME();
        SET_INTERRUPT_MASK_NAME(1);
        SET_INTERRUPT_MASK_NAME(0x20401);
        {
            register u32 *source __asm__("$4");
            register u32 *destination __asm__("$3");
            register u32 *end __asm__("$2");
            register u32 first __asm__("$8");
            register u32 second __asm__("$9");
            register u32 third __asm__("$10");
            register u32 fourth __asm__("$11");
            GameContext *context;

            context = GAME_CONTEXT_NAME;
            destination = SAVE_DATA_NAME.words;
            source = context->save.words;
            end = context->save.words + (0x7D0 / 4);
            __asm__("" : "=r"(source), "=r"(destination), "=r"(end)
                    : "0"(source), "1"(destination), "2"(end));
            do {
                first = source[0];
                second = source[1];
                third = source[2];
                fourth = source[3];
                destination[0] = first;
                destination[1] = second;
                destination[2] = third;
                destination[3] = fourth;
                source += 4;
                destination += 4;
            } while (source != end);
        }
        {
            register u32 *markerAddress __asm__("$3");
            register u32 marker __asm__("$2");

            markerAddress = (u32 *)0x80040000;
            marker = 73;
            __asm__("" : "=r"(markerAddress), "=r"(marker)
                    : "0"(markerAddress), "1"(marker));
            markerAddress[0x486C / 4] = marker;
        }

        for (delay = 0; delay <= 99999; delay++) {
        }

        __asm__ volatile(
            "nop\n\t"
            "nop\n\t"
            "nop\n\t"
            "nop\n\t"
            "nop\n\t"
            "nop\n\t"
            "nop\n\t"
            "nop");
        EEPROM_WRITE_NAME(SAVE_QUEUE_NAME, 0, EEPROM_BUFFER_NAME, 0x7F0);
        __asm__ volatile(
            "nop\n\t"
            "nop\n\t"
            "nop\n\t"
            "nop\n\t"
            "nop\n\t"
            "nop\n\t"
            "nop");
        SET_INTERRUPT_MASK_NAME(interruptMask);
        {
            register u32 *busyAddress __asm__("$2");

            busyAddress = (u32 *)0x80040000;
            __asm__("" : "=r"(busyAddress) : "0"(busyAddress));
            busyAddress[0x3724 / 4] = 0;
        }
    }
}
