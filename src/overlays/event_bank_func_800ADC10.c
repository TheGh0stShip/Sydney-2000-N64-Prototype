/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800ADC10\n.ent func_800ADC10\n"
    "func_800ADC10:\n"
    "andi $16,$19,0xff\n"
    "sltu $2,$16,$2\n"
    ".word 0x10400021\n"
    ".end func_800ADC10\n.set at\n.set reorder\n");
