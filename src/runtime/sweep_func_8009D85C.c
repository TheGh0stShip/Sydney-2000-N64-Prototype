/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009D85C\n.ent func_8009D85C\n"
    "func_8009D85C:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_800ADC1C\n"
    "addiu $4,$4,24688\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009D85C\n.set at\n.set reorder\n");
