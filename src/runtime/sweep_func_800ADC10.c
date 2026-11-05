/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800ADC10\n.ent func_800ADC10\n"
    "func_800ADC10:\n"
    "lui $2,0x2\n"
    "jr $31\n"
    "sw $2,192($4)\n"
    ".end func_800ADC10\n.set at\n.set reorder\n");
