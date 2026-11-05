/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EAE24\n.ent func_800EAE24\n"
    "func_800EAE24:\n"
    "addiu $29,$29,-48\n"
    "sw $17,28($29)\n"
    "move $17,$4\n"
    "sw $31,40($29)\n"
    "sw $19,36($29)\n"
    "sw $18,32($29)\n"
    "sw $16,24($29)\n"
    "lw $18,4($17)\n"
    "li $2,0x8000\n"
    "addu $2,$18,$2\n"
    "lbu $3,3229($2)\n"
    "sltiu $2,$3,6\n"
    ".end func_800EAE24\n.set at\n.set reorder\n");
