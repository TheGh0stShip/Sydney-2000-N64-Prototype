/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A63F0\n.ent func_800A63F0\n"
    "func_800A63F0:\n"
    "li $5,185\n"
    "li $6,7680\n"
    "jal func_800C0110\n"
    "li $7,23040\n"
    "lw $31,44($29)\n"
    "lw $20,40($29)\n"
    "lw $19,36($29)\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".end func_800A63F0\n.set at\n.set reorder\n");
