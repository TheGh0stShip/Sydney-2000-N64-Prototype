/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D5744\n.ent func_800D5744\n"
    "func_800D5744:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_800D427C\n"
    "nop\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800D5744\n.set at\n.set reorder\n");
