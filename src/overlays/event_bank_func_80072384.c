/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072384\n.ent func_80072384\n"
    "func_80072384:\n"
    "addiu $29,$29,-120\n"
    "sw $19,76($29)\n"
    "move $19,$4\n"
    "sw $31,100($29)\n"
    "sw $30,96($29)\n"
    "sw $23,92($29)\n"
    "sw $22,88($29)\n"
    "sw $21,84($29)\n"
    "sw $20,80($29)\n"
    ".end func_80072384\n.set at\n.set reorder\n");
