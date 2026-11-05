/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EC89C\n.ent func_800EC89C\n"
    "func_800EC89C:\n"
    "move $5,$18\n"
    "move $6,$17\n"
    "jal func_800B9964\n"
    "move $7,$16\n"
    "lw $31,112($29)\n"
    "lw $19,108($29)\n"
    "lw $18,104($29)\n"
    "lw $17,100($29)\n"
    "lw $16,96($29)\n"
    "jr $31\n"
    "addiu $29,$29,120\n"
    ".end func_800EC89C\n.set at\n.set reorder\n");
