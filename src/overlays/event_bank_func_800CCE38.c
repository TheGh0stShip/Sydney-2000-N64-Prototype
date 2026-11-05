/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CCE38\n.ent func_800CCE38\n"
    "func_800CCE38:\n"
    "addiu $29,$29,-40\n"
    "sw $18,24($29)\n"
    "move $18,$4\n"
    "sw $31,32($29)\n"
    "sw $19,28($29)\n"
    ".end func_800CCE38\n.set at\n.set reorder\n");
