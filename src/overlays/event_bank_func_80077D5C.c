/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077D5C\n.ent func_80077D5C\n"
    "func_80077D5C:\n"
    "addiu $29,$29,-32\n"
    "sw $18,24($29)\n"
    "move $18,$4\n"
    "sw $17,20($29)\n"
    "li $17,-1\n"
    "sw $16,16($29)\n"
    "sw $31,28($29)\n"
    "lw $3,2560($2)\n"
    "li $2,5\n"
    ".end func_80077D5C\n.set at\n.set reorder\n");
