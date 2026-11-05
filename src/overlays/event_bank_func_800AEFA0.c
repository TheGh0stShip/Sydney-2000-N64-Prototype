/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AEFA0\n.ent func_800AEFA0\n"
    "func_800AEFA0:\n"
    "sw $0,348($2)\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800AEFA0\n.set at\n.set reorder\n");
