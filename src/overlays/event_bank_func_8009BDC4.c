/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009BDC4\n.ent func_8009BDC4\n"
    "func_8009BDC4:\n"
    "move $5,$16\n"
    "li $6,1\n"
    "move $7,$19\n"
    "jal func_800A9B78\n"
    "sw $2,16($29)\n"
    "lw $31,40($29)\n"
    "lw $19,36($29)\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".end func_8009BDC4\n.set at\n.set reorder\n");
