/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083644\n.ent func_80083644\n"
    "func_80083644:\n"
    "jal func_800A9BE8\n"
    "addiu $4,$19,1116\n"
    "lw $3,21600($19)\n"
    "li $2,2\n"
    "sb $2,1551($19)\n"
    "jal func_800177EC\n"
    "sw $3,21540($19)\n"
    "lw $31,40($29)\n"
    "lw $19,36($29)\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".end func_80083644\n.set at\n.set reorder\n");
