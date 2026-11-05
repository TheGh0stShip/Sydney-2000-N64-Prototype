extern char *D_800FC270;
extern char D_800F3BC0[];
extern int D_80075754[];
extern void func_800C0110(void *queue, int id, int a2, int a3);

typedef struct SlotEntry {
    char pad[8];
    signed char index;
    char pad2[3];
} SlotEntry;

void func_800A01C0(unsigned char *obj)
{
    unsigned char mode;
    SlotEntry *entry;
    int value;
    int k;

    mode = obj[24041];
    if (mode != 4 && mode != 2 && mode != 3) {
        func_800C0110(D_800F3BC0, 184, 3840, 0);
    }

    entry = (SlotEntry *)(D_800FC270 + 2576) + obj[24038];
    if (entry->index == 0) {
        *(int *)(obj + 24136) = *(int *)(obj + 24128);
        *(int *)(obj + 24140) = *(int *)(obj + 24132);
    }

    if (*(int *)(obj + 24036) & 0x00FFFF00) {
        k = entry->index;
        value = D_80075754[k];
        if (k == D_800FC270[2572] - 1 && obj[24037] == 1) {
            value = 100;
        }
        mode = obj[24041];
        if (mode != 4 && mode != 2 && mode != 3) {
            func_800C0110(D_800F3BC0, value, 7680, 0);
        }
    }
}
