/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D33F8\n.ent func_800D33F8\n"
    "func_800D33F8:\n"
    "jal func_800ADE84\n"
    "li $5,2\n"
    "move $4,$18\n"
    "jal func_80081DC8\n"
    "move $5,$19\n"
    "lw $31,32($29)\n"
    "lw $19,28($29)\n"
    "lw $18,24($29)\n"
    "lw $17,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_800D33F8\n.set at\n.set reorder\n");
