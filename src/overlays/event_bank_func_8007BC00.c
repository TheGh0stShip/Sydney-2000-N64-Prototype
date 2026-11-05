/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BC00\n.ent func_8007BC00\n"
    "func_8007BC00:\n"
    "addu $18,$19,$2\n"
    "sw $31,40($29)\n"
    "sw $17,28($29)\n"
    "sw $16,24($29)\n"
    "lw $2,3232($18)\n"
    "addiu $2,$2,-256\n"
    ".word 0x1C4000A9\n"
    "sw $2,3232($18)\n"
    "lui $2,0x8010\n"
    "lw $2,-15760($2)\n"
    "lw $2,2560($2)\n"
    "li $16,4\n"
    ".word 0x14500060\n"
    ".end func_8007BC00\n.set at\n.set reorder\n");
