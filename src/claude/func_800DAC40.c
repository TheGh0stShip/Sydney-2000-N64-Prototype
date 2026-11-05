/* Runtime-stage C reconstruction: seed the save block with defaults on first use, then refresh dependent state. */
typedef unsigned short u16;

typedef struct SaveBlock {
    int magic;
    char unused4[0x1F0];
    signed char slots[8];
    char unused1FC[0x7FC];
    char settings[0x31C];
    char unusedD14[0x38];
    char records[0x544];
} SaveBlock;

extern SaveBlock *saveBlock;
extern char defaultSettings[];
extern char defaultRecords[];
extern void func_800B3870(void *dst, void *src, int size);
extern void func_800D9990(void);
extern void func_800D9A18(void);
extern void func_80007B18(int a, int b, int c);
extern void func_800DAB98(void);

void func_800DAC40(void) {
    if (saveBlock->magic != 0x12345678) {
        u16 i;

        func_800B3870(saveBlock->records, defaultRecords, 0x544);
        func_800B3870(saveBlock->settings, defaultSettings, 0x31C);
        saveBlock->magic = 0x12345678;
        func_800D9990();
        for (i = 0; i < 8; i++) {
            saveBlock->slots[i] = -1;
        }
        func_800D9A18();
        func_80007B18(0, 0, 0);
    }
    func_800DAB98();
}
