/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009C0D8\n.ent func_8009C0D8\n"
    "func_8009C0D8:\n"
    "jal func_800AE4D8\n"
    "li $5,2\n"
    "move $4,$17\n"
    "jal func_800AC3A4\n"
    "move $5,$20\n"
    "lw $31,36($29)\n"
    "lw $20,32($29)\n"
    "lw $19,28($29)\n"
    "lw $18,24($29)\n"
    "lw $17,20($29)\n"
    ".end func_8009C0D8\n.set at\n.set reorder\n");
