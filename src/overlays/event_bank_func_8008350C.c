/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8008350C\n.ent func_8008350C\n"
    "func_8008350C:\n"
    "move $19,$4\n"
    "sw $31,40($29)\n"
    "sw $18,32($29)\n"
    "sw $17,28($29)\n"
    "sw $16,24($29)\n"
    ".end func_8008350C\n.set at\n.set reorder\n");
