/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80081238\n.ent func_80081238\n"
    "func_80081238:\n"
    "lw $31,40($29)\n"
    "lw $19,36($29)\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".end func_80081238\n.set at\n.set reorder\n");
