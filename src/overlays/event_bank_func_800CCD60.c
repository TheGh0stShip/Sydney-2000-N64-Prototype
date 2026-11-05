/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CCD60\n.ent func_800CCD60\n"
    "func_800CCD60:\n"
    "move $7,$19\n"
    "lw $5,10052($2)\n"
    "move $2,$6\n"
    "sw $0,16($29)\n"
    "jal func_800AB2A4\n"
    "sw $2,20($29)\n"
    "lw $31,96($29)\n"
    "lw $19,92($29)\n"
    "lw $18,88($29)\n"
    "lw $17,84($29)\n"
    "lw $16,80($29)\n"
    "ldc1 $f20,104($29)\n"
    "jr $31\n"
    "addiu $29,$29,112\n"
    ".end func_800CCD60\n.set at\n.set reorder\n");
