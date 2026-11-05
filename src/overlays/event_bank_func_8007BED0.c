/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BED0\n.ent func_8007BED0\n"
    "func_8007BED0:\n"
    "beq $3,$2,L_8007BEE0\n"
    "li $4,19200\n"
    "jal func_8009B9EC\n"
    "li $5,24575\n"
    "L_8007BEE0:\n"
    "lw $31,40($29)\n"
    "lw $19,36($29)\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".end func_8007BED0\n.set at\n.set reorder\n");
