/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A731C\n.ent func_800A731C\n"
    "func_800A731C:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_800ADC1C\n"
    "addiu $4,$4,208\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800A731C\n.set at\n.set reorder\n");
