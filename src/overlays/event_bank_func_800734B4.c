/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800734B4\n.ent func_800734B4\n"
    "func_800734B4:\n"
    "addiu $29,$29,-40\n"
    "sw $17,20($29)\n"
    "move $17,$4\n"
    "sw $19,28($29)\n"
    ".end func_800734B4\n.set at\n.set reorder\n");
