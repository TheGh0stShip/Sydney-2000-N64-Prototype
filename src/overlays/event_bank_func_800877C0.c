/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800877C0\n.ent func_800877C0\n"
    "func_800877C0:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_8000F42C\n"
    "nop\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800877C0\n.set at\n.set reorder\n");
