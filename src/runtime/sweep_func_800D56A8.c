/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D56A8\n.ent func_800D56A8\n"
    "func_800D56A8:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lw $4,2780($4)\n"
    "beqz $4,L_800D56C4\n"
    "nop\n"
    "jal func_800DC6A4\n"
    "nop\n"
    "L_800D56C4:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800D56A8\n.set at\n.set reorder\n");
