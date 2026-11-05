typedef struct {
    char data[36];
} Cell;

extern void func_800B3870(void *, void *, unsigned int);

void func_800E5E84(char *obj)
{
    unsigned int i;
    unsigned int j;

    func_800B3870(*(Cell **)(obj + 240), *(Cell **)(obj + 236),
                  *(unsigned int *)(obj + 252) * sizeof(Cell));
    for (i = 0; i < *(unsigned int *)(obj + 220) * *(unsigned int *)(obj + 252);
         i += *(unsigned int *)(obj + 252)) {
        for (j = 0; j < *(unsigned int *)(obj + 252); j++) {
            func_800B3870(&(*(Cell **)(obj + 244))[i + j], &(*(Cell **)(obj + 236))[j],
                          sizeof(Cell));
        }
    }
}
