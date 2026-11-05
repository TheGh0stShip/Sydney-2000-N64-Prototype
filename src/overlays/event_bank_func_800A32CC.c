/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A32CC\n.ent func_800A32CC\n"
    "func_800A32CC:\n"
    "sw $19,36($29)\n"
    "sw $17,28($29)\n"
    "sw $16,24($29)\n"
    "lw $2,4($20)\n"
    "lw $3,16($18)\n"
    "subu $2,$2,$3\n"
    "lw $3,0($20)\n"
    "sra $19,$2,0x8\n"
    ".end func_800A32CC\n.set at\n.set reorder\n");
