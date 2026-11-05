/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072064\n.ent func_80072064\n"
    "func_80072064:\n"
    "sw $19,28($29)\n"
    "move $19,$4\n"
    "sw $31,32($29)\n"
    "sw $18,24($29)\n"
    "sw $17,20($29)\n"
    ".end func_80072064\n.set at\n.set reorder\n");
