/* Bank accessors preserved by the upstream libmus source. */
extern void *D_803AD9A8;
extern int D_8012686C;
extern int D_803AD9B0;

int MusFxBankNumberOfEffects(int *bank)
{
    return bank[1];
}

void osViExtendVStart(void *bank)
{
    D_803AD9A8 = bank;
}

void func_800FBDBC(int value)
{
    D_8012686C = value;
}

void func_800FBEA4(int value)
{
    D_803AD9B0 = value;
}
