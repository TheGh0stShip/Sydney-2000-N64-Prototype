/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007E434\n.ent func_8007E434\n"
    "func_8007E434:\n"
    "lw $31,44($29)\n"
    "lw $22,40($29)\n"
    "lw $21,36($29)\n"
    "lw $20,32($29)\n"
    "lw $19,28($29)\n"
    "lw $18,24($29)\n"
    "lw $17,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".end func_8007E434\n.set at\n.set reorder\n");
