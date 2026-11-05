/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800830C4\n.ent func_800830C4\n"
    "func_800830C4:\n"
    "addu $2,$18,$2\n"
    "lw $5,16672($2)\n"
    "jal func_80076680\n"
    "li $6,1\n"
    "lw $2,4($20)\n"
    "sw $2,16($18)\n"
    "lw $31,44($29)\n"
    "lw $20,40($29)\n"
    "lw $19,36($29)\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".end func_800830C4\n.set at\n.set reorder\n");
