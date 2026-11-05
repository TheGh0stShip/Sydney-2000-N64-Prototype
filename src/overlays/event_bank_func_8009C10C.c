/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009C10C\n.ent func_8009C10C\n"
    "func_8009C10C:\n"
    "addiu $29,$29,-40\n"
    "sw $18,24($29)\n"
    "move $18,$4\n"
    "sw $19,28($29)\n"
    "move $19,$5\n"
    "sw $16,16($29)\n"
    "addiu $16,$18,5048\n"
    "move $4,$16\n"
    "li $5,2\n"
    "sw $31,32($29)\n"
    "jal func_800ADDA4\n"
    "sw $17,20($29)\n"
    "addiu $2,$18,4412\n"
    ".end func_8009C10C\n.set at\n.set reorder\n");
