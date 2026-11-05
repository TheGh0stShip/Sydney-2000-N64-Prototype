/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D2760\n.ent func_800D2760\n"
    "func_800D2760:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_800B35F0\n"
    "addiu $4,$4,424\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800D2760\n.set at\n.set reorder\n");
