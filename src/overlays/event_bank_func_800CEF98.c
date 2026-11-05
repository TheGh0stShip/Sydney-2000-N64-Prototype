/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CEF98\n.ent func_800CEF98\n"
    "func_800CEF98:\n"
    "li $3,44\n"
    "sw $3,0($2)\n"
    "sw $0,17360($2)\n"
    "sw $0,3860($2)\n"
    "swc1 $f0,17348($2)\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800CEF98\n.set at\n.set reorder\n");
