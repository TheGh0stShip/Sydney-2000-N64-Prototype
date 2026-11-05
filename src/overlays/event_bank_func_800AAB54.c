/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AAB54\n.ent func_800AAB54\n"
    "func_800AAB54:\n"
    "lw $31,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_800AAB54\n.set at\n.set reorder\n");
