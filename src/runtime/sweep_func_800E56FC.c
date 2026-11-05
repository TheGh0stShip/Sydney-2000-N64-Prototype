/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E56FC\n.ent func_800E56FC\n"
    "func_800E56FC:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_800E5260\n"
    "nop\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800E56FC\n.set at\n.set reorder\n");
